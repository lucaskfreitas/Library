#include "configurations.h"
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileDialog>

QString Configurations::GetDBPath()
{
    QString sDBPath;

    QFile* fConfig = GetConfigFile();
    if (fConfig->open(QIODevice::ReadWrite))
    {
        while (!fConfig->atEnd())
        {
            QString sConfigLine = fConfig->readLine();

            if (sConfigLine.contains("DB_PATH"))
            {
                sDBPath = sConfigLine.split('=')[1].trimmed();
                break;
            }
        }

        if (sDBPath.isEmpty())
        {
            sDBPath = AskForDBPath();
            QTextStream stream(fConfig);
            stream << "DB_PATH = " << sDBPath << Qt::endl;
        }

        fConfig->close();
    }
    else
        qWarning() << "Error opening paths.conf:" << fConfig->errorString();

    return sDBPath;
}

QFile* Configurations::GetConfigFile()
{
    QString sAppDataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dir(sAppDataDir);
    if (!dir.exists())
        dir.mkpath(sAppDataDir);

    return new QFile(sAppDataDir + "/paths.conf");
}

QString Configurations::AskForDBPath()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly);

    dialog.exec();

    return dialog.directory().path() + "/db.sqlite";
}
