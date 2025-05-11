#ifndef TASKGROUPSDB_H
#define TASKGROUPSDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>

class TaskGroupsDB : public QObject
{
    Q_OBJECT
public:
    explicit TaskGroupsDB(QObject *parent = nullptr);
    ~TaskGroupsDB();

    bool initDatabase();
    bool addTaskGroup(const QString &name);
    bool removeTaskGroup(int id);
    QList<QPair<int, QString>> getAllTaskGroups();
    bool addTaskToGroup(int groupId, const QString &taskName, const QString &taskData);
    bool removeTaskFromGroup(int groupId, const QString &taskName);
    QList<QPair<QString, QString>> getTasksForGroup(int groupId);

private:
    QSqlDatabase db;
};

#endif // TASKGROUPSDB_H
