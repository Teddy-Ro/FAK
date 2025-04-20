#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void add_new_field_group();

private:
    void initUI();

    QPushButton *add_group_btn;
    QScrollArea *scroll;
    QWidget *scroll_content;
    QVBoxLayout *scroll_layout;
    int group_count;
};

#endif // MAINWINDOW_H
