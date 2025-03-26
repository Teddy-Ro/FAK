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
#include "task.h" // Подключаем наш новый класс Task

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Подключаем кнопки навигации
    connect(ui->myDayButton, &QPushButton::clicked, this, &MainWindow::on_myDayButton_clicked);
    connect(ui->importantButton, &QPushButton::clicked, this, &MainWindow::on_importantButton_clicked);
    connect(ui->plannedButton, &QPushButton::clicked, this, &MainWindow::on_plannedButton_clicked);

    // Подключаем кнопку добавления задачи
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addTaskButton_clicked);

    // Загружаем задачи из файла при запуске
    loadTasksFromFile();

    // Сделаем кнопку myDayButton активной по умолчанию
    on_myDayButton_clicked();
}

MainWindow::~MainWindow() {
    // Сохраняем задачи перед закрытием приложения
    saveTasksToFile();
    delete ui;
}

void MainWindow::displayTaskList(const QString& title, std::function<bool(const Task&)> filter) {
    // Очищаем текущее содержимое контейнера задач
    QLayout* baseLayout = ui->widget_3->layout();
    QVBoxLayout* layout = nullptr;

    if (!baseLayout) {
        // Если layout отсутствует, создаём новый
        layout = new QVBoxLayout(ui->widget_3);
        ui->widget_3->setLayout(layout);
    } else {
        // Преобразуем базовый layout к QVBoxLayout, если возможно
        layout = qobject_cast<QVBoxLayout*>(baseLayout);

        if (!layout) {
            // Если текущий layout не QVBoxLayout, создаем новый
            delete baseLayout;
            layout = new QVBoxLayout(ui->widget_3);
            ui->widget_3->setLayout(layout);
        } else {
            // Очищаем существующий layout
            QLayoutItem* item;
            while ((item = layout->takeAt(0))) {
                if (item->widget()) {
                    item->widget()->deleteLater();
                }
                delete item;
            }
        }
    }

    // Добавляем заголовок раздела
    QLabel* headerLabel = new QLabel(title, ui->widget_3);
    headerLabel->setStyleSheet("font-size: 18pt; font-weight: bold; margin-bottom: 10px;");
    layout->addWidget(headerLabel);

    // Проверка на наличие задач
    bool hasVisibleTasks = false;

    // Отображаем задачи, соответствующие фильтру
    for (int i = 0; i < m_tasks.size(); ++i) {
        const Task& task = m_tasks[i];

        if (filter(task)) {
            hasVisibleTasks = true;
            QWidget* taskWidget = createTaskWidget(i);
            layout->addWidget(taskWidget);
        }
    }

    // Если нет задач, показываем сообщение
    if (!hasVisibleTasks) {
        QLabel* emptyLabel = new QLabel("Нет задач в этом разделе", ui->widget_3);
        emptyLabel->setAlignment(Qt::AlignCenter);
        emptyLabel->setStyleSheet("color: gray; margin: 20px;");
        layout->addWidget(emptyLabel);
    }

    // Добавляем растягивающийся элемент в конец
    layout->addStretch();
}

