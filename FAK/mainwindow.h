#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>
#include "fieldgroup.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTaskClicked(const QString &taskDbId);
    void onCreateNewGroup();

private:
    void initMainDatabase();
    void loadGroups();

    QStackedWidget *m_stackedWidget;
    QMap<QString, QWidget*> m_taskWidgets;
    FieldGroup *m_mainGroup;
    QString m_mainDbId;
};

#endif // MAINWINDOW_H
