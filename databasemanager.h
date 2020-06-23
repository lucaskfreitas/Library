#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QGuiApplication>

class DatabaseManager
{
    public:
        static void connect(const QString databasePath);
        static void verifyDatabase();

    private:
        static void createDatabaseSchema();
};

#endif // DATABASEMANAGER_H
