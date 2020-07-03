#include "databasemanager.h"
#include "configurations.h"
#include "recorddb.h"
#include "recordtypecombobox.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl)
                     {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);

    //Database manager
    DatabaseManager::connect(Configurations::getDBPath());
    DatabaseManager::verifyDatabase();

    //Custom types
    qmlRegisterType<RecordDb>("org.database", 1, 0, "RecordDb");
    engine.rootContext()->setContextProperty("recordTypeComboModel", new RecordTypeComboBox);

    engine.load(url);

    return app.exec();
}
