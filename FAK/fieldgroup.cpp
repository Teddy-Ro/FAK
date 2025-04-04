#include "fieldgroup.h"
#include <QSpacerItem>
#include <QSizePolicy>

FieldGroup::FieldGroup(const QString &name, QWidget *parent)
    : QWidget(parent), name(name), expanded(false)
{
    // Initialize UI
    main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(0, 0, 0, 15);

    // Header layout
    QHBoxLayout *header_layout = new QHBoxLayout();
    header_layout->setContentsMargins(0, 0, 0, 0);

    // Editable list title
    name_field = new QLineEdit(name);
    name_field->setReadOnly(false);
    connect(name_field, &QLineEdit::textChanged, this, &FieldGroup::update_name);
    header_layout->addWidget(name_field, 1);

    // Collapse button
    collapse_btn = new QPushButton("▲");
    collapse_btn->setFixedSize(20, 20);
    connect(collapse_btn, &QPushButton::clicked, this, &FieldGroup::toggle_fields);
    header_layout->addWidget(collapse_btn);

    // Delete group button
    delete_group_btn = new QPushButton("×");
    delete_group_btn->setFixedSize(20, 20);
    connect(delete_group_btn, &QPushButton::clicked, this, &FieldGroup::delete_group);
    header_layout->addWidget(delete_group_btn);

    main_layout->addLayout(header_layout);

    // Fields container with indent
    fields_container = new QWidget();
    fields_layout = new QVBoxLayout(fields_container);
    fields_layout->setContentsMargins(30, 5, 0, 0); // Right indent
    main_layout->addWidget(fields_container);
    fields_container->hide();
}

void FieldGroup::toggle_fields()
{
    expanded = !expanded;
    fields_container->setVisible(expanded);
    collapse_btn->setText(expanded ? "▼" : "▲");
}

void FieldGroup::add_first_field()
{
    if (fields.isEmpty()) {
        create_input_field();
        toggle_fields();
    }
}

void FieldGroup::create_input_field()
{
    QHBoxLayout *container = new QHBoxLayout();
    container->setContentsMargins(0, 5, 0, 5);

    // Input field
    QLineEdit *field = new QLineEdit();
    field->setPlaceholderText("Введите текст и нажмите Enter");
    connect(field, &QLineEdit::returnPressed, this, &FieldGroup::on_enter_pressed);

    // Delete button
    QPushButton *delete_btn = new QPushButton("×");
    delete_btn->setFixedSize(25, 25);
    connect(delete_btn, &QPushButton::clicked, [this, container]() {
        this->delete_field(container);
    });

    container->addWidget(field, 1);
    container->addWidget(delete_btn);

    // Add to the end of the list
    fields_layout->addLayout(container);
    fields.append(container);
    field->setFocus();
}

void FieldGroup::on_enter_pressed()
{
    QLineEdit *field = qobject_cast<QLineEdit*>(sender());
    if (field && !field->text().trimmed().isEmpty()) {
        create_input_field();
    }
}

void FieldGroup::delete_field(QHBoxLayout *container)
{
    // Remove all widgets in the container
    while (container->count()) {
        QLayoutItem *item = container->takeAt(0);
        QWidget *widget = item->widget();
        if (widget) {
            widget->deleteLater();
        }
        delete item;
    }

    fields.removeOne(container);
    fields_layout->removeItem(container);
    delete container;
}

void FieldGroup::delete_group()
{
    deleteLater();
}

void FieldGroup::update_name()
{
    name = name_field->text();
}