QWidget* MainWindow::createTaskWidget(int taskIndex) {
    Task& task = m_tasks[taskIndex];

    // Создаем виджет задачи
    QWidget* taskWidget = new QWidget();
    QHBoxLayout* taskLayout = new QHBoxLayout(taskWidget);
    taskLayout->setContentsMargins(5, 5, 5, 5);

    // Чекбокс состояния задачи
    QCheckBox* checkbox = new QCheckBox();
    checkbox->setChecked(task.isCompleted());

    // Текст задачи
    QLabel* taskLabel = new QLabel(task.getText());
    taskLabel->setObjectName("taskLabel");
    taskLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Стиль для выполненных задач
    if (task.isCompleted()) {
        taskLabel->setStyleSheet("text-decoration: line-through; color: gray;");
    }

    // Кнопки редактирования и удаления
    QPushButton* editButton = new QPushButton("✎");
    editButton->setObjectName("editButton");
    editButton->setFixedSize(25, 25);
    editButton->setStyleSheet("border: none; background: transparent;");

    QPushButton* deleteButton = new QPushButton("✖");
    deleteButton->setObjectName("deleteButton");
    deleteButton->setFixedSize(25, 25);
    deleteButton->setStyleSheet("border: none; background: transparent;");

    // Добавляем элементы в layout
    taskLayout->addWidget(checkbox);
    taskLayout->addWidget(taskLabel, 1);
    taskLayout->addWidget(editButton);
    taskLayout->addWidget(deleteButton);

    // Подключаем события
    connect(checkbox, &QCheckBox::checkStateChanged, this, [this, taskIndex, taskLabel](Qt::CheckState state) {
        m_tasks[taskIndex].setCompleted(state == Qt::Checked);
        if (state == Qt::Checked) {
            taskLabel->setStyleSheet("text-decoration: line-through; color: gray;");
        } else {
            taskLabel->setStyleSheet("");
        }
        saveTasksToFile();
    });

    connect(editButton, &QPushButton::clicked, this, [this, taskIndex, taskLabel]() {
        bool ok;
        QString newText = QInputDialog::getText(this, "Редактирование задачи",
                                              "Измените текст задачи:",
                                              QLineEdit::Normal,
                                              m_tasks[taskIndex].getText(), &ok);
        if (ok && !newText.isEmpty()) {
            m_tasks[taskIndex].setText(newText);
            taskLabel->setText(newText);
            saveTasksToFile();
        }
    });

    connect(deleteButton, &QPushButton::clicked, this, [this, taskIndex, taskWidget]() {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Удаление задачи",
                                                                "Вы уверены, что хотите удалить эту задачу?",
                                                                QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            m_tasks.removeAt(taskIndex);
            taskWidget->deleteLater();
            saveTasksToFile();

            // Обновляем текущее представление
            QList<QPushButton*> buttons = {ui->myDayButton, ui->importantButton, ui->plannedButton};
            for (QPushButton* button : buttons) {
                if (button->styleSheet().contains("background-color")) {
                    button->click();
                    break;
                }
            }
        }
    });

    return taskWidget;
}

void MainWindow::on_myDayButton_clicked() {
    // Выделим активную кнопку в меню
    ui->myDayButton->setStyleSheet("background-color: #e0e0e0;");
    ui->importantButton->setStyleSheet("");
    ui->plannedButton->setStyleSheet("");

    // Показываем задачи "Мой день"
    displayTaskList("Мой день", [](const Task& task) {
        return task.isInMyDay();
    });
}

void MainWindow::on_importantButton_clicked() {
    // Выделим активную кнопку в меню
    ui->myDayButton->setStyleSheet("");
    ui->importantButton->setStyleSheet("background-color: #e0e0e0;");
    ui->plannedButton->setStyleSheet("");

    // Показываем важные задачи
    displayTaskList("Важные задачи", [](const Task& task) {
        return task.isImportant();
    });
}

void MainWindow::on_plannedButton_clicked() {
    // Выделим активную кнопку в меню
    ui->myDayButton->setStyleSheet("");
    ui->importantButton->setStyleSheet("");
    ui->plannedButton->setStyleSheet("background-color: #e0e0e0;");

    // Показываем запланированные задачи
    displayTaskList("Запланированные задачи", [](const Task& task) {
        return task.isPlanned();
    });
}

void MainWindow::on_addTaskButton_clicked() {
    bool ok;
    QString taskText = QInputDialog::getText(this, "Добавление задачи",
                                           "Введите текст задачи:",
                                           QLineEdit::Normal,
                                           "", &ok);
    if (ok && !taskText.isEmpty()) {
        // Определяем, в какой раздел добавлять
        bool inMyDay = !ui->myDayButton->styleSheet().isEmpty();
        bool important = !ui->importantButton->styleSheet().isEmpty();
        bool planned = !ui->plannedButton->styleSheet().isEmpty();

        // Создаем новую задачу
        Task newTask(taskText, important, planned, inMyDay);
        m_tasks.append(newTask);

        // Сохраняем и обновляем интерфейс
        saveTasksToFile();

        // Обновляем текущий вид
        if (inMyDay) on_myDayButton_clicked();
        else if (important) on_importantButton_clicked();
        else if (planned) on_plannedButton_clicked();
    }
}

void MainWindow::saveTasksToFile() {
    QFile file("tasks.dat");
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << m_tasks.size();
        for (const Task& task : m_tasks) {
            out << task;
        }
        file.close();
    }
}

void MainWindow::loadTasksFromFile() {
    m_tasks.clear();
    QFile file("tasks.dat");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        int count;
        in >> count;
        for (int i = 0; i < count; ++i) {
            Task task;
            in >> task;
            m_tasks.append(task);
        }
        file.close();
    } else {
        // Добавляем примеры задач при первом запуске
        m_tasks.append(Task("Завершить проект Time Manager", true, true, true));
        m_tasks.append(Task("Купить продукты", false, false, true));
        m_tasks.append(Task("Позвонить другу", false, true, false));
    }
}
