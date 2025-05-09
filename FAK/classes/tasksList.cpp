#include "tasksList.h"
#include "./ui_tasksList.h"
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
#include <QFont>
#include <QDateTimeEdit>
#include <QContextMenuEvent>
#include <QMenu>
#include <QTimer>
#include <QStandardPaths>
#include <QDir>

tasksList::tasksList(QWidget *parent)
    : QWidget(parent), ui(new Ui::tasksList)
{
    ui->setupUi(this);
    initDatabase();

    QWidget* scrollContents = new QWidget();
    QVBoxLayout* taskListLayout = new QVBoxLayout(scrollContents);
    taskListLayout->setAlignment(Qt::AlignTop);
    ui->scrollArea->setWidget(scrollContents);
    ui->scrollArea->setWidgetResizable(true);
    ui->buttonsLayout = taskListLayout;

    // Проверка просроченных задач каждую минуту
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &tasksList::checkForOverdueTasks);
    timer->start(60000); // 60 секунд

    loadTasksFromDefaultDatabase();
    connect(ui->textInput, &QLineEdit::returnPressed, this, &tasksList::createButtonFromInput);
}

tasksList::tasksList(const QString &dbName, QWidget *parent)
    : QWidget(parent), ui(new Ui::tasksList)
{
    ui->setupUi(this);

    // Инициализация базы данных с указанным именем
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Database connection error:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "text TEXT NOT NULL UNIQUE, "
                 "completed BOOLEAN NOT NULL, "
                 "deadline DATETIME)");
    }

    QWidget* scrollContents = new QWidget();
    QVBoxLayout* taskListLayout = new QVBoxLayout(scrollContents);
    taskListLayout->setAlignment(Qt::AlignTop);
    ui->scrollArea->setWidget(scrollContents);
    ui->scrollArea->setWidgetResizable(true);
    ui->buttonsLayout = taskListLayout;

    // Проверка просроченных задач каждую минуту
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &tasksList::checkForOverdueTasks);
    timer->start(60000); // 60 секунд

    loadTasksFromDatabase(dbName);
    connect(ui->textInput, &QLineEdit::returnPressed, this, &tasksList::createButtonFromInput);
}

tasksList::~tasksList()
{
    db.close();
    delete ui;
}

void tasksList::initDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Получаем путь к постоянной директории данных
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dbPath); // Создаём директорию, если её нет

    // Устанавливаем полный путь к файлу БД
    db.setDatabaseName(dbPath + "/tasks.db");

    if (!db.open()) {
        qDebug() << "Database connection error:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "text TEXT NOT NULL UNIQUE, "
                 "completed BOOLEAN NOT NULL, "
                 "deadline DATETIME)");
    }
}

