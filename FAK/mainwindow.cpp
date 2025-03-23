#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Настройка интерфейса (устраняем дублирование кода)
    ui->textInput->setVisible(true);
    ui->textInput->setFocus();

    // Создаем новый виджет для списка и скролл области
    QWidget* scrollContents = new QWidget();
    QVBoxLayout* taskListLayout = new QVBoxLayout(scrollContents);
    taskListLayout->setAlignment(Qt::AlignTop); // Важно! Выравнивание по верхнему краю
    taskListLayout->setSpacing(5);

    // Настраиваем область прокрутки
    ui->scrollArea->setWidget(scrollContents);
    ui->scrollArea->setWidgetResizable(true);

    // Заменяем указатель на layout в UI
    ui->buttonsLayout = taskListLayout;

    // Связываем сигнал нажатия Enter в поле ввода с слотом
    QObject::connect(ui->textInput, &QLineEdit::returnPressed, this, &MainWindow::createButtonFromInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Слот для обработки нажатия Enter в поле ввода
void MainWindow::createButtonFromInput()
{
    QString buttonText = ui->textInput->text().trimmed();

    if (!buttonText.isEmpty()) {
        // Создаем виджет-контейнер для задачи
        QWidget* taskWidget = new QWidget();

        // Настраиваем политику размеров для правильного растягивания
        taskWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        // Создаем горизонтальный layout для этого виджета
        QHBoxLayout* taskLayout = new QHBoxLayout(taskWidget);
        taskLayout->setContentsMargins(0, 0, 0, 0);
        taskLayout->setSpacing(5);

        // Создаем чекбокс
        QCheckBox* checkbox = new QCheckBox();
        checkbox->setMaximumWidth(20); // Ограничиваем ширину чекбокса

        // Создаем кнопку с текстом и выравниванием по левой стороне
        QPushButton* newButton = new QPushButton(buttonText);
        newButton->setStyleSheet("text-align: left; padding-left: 10px;");
        newButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        // Сохраняем указатель на кнопку в свойстве чекбокса
        checkbox->setProperty("associatedButton", QVariant::fromValue((void*)newButton));

        // Добавляем виджеты в горизонтальный контейнер
        taskLayout->addWidget(checkbox);
        taskLayout->addWidget(newButton, 1);

        // Добавляем контейнер в основной layout
        ui->buttonsLayout->addWidget(taskWidget);

        // Связываем сигналы
        QObject::connect(newButton, &QPushButton::clicked, this, &MainWindow::handleNewButton);
        QObject::connect(checkbox, &QCheckBox::toggled, this, &MainWindow::handleCheckboxToggle);

        // Очищаем поле ввода для нового текста
        ui->textInput->clear();
        ui->textInput->setFocus();
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

void MainWindow::handleCheckboxToggle(bool checked)
{
    // Определяем, какой чекбокс был изменен
    QCheckBox* clickedCheckbox = qobject_cast<QCheckBox*>(sender());
    if (clickedCheckbox) {
        // Получаем связанную кнопку из свойства чекбокса
        QPushButton* button = static_cast<QPushButton*>(
            clickedCheckbox->property("associatedButton").value<void*>());

        if (button) {
            // Если задача отмечена как выполненная, делаем текст кнопки зачеркнутым
            if (checked) {
                button->setStyleSheet("text-align: left; padding-left: 10px; text-decoration: line-through;");
            } else {
                button->setStyleSheet("text-align: left; padding-left: 10px;");
            }
        }
    }
}
