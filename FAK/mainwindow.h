#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include "fieldgroup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_new_field_group();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *scroll_layout;
    QWidget *scroll_content;
    int group_count;
};

#endif // MAINWINDOW_H
