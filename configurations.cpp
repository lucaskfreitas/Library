#include "configurations.h"
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileDialog>

QString Configurations::GetDBPath()
{
    QString sDBPath = ReadVariable("paths.conf", "DB_PATH");

    if (!sDBPath.isEmpty() && !QFile::exists(sDBPath)) //Invalid path
    {
        sDBPath = "";
        RemoveVariable("paths.conf", "DB_PATH");
    }

    if (sDBPath.isEmpty())
    {
        sDBPath = AskForDBPath();

        if (!sDBPath.isEmpty())
            WriteVariable("paths.conf", "DB_PATH", sDBPath);
    }

    return sDBPath;
}

QFile* Configurations::GetConfigFile(QString aFilename)
{
    QString sAppDataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dir(sAppDataDir);
    if (!dir.exists())
        dir.mkpath(sAppDataDir);

    return new QFile(sAppDataDir + "/" + aFilename);
}

QString Configurations::AskForDBPath()
{
    QFileDialog dialog;
    QString sSelectedFile = dialog.getSaveFileName(nullptr,
                                                   "Selecione o caminho do banco de dados...",
                                                   "db.sqlite",
                                                   "SQLITE database file (*.sqlite)",
                                                   nullptr,
                                                   QFileDialog::DontConfirmOverwrite);

    if (!sSelectedFile.isEmpty() && !sSelectedFile.contains(".sqlite"))
        sSelectedFile += ".sqlite";

    return sSelectedFile;
}

QString Configurations::ReadVariable(QString aFilename, QString aVariableName)
{
    QString sResult = "";

    QFile* fConfig = GetConfigFile(aFilename);
    if (fConfig->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fConfig->atEnd())
        {
            QString sConfigLine = fConfig->readLine();
            if (sConfigLine.contains(aVariableName))
                sResult = sConfigLine.split('=')[1].trimmed();
        }

        fConfig->close();
    }

    return sResult;
}

void Configurations::WriteVariable(QString aFilename, QString aVariableName, QString aValue)
{
    QFile* fConfig = GetConfigFile(aFilename);
    if (fConfig->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream oStream(fConfig);
        oStream << aVariableName << "=" << aValue << Qt::endl;
        fConfig->close();
    }
}

void Configurations::RemoveVariable(QString aFilename, QString aVariableName)
{
    QFile* fConfig = GetConfigFile(aFilename);
    if (fConfig->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream oStream(fConfig);
        QString sNewFileContents = "";

        while (!fConfig->atEnd())
        {
            QString sConfigLine = fConfig->readLine();
            if(!sConfigLine.contains(aVariableName))
                sNewFileContents.append(sConfigLine + "\n");
        }

        fConfig->resize(0);
        oStream << sNewFileContents;
        fConfig->close();
    }
}
