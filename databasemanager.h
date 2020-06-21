#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QGuiApplication>

class DatabaseManager
{
    public:
        DatabaseManager(QString aDatabasePath);
        void VerifyDatabase();

    private:
        void CreateDatabaseSchema();
};

#endif // DATABASEMANAGER_H
