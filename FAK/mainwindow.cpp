#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint);


    // Связываем сигнал нажатия кнопки с слотом
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::createNewButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Слот для обработки нажатия кнопки
void MainWindow::createNewButton()
{
    QPushButton* newButton = new QPushButton("Новая кнопка", this);

        // Добавляем в layout
        ui->verticalLayoutForButtons->addWidget(newButton);

        // Связываем сигнал новой кнопки
        QObject::connect(newButton, &QPushButton::clicked, this, &MainWindow::handleNewButton);
}
void MainWindow::handleNewButton()
{
    // Обработчик для новых кнопок
    QMessageBox::information(this, "message", "new button tapped!");
}
