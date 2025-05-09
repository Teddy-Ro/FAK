#include "mainwindow.h"
#include <QButtonGroup>
#include <QFile>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QtUiTools/QUiLoader>
#include "classes/tasksList.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    deadlinePanel = new DeadlinePanel();
    ui->horizontalLayout->addWidget(deadlinePanel);
    deadlinePanel->hide();

    connect(deadlinePanel, &DeadlinePanel::deadlineApplied, this, &MainWindow::handleDeadlineApplied);
    connect(deadlinePanel, &DeadlinePanel::cancelled, this, &MainWindow::hideDeadlinePanel);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    buttonGroup->addButton(ui->myDayButton, 0);
    buttonGroup->addButton(ui->importantButton, 1);
    buttonGroup->addButton(ui->plannedButton, 2);
    buttonGroup->addButton(ui->allTasksButton, 3);

    stackedWidget = new QStackedWidget();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->tasks_widget->layout());
    if (layout) {
        layout->addWidget(stackedWidget);
    }

    stackedWidget->addWidget(new QWidget());

    connect(ui->myDayButton, &QPushButton::clicked, [this]() { loadTabContent(0); });
    connect(ui->importantButton, &QPushButton::clicked, [this]() { loadTabContent(1); });
    connect(ui->plannedButton, &QPushButton::clicked, [this]() { loadTabContent(2); });
    connect(ui->allTasksButton, &QPushButton::clicked, [this]() { loadTabContent(3); });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showDeadlinePanel(QWidget* taskWidget) {
    currentTaskWidget = taskWidget;
    deadlinePanel->show();
    deadlinePanel->setFixedWidth(300);

    if (auto taskButton = taskWidget->findChild<QPushButton*>()) {
        QDateTime deadline = tasksList::extractDeadlineFromText(taskButton->text());
        deadlinePanel->setDeadline(deadline.isValid() ? deadline : QDateTime::currentDateTime());
    }

    // Получаем центральный виджет и настраиваем его размер
    if (auto central = centralWidget()) {
        central->setMinimumWidth(width() - 550);
    }
}

void MainWindow::hideDeadlinePanel() {
    deadlinePanel->hide();
    currentTaskWidget = nullptr;
}

void MainWindow::handleDeadlineApplied(const QDateTime& deadline) {
    if (currentTaskWidget) {
        if (auto taskButton = currentTaskWidget->findChild<QPushButton*>()) {
            QString baseText = tasksList::extractBaseTaskText(taskButton->text());
            QString newText = baseText + " (До: " + deadline.toString("dd.MM.yyyy HH:mm") + ")";
            taskButton->setText(newText);

            // Обновляем стиль задачи
            if (auto currentTasksList = qobject_cast<tasksList*>(stackedWidget->currentWidget())) {
                currentTasksList->updateTaskStyle(taskButton, taskButton->font().strikeOut());
                currentTasksList->updateTaskDeadlineInDatabase(baseText, deadline);
            }
        }
        hideDeadlinePanel();
    }
}

void MainWindow::loadTabContent(int index) {
    if (!stackedWidget)
        return;

    // Remove old widget if it exists
    if (stackedWidget->count() > index) {
        QWidget* oldWidget = stackedWidget->widget(index);
        stackedWidget->removeWidget(oldWidget);
        delete oldWidget;
    }

    switch (index) {
        case 0: {
            tasksList* tasksWidget = new tasksList();
            connect(tasksWidget, &tasksList::showDeadlinePanelRequested, this, &MainWindow::showDeadlinePanel);
            stackedWidget->insertWidget(index, tasksWidget);
            stackedWidget->setCurrentIndex(index);
            break;
        }
        case 1: {
            tasksList* tasksWidget = new tasksList();
            connect(tasksWidget, &tasksList::showDeadlinePanelRequested, this, &MainWindow::showDeadlinePanel);
            stackedWidget->insertWidget(index, tasksWidget);
            stackedWidget->setCurrentIndex(index);
            break;
        }
        case 2: {
            tasksList* tasksWidget = new tasksList();
            connect(tasksWidget, &tasksList::showDeadlinePanelRequested, this, &MainWindow::showDeadlinePanel);
            stackedWidget->insertWidget(index, tasksWidget);
            stackedWidget->setCurrentIndex(index);
            break;
        }
        case 3: {
            tasksList* tasksWidget = new tasksList();
            connect(tasksWidget, &tasksList::showDeadlinePanelRequested, this, &MainWindow::showDeadlinePanel);
            stackedWidget->insertWidget(index, tasksWidget);
            stackedWidget->setCurrentIndex(index);
            break;
        }
        default:
            break;
    }
}
