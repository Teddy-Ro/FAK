#include "taskGroupsDB.h"

TaskGroupsDB::TaskGroupsDB(QObject *parent) : QObject(parent)
{
    initDatabase();
}

TaskGroupsDB::~TaskGroupsDB()
{
    if(db.isOpen()) {
        db.close();
    }
}

bool TaskGroupsDB::initDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "taskGroupsConnection");

    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dbPath);
    db.setDatabaseName(dbPath + "/taskGroups.db");

    if(!db.open()) {
        qDebug() << "Error opening task groups database:" << db.lastError().text();
        return false;
    }

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS task_groups ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT NOT NULL UNIQUE)");

    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "group_id INTEGER NOT NULL, "
               "name TEXT NOT NULL, "
               "data TEXT, "
               "FOREIGN KEY(group_id) REFERENCES task_groups(id) ON DELETE CASCADE, "
               "UNIQUE(group_id, name))");

    return true;
}

bool TaskGroupsDB::addTaskGroup(const QString &name)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO task_groups (name) VALUES (:name)");
    query.bindValue(":name", name);
    return query.exec();
}

bool TaskGroupsDB::removeTaskGroup(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM task_groups WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QList<QPair<int, QString>> TaskGroupsDB::getAllTaskGroups()
{
    QList<QPair<int, QString>> groups;
    QSqlQuery query(db);
    query.exec("SELECT id, name FROM task_groups");

    while(query.next()) {
        groups.append(qMakePair(query.value(0).toInt(), query.value(1).toString()));
    }

    return groups;
}

bool TaskGroupsDB::addTaskToGroup(int groupId, const QString &taskName, const QString &taskData)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO tasks (group_id, name, data) VALUES (:group_id, :name, :data)");
    query.bindValue(":group_id", groupId);
    query.bindValue(":name", taskName);
    query.bindValue(":data", taskData);
    return query.exec();
}

bool TaskGroupsDB::removeTaskFromGroup(int groupId, const QString &taskName)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM tasks WHERE group_id = :group_id AND name = :name");
    query.bindValue(":group_id", groupId);
    query.bindValue(":name", taskName);
    return query.exec();
}

QList<QPair<QString, QString>> TaskGroupsDB::getTasksForGroup(int groupId)
{
    QList<QPair<QString, QString>> tasks;
    QSqlQuery query(db);
    query.prepare("SELECT name, data FROM tasks WHERE group_id = :group_id");
    query.bindValue(":group_id", groupId);
    query.exec();

    while(query.next()) {
        tasks.append(qMakePair(query.value(0).toString(), query.value(1).toString()));
    }

    return tasks;
}
