#include "mainwindow.h"
#include "classes/myDayTasks.h"
#include <QAction>
#include <QCheckBox>
#include <QFile>
#include <QFrame>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QMenu>
#include <QMessageBox>
#include <QTimer>
#include <QVBoxLayout>
#include <QtUiTools/QUiLoader>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Инициализируем QStackedWidget
    stackedWidget = new QStackedWidget();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widget_3->layout());
    if (layout) {
        layout->addWidget(stackedWidget);
    }

    // Добавляем начальную страницу
    stackedWidget->addWidget(new QWidget());

    // Подключаем кнопки
    connect(ui->myDayButton, &QPushButton::clicked, [this]() { loadTabContent(0); });
    connect(ui->importantButton, &QPushButton::clicked, [this]() { loadTabContent(1); });
    connect(ui->plannedButton, &QPushButton::clicked, [this]() { loadTabContent(2); });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadTabContent(int index) {
    if (!stackedWidget) return;

    // Удаляем старый контент
    if (stackedWidget->count() > index) {
        QWidget* oldWidget = stackedWidget->widget(index);
        stackedWidget->removeWidget(oldWidget);
        delete oldWidget;
    }

    // Создаем виджет без QUiLoader для MyDayTasks
    if (index == 0) {
        MyDayTasks* myDayWidget = new MyDayTasks();
        stackedWidget->insertWidget(index, myDayWidget);
        stackedWidget->setCurrentIndex(index);
        return;
    }

    // Для остальных вкладок оставляем текущую логику
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
