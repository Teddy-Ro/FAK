#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include <QStackedWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

 private slots:
    void loadTabContent(int index);  // Исправленное имя слота

 private:
    Ui::MainWindow* ui;
    QStackedWidget* stackedWidget;  // Добавляем член класса
    QButtonGroup* buttonGroup;
};
#endif  // MAINWINDOW_H
