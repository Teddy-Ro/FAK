#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createButtonFromInput();      // Создать кнопку из введенного текста
    void handleNewButton();            // Обработать нажатие на созданную кнопку
    void handleCheckboxToggle(bool checked); // Обработка нажатия на чекбокс

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
