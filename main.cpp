#include "databasemanager.h"
#include "programsettings.h"
#include "recorddb.h"
#include "recordtypecombobox.h"
#include "languagecombobox.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
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

    ProgramSettings settings;

    //Database manager
    DatabaseManager::connect(settings.getDBPath());
    DatabaseManager::verifyDatabase();

    //Custom types
    qmlRegisterType<RecordDb>("org.database", 1, 0, "RecordDb");
    engine.rootContext()->setContextProperty("recordTypeComboModel", new RecordTypeComboBox);
    engine.rootContext()->setContextProperty("languageComboModel", new LanguageComboBox);

    engine.load(url);

    return app.exec();
}
