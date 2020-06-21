#include "databasemanager.h"
#include <QQmlApplicationEngine>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager()
{
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("C:\\Users\\Kaminski\\Workspace\\BibliotecaKaminskiFreitas\\t.sqlite");

        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void DatabaseManager::teste2()
{
    QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");

    if(!query.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}
