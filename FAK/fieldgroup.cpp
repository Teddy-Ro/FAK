#include "fieldgroup.h"
#include <QSpacerItem>
#include <QSizePolicy>
#include <QMouseEvent>
#include <QStandardPaths>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QInputDialog>

FieldGroup::FieldGroup(const QString &name, QWidget *parent)
    : QWidget(parent), expanded(false), name(name)
{
    initUI();
    // Добавляем спейсер в конец layout
    fields_layout->addStretch();
}

void FieldGroup::initUI()
{
    main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(0, 0, 0, 15);
    main_layout->setSpacing(5);

    QPushButton *addGroupBtn = new QPushButton("＋ Создать новый список");
    addGroupBtn->setStyleSheet("color: white; text-align: left; padding: 5px;");
    connect(addGroupBtn, &QPushButton::clicked, this, &FieldGroup::create_new_group);
    main_layout->addWidget(addGroupBtn);

    QHBoxLayout *header_layout = new QHBoxLayout();
    header_layout->setContentsMargins(0, 0, 0, 0);

    name_field = new QLineEdit(name);
    name_field->setStyleSheet("color: white;");
    name_field->setReadOnly(false);
    connect(name_field, &QLineEdit::textChanged, this, &FieldGroup::update_name);
    header_layout->addWidget(name_field, 1);

    add_task_btn = new QPushButton("＋");
    add_task_btn->setFixedSize(20, 20);
    add_task_btn->setStyleSheet("color: white;");
    connect(add_task_btn, &QPushButton::clicked, this, &FieldGroup::create_input_field);
    header_layout->addWidget(add_task_btn);

    collapse_btn = new QPushButton("▲");
    collapse_btn->setFixedSize(20, 20);
    collapse_btn->setStyleSheet("color: white;");
    connect(collapse_btn, &QPushButton::clicked, this, &FieldGroup::toggle_fields);
    header_layout->addWidget(collapse_btn);

    delete_group_btn = new QPushButton("×");
    delete_group_btn->setFixedSize(20, 20);
    delete_group_btn->setStyleSheet("color: white;");
    connect(delete_group_btn, &QPushButton::clicked, this, &FieldGroup::delete_group);
    header_layout->addWidget(delete_group_btn);

    main_layout->addLayout(header_layout);

    fields_container = new QWidget();
    fields_container->setStyleSheet("color: white;");
    fields_layout = new QVBoxLayout(fields_container);
    fields_layout->setContentsMargins(30, 5, 0, 0);
    main_layout->addWidget(fields_container);
    fields_container->hide();
}

void FieldGroup::setTextColor(const QString &color)
{
    QString style = QString("color: %1;").arg(color);
    this->setStyleSheet(style);
    name_field->setStyleSheet(style);
}

void FieldGroup::create_new_group()
{
    emit newGroupRequested();
}

void FieldGroup::add_first_field()
{
    if (fields.isEmpty()) {
        create_input_field();
        toggle_fields();
    }
}

void FieldGroup::toggle_fields()
{
    expanded = !expanded;
    fields_container->setVisible(expanded);
    collapse_btn->setText(expanded ? "▼" : "▲");
}

void FieldGroup::show_field_settings(QPushButton* fieldBtn)
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Изменить задачу"),
                                    tr("Название задачи:"), QLineEdit::Normal,
                                    fieldBtn->text(), &ok);
    if (ok && !text.isEmpty()) {
        fieldBtn->setText(text);
        fieldBtn->setProperty("originalName", text);
    }
}

void FieldGroup::create_input_field()
{
    QHBoxLayout *container = new QHBoxLayout();
    container->setContentsMargins(0, 5, 0, 5);

    QString taskName = QString("Задача %1").arg(fields.size() + 1);
    QPushButton *fieldBtn = new QPushButton(taskName);
    fieldBtn->setStyleSheet("text-align: left; padding: 5px; color: white;");
    fieldBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    fieldBtn->setProperty("originalName", taskName);

    fieldBtn->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(fieldBtn, &QPushButton::customContextMenuRequested, [this, fieldBtn]() {
        show_field_settings(fieldBtn);
    });

    connect(fieldBtn, &QPushButton::clicked, this, &FieldGroup::onTaskButtonClicked);

    QPushButton *settingsBtn = new QPushButton("⋮");
    settingsBtn->setFixedSize(25, 25);
    settingsBtn->setStyleSheet("padding-bottom: 7px; color: white;");
    connect(settingsBtn, &QPushButton::clicked, [this, fieldBtn]() {
        show_field_settings(fieldBtn);
    });

    QPushButton *delete_btn = new QPushButton("×");
    delete_btn->setFixedSize(25, 25);
    delete_btn->setStyleSheet("color: white;");

    connect(delete_btn, &QPushButton::clicked, [this, container, fieldBtn]() {
        while (container->count()) {
            QLayoutItem *item = container->takeAt(0);
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }

        fields.removeOne(container);
        fields_layout->removeItem(container);
        delete container;

        for (int i = 0; i < fields.size(); ++i) {
            QHBoxLayout *layout = fields[i];
            if (layout->count() > 0) {
                if (QPushButton *btn = qobject_cast<QPushButton*>(layout->itemAt(0)->widget())) {
                    btn->setText(QString("Задача %1").arg(i + 1));
                    btn->setProperty("originalName", QString("Задача %1").arg(i + 1));
                }
            }
        }
    });

    container->addWidget(fieldBtn, 1);
    container->addWidget(settingsBtn);
    container->addWidget(delete_btn);

    fields_layout->addLayout(container);
    fields.append(container);
}


void FieldGroup::addGroup(FieldGroup* group)
{
    // Добавляем новую группу в layout перед спейсером
    fields_layout->insertWidget(fields_layout->count() - 1, group);

    // Устанавливаем белый цвет текста для новой группы
    group->setTextColor("white");

    // Подключаем сигналы новой группы
    connect(group, &FieldGroup::newGroupRequested,
            this, &FieldGroup::newGroupRequested);
    connect(group, &FieldGroup::taskClicked,
            this, &FieldGroup::taskClicked);
}


void FieldGroup::onTaskButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString fullTaskName = this->name + "::" + button->property("originalName").toString();
        emit taskClicked(fullTaskName);
    }
}

void FieldGroup::delete_group()
{
    deleteLater();
}

void FieldGroup::update_name()
{
    name = name_field->text();
}
