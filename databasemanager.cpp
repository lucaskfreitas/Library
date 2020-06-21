#include "databasemanager.h"
#include <QQmlApplicationEngine>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>

DatabaseManager::DatabaseManager(QString aDatabasePath)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(aDatabasePath);
    if(!db.open())
        qWarning() << "Error connecting to the Database:" << db.lastError().text();
}

void DatabaseManager::VerifyDatabase()
{
    QSqlQuery query("pragma user_version");
    query.next();
    int iUserVersion = query.value(0).toInt();

    if (iUserVersion == 0)
    {
        CreateDatabaseSchema();
    }
    else
        qDebug() << "Database already up to date!";

}

void DatabaseManager::CreateDatabaseSchema()
{
    QFile fScript(":/sql-scripts/db-schema.sql");
    if (!fScript.open(QIODevice::ReadOnly))
    {
        qWarning() << "Error opening db-schema script file:" << fScript.errorString();
        return;
    }

    QSqlQuery query;

    QStringList lsCommands = QTextStream(&fScript).readAll().split(';');
    foreach (QString sCommand, lsCommands)
    {
        if (!sCommand.trimmed().isEmpty() && !query.exec(sCommand))
        {
            qWarning() << "Error executing query at method DatabaseManager::CreateDatabaseSchema:" << query.lastError();
            return;
        }
    }

    qDebug() << "Database successfully created!";
}
