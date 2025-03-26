#ifndef MYDAYTASKS_H
#define MYDAYTASKS_H

#include <QCheckBox>
#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class MyDayTasks;
}
QT_END_NAMESPACE

class MyDayTasks : public QWidget {
    Q_OBJECT

 public:
    MyDayTasks(QWidget* parent = nullptr);
    ~MyDayTasks();

 private slots:
    void createButtonFromInput();             // Создать кнопку из введенного текста
    void handleNewButton();                   // Обработать нажатие на созданную кнопку
    void handleCheckboxToggle(bool checked);  // Обработка нажатия на чекбокс

 private:
    Ui::MyDayTasks* ui;
};
#endif  // MYDAYTASKS_H