void tasksList::loadTasksFromDatabase(const QString &dbName) {
    // Clear existing tasks
    QLayout *layout = ui->buttonsLayout;
    if (layout) {
        while (QLayoutItem* item = layout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
    }

    // If no specific database name is provided, use the default one
    QString targetDbName = dbName.isEmpty() ? db.databaseName() : dbName;

    // Create a temporary connection to the target database
    QSqlDatabase tempDb = QSqlDatabase::addDatabase("QSQLITE", "temp_" + targetDbName);
    tempDb.setDatabaseName(targetDbName);

    if (!tempDb.open()) {
        qDebug() << "Error opening database:" << tempDb.lastError().text();
        return;
    }

    QSqlQuery query(tempDb);
    query.exec("SELECT text, completed, deadline FROM tasks ORDER BY completed");

    while (query.next()) {
        QString text = query.value(0).toString();
        bool completed = query.value(1).toBool();
        QDateTime deadline = query.value(2).toDateTime();

        if (deadline.isValid()) {
            text += " (До: " + deadline.toString("dd.MM.yyyy HH:mm") + ")";
        }

        QWidget* taskWidget = new QWidget();
        taskWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QHBoxLayout* taskLayout = new QHBoxLayout(taskWidget);
        taskLayout->setContentsMargins(0, 2, 0, 2);

        QCheckBox* checkbox = new QCheckBox();
        checkbox->setChecked(completed);
        checkbox->setFixedSize(20, 20);

        QPushButton* taskButton = new QPushButton(text);
        updateTaskStyle(taskButton, completed);

        QToolButton* optionsButton = new QToolButton();
        optionsButton->setText("⋮");
        optionsButton->setStyleSheet(
            "QToolButton {"
            "font-size: 18px; font-weight: bold; color: #F4E3B2;"
            "background-color: transparent; border: none;"
            "min-width: 20px; min-height: 20px;"
            "}"
            "QToolButton:hover { color: #9d7aaf; }"
        );

        QToolButton* deleteButton = new QToolButton();
        deleteButton->setText("×");
        deleteButton->setStyleSheet(
            "QToolButton {"
            "font-size: 18px; font-weight: bold; color: #F4E3B2;"
            "background-color: transparent; border: none;"
            "min-width: 20px; min-height: 20px;"
            "}"
            "QToolButton:hover { color: #74070E; }"
        );

        checkbox->setProperty("taskButton", QVariant::fromValue(taskButton));
        checkbox->setProperty("taskWidget", QVariant::fromValue(taskWidget));
        deleteButton->setProperty("taskWidget", QVariant::fromValue(taskWidget));
        optionsButton->setProperty("taskWidget", QVariant::fromValue(taskWidget));

        taskLayout->addWidget(checkbox);
        taskLayout->addWidget(taskButton, 1);
        taskLayout->addWidget(optionsButton);
        taskLayout->addWidget(deleteButton);

        if (completed) {
            ui->buttonsLayout->addWidget(taskWidget);
        } else {
            ui->buttonsLayout->insertWidget(0, taskWidget);
        }

        connect(checkbox, &QCheckBox::toggled, this, &tasksList::handleCheckboxToggle);
        connect(taskButton, &QPushButton::clicked, this, &tasksList::handleTaskButtonClick);
        connect(deleteButton, &QToolButton::clicked, this, &tasksList::handleDeleteButtonClick);
        connect(optionsButton, &QToolButton::clicked, this, &tasksList::showDeadlineOptions);
    }

    tempDb.close();
    QSqlDatabase::removeDatabase("temp_" + targetDbName);
    checkForOverdueTasks();
}

void tasksList::showDeadlineOptions()
{
    QToolButton* optionsButton = qobject_cast<QToolButton*>(sender());
    if (!optionsButton) return;

    QWidget* taskWidget = optionsButton->parentWidget();
    if (taskWidget) {
        emit showDeadlinePanelRequested(taskWidget);
    }
}

void tasksList::updateTaskStyle(QPushButton* button, bool completed)
{
    QString style = QString("QPushButton {"
            "text-align: left; padding-left: 10px;"
            "background-color: %1; color: %2;"
            "border: none;"
            "text-decoration: %3;"
            "}"
            "QPushButton:hover { background-color: %4; }")
        .arg(completed ? "transparent" : "#45462A")  // Drab dark brown для невыполненных
        .arg(completed ? "#aaaaaa" : "#F4E3B2")      // Vanilla для текста невыполненных
        .arg(completed ? "line-through" : "none")
        .arg(completed ? "transparent" : "#555555"); // Цвет ховера для невыполненных

    // Проверка на просроченность
    QDateTime deadline = extractDeadlineFromText(button->text());
    if (deadline.isValid() && deadline < QDateTime::currentDateTime()) {
        style += " color: #74070E;"; // Blood red для просроченных
    }

    button->setStyleSheet(style);

    QFont font = button->font();
    font.setStrikeOut(completed);
    button->setFont(font);
}

void tasksList::moveTaskToBottom(QWidget* taskWidget)
{
    ui->buttonsLayout->removeWidget(taskWidget);
    ui->buttonsLayout->addWidget(taskWidget);
}

void tasksList::createButtonFromInput()
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

    // Добавляем кнопку опций (три точки)
    QToolButton* optionsButton = new QToolButton();
    optionsButton->setText("⋮");
    optionsButton->setStyleSheet(
        "QToolButton {"
        "font-size: 18px; font-weight: bold; color: #f7f3e3;"
        "background-color: transparent; border: none;"
        "min-width: 20px; min-height: 20px;"
        "}"
        "QToolButton:hover { color: #9d7aaf; }"
    );

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
    optionsButton->setProperty("taskWidget", QVariant::fromValue(taskWidget));

    taskLayout->addWidget(checkbox);
    taskLayout->addWidget(taskButton, 1);
    taskLayout->addWidget(optionsButton);  // Добавляем кнопку опций
    taskLayout->addWidget(deleteButton);

    ui->buttonsLayout->insertWidget(0, taskWidget);
    saveTaskToDatabase(text);

    connect(checkbox, &QCheckBox::toggled, this, &tasksList::handleCheckboxToggle);
    connect(taskButton, &QPushButton::clicked, this, &tasksList::handleTaskButtonClick);
    connect(deleteButton, &QToolButton::clicked, this, &tasksList::handleDeleteButtonClick);
    connect(optionsButton, &QToolButton::clicked, this, &tasksList::showDeadlineOptions);  // Подключаем обработчик

    ui->textInput->clear();
}

