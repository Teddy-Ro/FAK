#include "mainwindow.h"
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

    // buttons
    connect(ui->myDayButton, &QPushButton::clicked, this, &MainWindow::on_myDayButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_myDayButton_clicked() {
    // 1. Находим кнопку changeButton в структуре виджетов
    QPushButton* changeButton = ui->widget_3->findChild<QPushButton*>("changeButton");
    if (!changeButton) {
        qWarning() << "Не удалось найти changeButton";
        return;
    }

    // 2. Удаляем кнопку из layout
    QLayout* layout = ui->widget_3->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0))) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
    }

    // 3. Загружаем UI-файл
    QUiLoader loader;
    QFile file(":/ui/taskList.ui");
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Не удалось открыть файл taskList.ui:" << file.errorString();
        return;
    }

    // 4. Создаем виджет из UI-файла
    QWidget* taskListWidget = loader.load(&file);
    file.close();

    if (!taskListWidget) {
        qWarning() << "Не удалось загрузить UI из файла";
        return;
    }

    // 5. Добавляем загруженный виджет на место changeButton
    ui->widget_3->layout()->addWidget(taskListWidget);
}
