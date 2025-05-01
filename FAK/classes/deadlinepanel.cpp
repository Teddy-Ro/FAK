#include "deadlinepanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>
#include <QPushButton>

DeadlinePanel::DeadlinePanel(QWidget *parent)
    : QWidget(parent)
{
    // Обновленные стили
    setStyleSheet(R"(
        DeadlinePanel {
            background-color: #131118;
            border-left: 1px solid #8d6a9f;
        }
        QDateTimeEdit {
            background-color: #0c1618;
            color: #f7f3e3;
            border: 1px solid #8d6a9f;
            padding: 5px;
            margin: 10px;
        }
        QPushButton {
            background-color: #8d6a9f;
            color: #f7f3e3;
            border: none;
            padding: 8px 15px;
            margin: 5px;
        }
        QPushButton:hover {
            background-color: #9d7aaf;
        }
    )");

    setMinimumWidth(250);
    setMaximumWidth(250);

    deadlineEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    deadlineEdit->setDisplayFormat("dd.MM.yyyy HH:mm");
    deadlineEdit->setCalendarPopup(true);

    applyButton = new QPushButton("Применить", this);
    cancelButton = new QPushButton("Отмена", this);

    // Виджет для кнопок
    QWidget *buttonsWidget = new QWidget(this);
    buttonsWidget->setStyleSheet("background: transparent;");

    QHBoxLayout *buttonsLayout = new QHBoxLayout(buttonsWidget);
    buttonsLayout->setContentsMargins(10, 0, 10, 10); // Отступы
    buttonsLayout->addWidget(applyButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Убираем внешние отступы
    mainLayout->addWidget(deadlineEdit);
    mainLayout->addWidget(buttonsWidget);
    mainLayout->addStretch(); // Растягивающийся элемент для выравнивания

    connect(applyButton, &QPushButton::clicked, this, &DeadlinePanel::applyClicked);
    connect(cancelButton, &QPushButton::clicked, this, &DeadlinePanel::cancelClicked);
}

void DeadlinePanel::setDeadline(const QDateTime &deadline)
{
    deadlineEdit->setDateTime(deadline.isValid() ? deadline : QDateTime::currentDateTime());
}

QDateTime DeadlinePanel::getDeadline() const
{
    return deadlineEdit->dateTime();
}

void DeadlinePanel::applyClicked()
{
    emit deadlineApplied(deadlineEdit->dateTime());
}

void DeadlinePanel::cancelClicked()
{
    emit cancelled();
}