void tasksList::handleCheckboxToggle(bool checked)
{
    QCheckBox* checkbox = qobject_cast<QCheckBox*>(sender());
    if (!checkbox) return;

    QPushButton* taskButton = checkbox->property("taskButton").value<QPushButton*>();
    QWidget* taskWidget = checkbox->property("taskWidget").value<QWidget*>();
    if (!taskButton || !taskWidget) return;

    updateTaskStyle(taskButton, checked);
    updateTaskStatusInDatabase(extractBaseTaskText(taskButton->text()), checked);

    if (checked) {
        moveTaskToBottom(taskWidget);
    } else {
        ui->buttonsLayout->removeWidget(taskWidget);
        ui->buttonsLayout->insertWidget(0, taskWidget);
    }
}

void tasksList::handleTaskButtonClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QMessageBox::information(this, "Задача", "Текст задачи: " + button->text());
    }
}

void tasksList::handleDeleteButtonClick()
{
    QToolButton* deleteButton = qobject_cast<QToolButton*>(sender());
    if (!deleteButton) return;

    QWidget* taskWidget = deleteButton->property("taskWidget").value<QWidget*>();
    if (!taskWidget) return;

    QPushButton* taskButton = taskWidget->findChild<QPushButton*>();
    if (taskButton) {
        deleteTaskFromDatabase(extractBaseTaskText(taskButton->text()));
    }

    taskWidget->hide();
    ui->buttonsLayout->removeWidget(taskWidget);
    taskWidget->deleteLater();
}

void tasksList::saveTaskToDatabase(const QString &taskText, bool completed, const QDateTime &deadline)
{
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (text, completed, deadline) VALUES (:text, :completed, :deadline)");
    query.bindValue(":text", taskText);
    query.bindValue(":completed", completed);
    query.bindValue(":deadline", deadline.isValid() ? deadline.toString(Qt::ISODate) : QVariant());
    if (!query.exec()) {
        qDebug() << "Error saving task:" << query.lastError().text();
    }
}

void tasksList::updateTaskStatusInDatabase(const QString &taskText, bool completed)
{
    QSqlQuery query;
    query.prepare("UPDATE tasks SET completed = :completed WHERE text = :text");
    query.bindValue(":completed", completed);
    query.bindValue(":text", taskText);
    if (!query.exec()) {
        qDebug() << "Error updating task:" << query.lastError().text();
    }
}

void tasksList::updateTaskDeadlineInDatabase(const QString &taskText, const QDateTime &deadline)
{
    QSqlQuery query;
    query.prepare("UPDATE tasks SET deadline = :deadline WHERE text = :text");
    query.bindValue(":deadline", deadline.isValid() ? deadline.toString(Qt::ISODate) : QVariant());
    query.bindValue(":text", taskText);
    if (!query.exec()) {
        qDebug() << "Error updating deadline:" << query.lastError().text();
    }
}

