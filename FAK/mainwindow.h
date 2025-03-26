#ifndef MAINWINDOW_H
#define MAINWINDOW_H

<<<<<<< HEAD
#include "task.h"
#include <QList>
#include <QListWidgetItem>
=======
>>>>>>> parent of a50667e (один раз открывается вкладка, добавлена возможность открыть  ui)
#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

<<<<<<< HEAD
 private slots:
    void on_myDayButton_clicked();
    void on_importantButton_clicked();
    void on_plannedButton_clicked();
    // Удален метод on_tasksButton_clicked();
    void on_addTaskButton_clicked();
    void on_deleteTask_clicked();
    void on_editTask_clicked();

 private:
    Ui::MainWindow* ui;
    void loadTaskListUI(const QString& title);
    void connectTaskListSignals(QWidget* taskListWidget);

    QList<Task> m_tasks;

    void displayTaskList(const QString& title, std::function<bool(const Task&)> filter);
    QWidget* createTaskWidget(int taskIndex);
    void addTask(const QString& text, bool important, bool planned, bool inMyDay);
    void updateTaskList();
    void saveTasksToFile();
    void loadTasksFromFile();
=======
private slots:


private:
    Ui::MainWindow *ui;

>>>>>>> parent of a50667e (один раз открывается вкладка, добавлена возможность открыть  ui)
};
#endif // MAINWINDOW_H
