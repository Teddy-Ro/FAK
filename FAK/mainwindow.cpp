#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fieldgroup.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWindow), group_count(0)
{
    ui->setupUi(this);

    // Get scroll area from UI
    QScrollArea *scroll = ui->scrollArea;
    scroll->setWidgetResizable(true);

    // Create content widget for scroll area
    scroll_content = new QWidget();
    scroll_layout = new QVBoxLayout(scroll_content);
    scroll_layout->addStretch(1);

    scroll->setWidget(scroll_content);

    // Connect add button
    connect(ui->addGroupButton, &QPushButton::clicked, this, &MainWindow::add_new_field_group);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_new_field_group()
{
    group_count++;
    FieldGroup *new_group = new FieldGroup(QString("Список %1").arg(group_count));
    new_group->add_first_field();

    // Add new group before the stretch element
    scroll_layout->insertWidget(scroll_layout->count() - 1, new_group);
}