void tasksList::deleteTaskFromDatabase(const QString &taskText)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tasks WHERE text = :text");
    query.bindValue(":text", taskText);
    if (!query.exec()) {
        qDebug() << "Error deleting task:" << query.lastError().text();
    }
}

void tasksList::contextMenuEvent(QContextMenuEvent *event)
{
    contextMenuButton = getButtonAtPos(event->pos());
    if (!contextMenuButton) return;

    QMenu menu(this);
    QAction *propertiesAction = menu.addAction("Свойства задачи");
    QAction *deadlineAction = menu.addAction("Установить дедлайн");

    connect(propertiesAction, &QAction::triggered, this, &tasksList::showTaskProperties);
    connect(deadlineAction, &QAction::triggered, this, &tasksList::setTaskDeadline);

    menu.exec(event->globalPos());
}

QPushButton* tasksList::getButtonAtPos(const QPoint &pos)
{
    QWidget *child = childAt(pos);
    while (child) {
        if (auto button = qobject_cast<QPushButton*>(child)) {
            return button;
        }
        child = child->parentWidget();
    }
    return nullptr;
}

void tasksList::showTaskProperties()
{
    if (!contextMenuButton) return;

    QString message = "Задача: " + contextMenuButton->text();
    QMessageBox::information(this, "Свойства задачи", message);
}

void tasksList::setTaskDeadline()
{
    if (!contextMenuButton) return;

    QString currentText = contextMenuButton->text();
    QDateTime currentDeadline = extractDeadlineFromText(currentText);

    QDialog dialog(this);
    dialog.setWindowTitle("Установить дедлайн");

    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(currentDeadline.isValid() ? currentDeadline : QDateTime::currentDateTime());
    dateTimeEdit->setDisplayFormat("dd.MM.yyyy HH:mm");
    dateTimeEdit->setCalendarPopup(true);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(dateTimeEdit);

    QPushButton *okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    QPushButton *cancelButton = new QPushButton("Отмена");
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    if (dialog.exec() == QDialog::Accepted) {
        QDateTime deadline = dateTimeEdit->dateTime();
        QString baseText = extractBaseTaskText(currentText);
        QString newText = baseText + " (До: " + deadline.toString("dd.MM.yyyy HH:mm") + ")";

        contextMenuButton->setText(newText);
        updateTaskDeadlineInDatabase(baseText, deadline);
        updateTaskStyle(contextMenuButton, contextMenuButton->font().strikeOut());
    }

    contextMenuButton = nullptr;
}

void tasksList::checkForOverdueTasks()
{
    QDateTime now = QDateTime::currentDateTime();
    QLayout *layout = ui->buttonsLayout;

    for (int i = 0; i < layout->count(); ++i) {
        QWidget *widget = layout->itemAt(i)->widget();
        if (!widget) continue;

        QPushButton *button = widget->findChild<QPushButton*>();
        if (button) {
            QDateTime deadline = extractDeadlineFromText(button->text());
            if (deadline.isValid() && deadline < now) {
                updateTaskStyle(button, button->font().strikeOut());
            }
        }
    }
}

QString tasksList::extractBaseTaskText(const QString &fullText) {
    if (fullText.contains("(До:")) {
        return fullText.left(fullText.indexOf("(До:")).trimmed();
    }
    return fullText;
}

QDateTime tasksList::extractDeadlineFromText(const QString &fullText) {
    if (fullText.contains("(До:")) {
        int start = fullText.indexOf("(До:") + 5;
        int end = fullText.indexOf(")", start);
        QString dateStr = fullText.mid(start, end - start).trimmed();
        return QDateTime::fromString(dateStr, "dd.MM.yyyy HH:mm");
    }
    return QDateTime();
}

void tasksList::loadTasksFromDefaultDatabase()
{
    loadTasksFromDatabase(db.databaseName());
}
