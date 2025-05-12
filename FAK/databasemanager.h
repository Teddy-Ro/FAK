#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>
#include <QUuid>

class DatabaseManager
{
public:
    static QString createDatabase(const QString &connectionName = "");
    static bool execute(const QString &connectionName, const QString &query);
    static QSqlQuery query(const QString &connectionName, const QString &query = "");
};

#endif // DATABASEMANAGER_H
