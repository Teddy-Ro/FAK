#ifndef MYDAYTASKS_H
#define MYDAYTASKS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPushButton>  // Добавлен заголовок для QPushButton
#include <QCheckBox>    // Добавлен заголовок для QCheckBox
#include <QToolButton>  // Добавлен заголовок для QToolButton

QT_BEGIN_NAMESPACE
namespace Ui {
class MyDayTasks;
}
QT_END_NAMESPACE

class MyDayTasks : public QWidget
{
    Q_OBJECT

public:
    explicit MyDayTasks(QWidget *parent = nullptr);
    ~MyDayTasks();

private slots:
    void createButtonFromInput();
    void handleTaskButtonClick();
    void handleCheckboxToggle(bool checked);
    void handleDeleteButtonClick();

private:
    Ui::MyDayTasks *ui;
    QSqlDatabase db;

    void initDatabase();
    void saveTaskToDatabase(const QString &taskText, bool completed = false);
    void updateTaskStatusInDatabase(const QString &taskText, bool completed);
    void deleteTaskFromDatabase(const QString &taskText);
    void loadTasksFromDatabase();
    void moveTaskToBottom(QWidget* taskWidget);
    void updateTaskStyle(QPushButton* button, bool completed);  // Объявление метода
};

#endif // MYDAYTASKS_H
