#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QGuiApplication>

class DatabaseManager
{
public:
    static void Connect(QString aDatabasePath);
    static void VerifyDatabase();

private:
    static void CreateDatabaseSchema();
};

#endif // DATABASEMANAGER_H
