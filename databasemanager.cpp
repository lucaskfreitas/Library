#include "databasemanager.h"

#include <QQmlApplicationEngine>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>

void DatabaseManager::connect(const QString databasePath)
{
    if (!databasePath.isEmpty())
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(databasePath);
        if(!db.open())
            qWarning() << "Error connecting to the Database:" << db.lastError().text();
    }
    else
        qWarning() << "No database path was informed!";
}

void DatabaseManager::verifyDatabase()
{
    QSqlQuery query("pragma user_version");
    query.next();
    int databaseVersion = query.value(0).toInt();

    if (databaseVersion == 0)
    {
        createDatabaseSchema();
    }
    else
        qDebug() << "Database already up to date!";
}

void DatabaseManager::createDatabaseSchema()
{
    QFile scriptFile(":/sql-scripts/db-schema.sql");
    if (!scriptFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "Error opening db-schema script file:" << scriptFile.errorString();
        return;
    }

    QSqlQuery query;

    QStringList commandList = QTextStream(&scriptFile).readAll().split(';');
    foreach (QString command, commandList)
    {
        if (!command.trimmed().isEmpty() && !query.exec(command))
        {
            qWarning() << "Error executing query at method DatabaseManager::CreateDatabaseSchema:" << query.lastError();
            return;
        }
    }

    qDebug() << "Database successfully created!";
}
