#include "databasemanager.h"

QString DatabaseManager::createDatabase(const QString &connectionName)
{
    QString dbName = connectionName.isEmpty() ? QUuid::createUuid().toString() : connectionName;
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dbPath);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", dbName);
    db.setDatabaseName(dbPath + "/" + dbName + ".db");

    if (!db.open()) {
        qWarning() << "Cannot open database:" << db.lastError().text();
        return "";
    }

    return dbName;
}

bool DatabaseManager::execute(const QString &connectionName, const QString &queryStr)
{
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    if (!db.isOpen()) return false;

    QSqlQuery query(db);
    return query.exec(queryStr);
}

QSqlQuery DatabaseManager::query(const QString &connectionName, const QString &queryStr)
{
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery q(db);
    if (!queryStr.isEmpty()) q.exec(queryStr);
    return q;
}
