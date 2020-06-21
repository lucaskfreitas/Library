#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QGuiApplication>

class DatabaseManager
{
    public:
        DatabaseManager();
        void VerifyDatabase();

    private:
        void CreateDatabaseSchema();
};

#endif // DATABASEMANAGER_H
