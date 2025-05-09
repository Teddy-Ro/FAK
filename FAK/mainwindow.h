#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "deadlinepanel.h"
#include "classes/tasksList.h"

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

private:
    Ui::MainWindow *ui;
    DeadlinePanel *deadlinePanel;
    QButtonGroup *buttonGroup;
    QStackedWidget *stackedWidget;
    QWidget *currentTaskWidget;
};
#endif // MAINWINDOW_H
