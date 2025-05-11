#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QtUiTools/QUiLoader>
#include "classes/myDayTasks.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Настройка цветов
    ui->widget_2->setStyleSheet("color: white;");

    // Инициализация менеджера задач
    taskManagerWidget = new FieldGroup("Мои задачи");
    taskManagerWidget->setTextColor("white");
    QVBoxLayout *redWindowLayout = qobject_cast<QVBoxLayout*>(ui->widget_2->layout());
    if (redWindowLayout) {
        redWindowLayout->addWidget(taskManagerWidget);
    }

    connect(taskManagerWidget, &FieldGroup::newGroupRequested,
            this, &MainWindow::createNewTaskGroup);
    connect(taskManagerWidget, &FieldGroup::taskClicked,
            this, &MainWindow::onTaskClicked);

    // Остальная инициализация
    deadlinePanel = new DeadlinePanel();
    ui->horizontalLayout->addWidget(deadlinePanel);
    deadlinePanel->hide();

    connect(deadlinePanel, &DeadlinePanel::deadlineApplied,
            this, &MainWindow::handleDeadlineApplied);
    connect(deadlinePanel, &DeadlinePanel::cancelled,
            this, &MainWindow::hideDeadlinePanel);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    buttonGroup->addButton(ui->myDayButton, 0);
    buttonGroup->addButton(ui->importantButton, 1);
    buttonGroup->addButton(ui->plannedButton, 2);

    stackedWidget = new QStackedWidget();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widget_3->layout());
    if (layout) {
        layout->addWidget(stackedWidget);
    }

    stackedWidget->addWidget(new QWidget());

    connect(ui->myDayButton, &QPushButton::clicked, [this]() { loadTabContent(0); });
    connect(ui->importantButton, &QPushButton::clicked, [this]() { loadTabContent(1); });
    connect(ui->plannedButton, &QPushButton::clicked, [this]() { loadTabContent(2); });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createNewTaskGroup()
{
    groupCounter++;
    FieldGroup *newGroup = new FieldGroup(QString("Список %1").arg(groupCounter));
    newGroup->setTextColor("white");

    // Добавляем первую задачу в новую группу
    newGroup->add_first_field();

    // Подключаем сигналы новой группы
    connect(newGroup, &FieldGroup::taskClicked,
            this, &MainWindow::onTaskClicked);
    connect(newGroup, &FieldGroup::newGroupRequested,
            this, &MainWindow::createNewTaskGroup);

    // Добавляем новую группу в layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->widget_2->layout());
    if (layout) {
        layout->insertWidget(layout->count() - 1, newGroup);
    }
}


void MainWindow::showDeadlinePanel(QWidget* taskWidget)
{
    currentTaskWidget = taskWidget;
    deadlinePanel->show();
    deadlinePanel->setFixedWidth(300);

    if (auto taskButton = taskWidget->findChild<QPushButton*>()) {
        QDateTime deadline = MyDayTasks::extractDeadlineFromText(taskButton->text());
        deadlinePanel->setDeadline(deadline.isValid() ? deadline : QDateTime::currentDateTime());
    }

    if (auto central = centralWidget()) {
        central->setMinimumWidth(width() - 550);
    }
}

void MainWindow::hideDeadlinePanel()
{
    deadlinePanel->hide();
    currentTaskWidget = nullptr;
}

void MainWindow::handleDeadlineApplied(const QDateTime &deadline)
{
    if (currentTaskWidget) {
        if (auto taskButton = currentTaskWidget->findChild<QPushButton*>()) {
            QString baseText = MyDayTasks::extractBaseTaskText(taskButton->text());
            QString newText = baseText + " (До: " + deadline.toString("dd.MM.yyyy HH:mm") + ")";
            taskButton->setText(newText);

            if (auto myDayTasks = qobject_cast<MyDayTasks*>(stackedWidget->currentWidget())) {
                myDayTasks->updateTaskStyle(taskButton, taskButton->font().strikeOut());
                myDayTasks->updateTaskDeadlineInDatabase(baseText, deadline);
            }
        }
        hideDeadlinePanel();
    }
}

void MainWindow::loadTabContent(int index)
{
    if (!stackedWidget) return;

    if (stackedWidget->count() > index) {
        QWidget* oldWidget = stackedWidget->widget(index);
        stackedWidget->removeWidget(oldWidget);
        delete oldWidget;
    }

    if (index == 0) {
        MyDayTasks* myDayWidget = new MyDayTasks();
        connect(myDayWidget, &MyDayTasks::showDeadlinePanelRequested,
                this, &MainWindow::showDeadlinePanel);
        stackedWidget->insertWidget(index, myDayWidget);
        stackedWidget->setCurrentIndex(index);
        return;
    }

    QString filePath;
    switch (index) {
        case 1: filePath = ":/ui/ui/importantList.ui"; break;
        case 2: filePath = ":/ui/ui/planned.ui"; break;
        default: return;
    }

    QUiLoader loader;
    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        QWidget* tabContent = loader.load(&file);
        file.close();
        if (tabContent) {
            stackedWidget->insertWidget(index, tabContent);
            stackedWidget->setCurrentIndex(index);
        }
    }
}

void MainWindow::onTaskClicked(const QString &taskData)
{
   if (!taskDatabases.contains(taskData)) {
        MyDayTasks* newTaskDB = new MyDayTasks();
        newTaskDB->setDatabaseName(taskData);
        taskDatabases[taskData] = newTaskDB;

        connect(newTaskDB, &MyDayTasks::showDeadlinePanelRequested,
                this, &MainWindow::showDeadlinePanel);
    }

    loadTabContent(0);
    if (stackedWidget->currentWidget() != taskDatabases[taskData]) {
        stackedWidget->removeWidget(stackedWidget->currentWidget());
        stackedWidget->addWidget(taskDatabases[taskData]);
        stackedWidget->setCurrentWidget(taskDatabases[taskData]);
    }
}
