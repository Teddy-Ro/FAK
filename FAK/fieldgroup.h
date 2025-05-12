#ifndef FIELDGROUP_H
#define FIELDGROUP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "databasemanager.h"

class FieldGroup : public QWidget
{
    Q_OBJECT
public:
    explicit FieldGroup(const QString &dbId, const QString &name, QWidget *parent = nullptr);
    ~FieldGroup();

    void addTask(const QString &taskName, const QString &taskDbId = "");  // Изменили сигнатуру
    void loadTasks();
    QString dbId() const;

signals:
    void taskClicked(const QString &taskDbId);
    void newGroupRequested();

private slots:
    void onAddTaskClicked();
    void onTaskClicked();
    void onAddGroupClicked();

private:
    void initUI();
    void setupDatabase();

    QString m_dbId;
    QString m_name;
    QVBoxLayout *m_mainLayout;
    QScrollArea *m_scrollArea;
    QWidget *m_scrollContent;
    QVBoxLayout *m_tasksLayout;
};

#endif // FIELDGROUP_H
