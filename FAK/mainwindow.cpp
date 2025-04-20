#include "mainwindow.h"
#include "fieldgroup.h"
#include <QApplication>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      group_count(0)
{
    initUI();
}

void MainWindow::initUI()
{
    setWindowTitle("Управление списками полей");
    setGeometry(300, 300, 500, 400);

    QVBoxLayout *main_layout = new QVBoxLayout(this);

    add_group_btn = new QPushButton("＋ Добавить новый список");
    connect(add_group_btn, &QPushButton::clicked, this, &MainWindow::add_new_field_group);
    main_layout->addWidget(add_group_btn);

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll_content = new QWidget();
    scroll_layout = new QVBoxLayout(scroll_content);
    scroll_layout->addStretch(1);

    scroll->setWidget(scroll_content);
    main_layout->addWidget(scroll);
}

void MainWindow::add_new_field_group()
{
    group_count++;
    FieldGroup *new_group = new FieldGroup(QString("Список %1").arg(group_count));
    new_group->add_first_field();

    scroll_layout->insertWidget(scroll_layout->count() - 1, new_group);
}
