#include "myDayTasks.h"
#include "./ui_myDayTasks.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QSqlError>
#include <QFont>  // Добавлен для работы с шрифтами

MyDayTasks::MyDayTasks(QWidget *parent)
    : QWidget(parent), ui(new Ui::MyDayTasks)
{
    ui->setupUi(this);
    initDatabase();

    QWidget* scrollContents = new QWidget();
    QVBoxLayout* taskListLayout = new QVBoxLayout(scrollContents);
    taskListLayout->setAlignment(Qt::AlignTop);
    ui->scrollArea->setWidget(scrollContents);
    ui->scrollArea->setWidgetResizable(true);
    ui->buttonsLayout = taskListLayout;

    loadTasksFromDatabase();
    connect(ui->textInput, &QLineEdit::returnPressed, this, &MyDayTasks::createButtonFromInput);
}

MyDayTasks::~MyDayTasks()
{
    db.close();
    delete ui;
}

void MyDayTasks::initDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");
    if (!db.open()) {
        qDebug() << "Database connection error:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "text TEXT NOT NULL UNIQUE, "
                 "completed BOOLEAN NOT NULL)");
    }
}

void MyDayTasks::loadTasksFromDatabase()
{
    QSqlQuery query("SELECT text, completed FROM tasks ORDER BY completed");
    while (query.next()) {
        QString text = query.value(0).toString();
        bool completed = query.value(1).toBool();

        QWidget* taskWidget = new QWidget();
        taskWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QHBoxLayout* taskLayout = new QHBoxLayout(taskWidget);
        taskLayout->setContentsMargins(0, 2, 0, 2);

        QCheckBox* checkbox = new QCheckBox();
        checkbox->setChecked(completed);
        checkbox->setFixedSize(20, 20);

        QPushButton* taskButton = new QPushButton(text);
        updateTaskStyle(taskButton, completed);

        QToolButton* deleteButton = new QToolButton();
        deleteButton->setText("×");
        deleteButton->setStyleSheet(
            "QToolButton {"
            "font-size: 18px; font-weight: bold; color: #f7f3e3;"
            "background-color: transparent; border: none;"
            "min-width: 20px; min-height: 20px;"
            "}"
            "QToolButton:hover { color: #ff6666; }"
        );

        checkbox->setProperty("taskButton", QVariant::fromValue(taskButton));
        checkbox->setProperty("taskWidget", QVariant::fromValue(taskWidget));
        deleteButton->setProperty("taskWidget", QVariant::fromValue(taskWidget));

        taskLayout->addWidget(checkbox);
        taskLayout->addWidget(taskButton, 1);
        taskLayout->addWidget(deleteButton);

        if (completed) {
            ui->buttonsLayout->addWidget(taskWidget);
        } else {
            ui->buttonsLayout->insertWidget(0, taskWidget);
        }

        connect(checkbox, &QCheckBox::toggled, this, &MyDayTasks::handleCheckboxToggle);
        connect(taskButton, &QPushButton::clicked, this, &MyDayTasks::handleTaskButtonClick);
        connect(deleteButton, &QToolButton::clicked, this, &MyDayTasks::handleDeleteButtonClick);
    }
}

void MyDayTasks::updateTaskStyle(QPushButton* button, bool completed)
{
    button->setStyleSheet(
        QString("QPushButton {"
                "text-align: left; padding-left: 10px;"
                "background-color: %1; color: %2;"
                "border: none;"
                "}"
                "QPushButton:hover { background-color: #9d7aaf; }")
        .arg(completed ? "transparent" : "#8d6a9f")
        .arg(completed ? "#aaaaaa" : "#f7f3e3")
    );

    QFont font = button->font();
    font.setStrikeOut(completed);
    button->setFont(font);
}

void MyDayTasks::moveTaskToBottom(QWidget* taskWidget)
{
    ui->buttonsLayout->removeWidget(taskWidget);
    ui->buttonsLayout->addWidget(taskWidget);
}

