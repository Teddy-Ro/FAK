#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>
#include "deadlinepanel.h"
#include "classes/myDayTasks.h"
#include "fieldgroup.h"

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
    void showDeadlinePanel(QWidget* taskWidget);
    void hideDeadlinePanel();
    void handleDeadlineApplied(const QDateTime &deadline);
    void loadTabContent(int index);
    void onTaskClicked(const QString &taskData);
    void createNewTaskGroup();

private:
    Ui::MainWindow *ui;
    DeadlinePanel *deadlinePanel;
    QButtonGroup *buttonGroup;
    QStackedWidget *stackedWidget;
    QWidget *currentTaskWidget;
    QMap<QString, MyDayTasks*> taskDatabases;
    FieldGroup *taskManagerWidget;
    int groupCounter = 1;
};

#endif // MAINWINDOW_H
