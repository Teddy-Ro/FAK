#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint);

    // Изначально скрываем поле ввода
    ui->textInput->setVisible(false);

    // Связываем сигнал нажатия кнопки с слотом
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::showInputField);

    // Связываем сигнал нажатия Enter в поле ввода с слотом
    QObject::connect(ui->textInput, &QLineEdit::returnPressed, this, &MainWindow::createButtonFromInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Слот для обработки нажатия основной кнопки - показываем поле ввода
void MainWindow::showInputField()
{
    ui->textInput->setVisible(true);
    ui->textInput->clear();
    ui->textInput->setFocus();
}

// Слот для обработки нажатия Enter в поле ввода
void MainWindow::createButtonFromInput()
{
    QString buttonText = ui->textInput->text();

    if (!buttonText.isEmpty()) {
        // Создаем новую кнопку с введенным текстом
        QPushButton* newButton = new QPushButton(buttonText, this);

        // Добавляем в layout - используем правильное имя layout
        ui->verticalLayout->addWidget(newButton);  // изменено с verticalLayoutForButtons на verticalLayout

        // Связываем сигнал новой кнопки
        QObject::connect(newButton, &QPushButton::clicked, this, &MainWindow::handleNewButton);

        // Скрываем поле ввода после создания кнопки
        ui->textInput->setVisible(false);
    }
}

void MainWindow::handleNewButton()
{
    // Определяем, какая кнопка была нажата
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        // Показываем текст нажатой кнопки
        QMessageBox::information(this, "Нажата кнопка",
                                "Вы нажали кнопку: " + clickedButton->text());
    }
}