void MyDayTasks::createButtonFromInput()
{
    QString text = ui->textInput->text().trimmed();
    if (text.isEmpty()) return;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM tasks WHERE text = :text");
    checkQuery.bindValue(":text", text);
    if (!checkQuery.exec() || (checkQuery.next() && checkQuery.value(0).toInt() > 0)) {
        QMessageBox::warning(this, "Ошибка", "Такая задача уже существует!");
        ui->textInput->clear();
        return;
    }

    QWidget* taskWidget = new QWidget();
    taskWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout* taskLayout = new QHBoxLayout(taskWidget);
    taskLayout->setContentsMargins(0, 2, 0, 2);

    QCheckBox* checkbox = new QCheckBox();
    checkbox->setFixedSize(20, 20);

    QPushButton* taskButton = new QPushButton(text);
    updateTaskStyle(taskButton, false);

    QToolButton* deleteButton = new QToolButton();
    deleteButton->setText("×");
    deleteButton->setStyleSheet(
        "QToolButton {"
        "font-size: 18px; font-weight: bold; color: #f7f3e3;"
        "background-color: transparent; border: none;"
        "min-width: 20px; min-height: 20px;"
        "}"
        "QToolButton:hover { color: #ff6666; }"
    );

    checkbox->setProperty("taskButton", QVariant::fromValue(taskButton));
    checkbox->setProperty("taskWidget", QVariant::fromValue(taskWidget));
    deleteButton->setProperty("taskWidget", QVariant::fromValue(taskWidget));

    taskLayout->addWidget(checkbox);
    taskLayout->addWidget(taskButton, 1);
    taskLayout->addWidget(deleteButton);

    ui->buttonsLayout->insertWidget(0, taskWidget);
    saveTaskToDatabase(text);

    connect(checkbox, &QCheckBox::toggled, this, &MyDayTasks::handleCheckboxToggle);
    connect(taskButton, &QPushButton::clicked, this, &MyDayTasks::handleTaskButtonClick);
    connect(deleteButton, &QToolButton::clicked, this, &MyDayTasks::handleDeleteButtonClick);

    ui->textInput->clear();
}

void MyDayTasks::handleCheckboxToggle(bool checked)
{
    QCheckBox* checkbox = qobject_cast<QCheckBox*>(sender());
    if (!checkbox) return;

    QPushButton* taskButton = checkbox->property("taskButton").value<QPushButton*>();
    QWidget* taskWidget = checkbox->property("taskWidget").value<QWidget*>();
    if (!taskButton || !taskWidget) return;

    updateTaskStyle(taskButton, checked);
    updateTaskStatusInDatabase(taskButton->text(), checked);

    if (checked) {
        moveTaskToBottom(taskWidget);
    } else {
        ui->buttonsLayout->removeWidget(taskWidget);
        ui->buttonsLayout->insertWidget(0, taskWidget);
    }
}

void MyDayTasks::handleTaskButtonClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QMessageBox::information(this, "Задача", "Текст задачи: " + button->text());
    }
}

void MyDayTasks::handleDeleteButtonClick()
{
    QToolButton* deleteButton = qobject_cast<QToolButton*>(sender());
    if (!deleteButton) return;

    QWidget* taskWidget = deleteButton->property("taskWidget").value<QWidget*>();
    if (!taskWidget) return;

    QPushButton* taskButton = taskWidget->findChild<QPushButton*>();
    if (taskButton) {
        deleteTaskFromDatabase(taskButton->text());
    }

    taskWidget->hide();
    ui->buttonsLayout->removeWidget(taskWidget);
    taskWidget->deleteLater();
}

void MyDayTasks::saveTaskToDatabase(const QString &taskText, bool completed)
{
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (text, completed) VALUES (:text, :completed)");
    query.bindValue(":text", taskText);
    query.bindValue(":completed", completed);
    if (!query.exec()) {
        qDebug() << "Error saving task:" << query.lastError().text();
    }
}

void MyDayTasks::updateTaskStatusInDatabase(const QString &taskText, bool completed)
{
    QSqlQuery query;
    query.prepare("UPDATE tasks SET completed = :completed WHERE text = :text");
    query.bindValue(":completed", completed);
    query.bindValue(":text", taskText);
    if (!query.exec()) {
        qDebug() << "Error updating task:" << query.lastError().text();
    }
}

void MyDayTasks::deleteTaskFromDatabase(const QString &taskText)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tasks WHERE text = :text");
    query.bindValue(":text", taskText);
    if (!query.exec()) {
        qDebug() << "Error deleting task:" << query.lastError().text();
    }
}
