#include "configurations.h"

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileDialog>

QString Configurations::getDBPath()
{
    QString dbPath = readVariable("paths.conf", "DB_PATH");

    if (!dbPath.isEmpty() && !QFile::exists(dbPath)) //Invalid path
    {
        dbPath = "";
        removeVariable("paths.conf", "DB_PATH");
    }

    if (dbPath.isEmpty())
    {
        dbPath = askForDBPath();

        if (!dbPath.isEmpty())
            writeVariable("paths.conf", "DB_PATH", dbPath);
    }

    return dbPath;
}

QFile* Configurations::getConfigFile(const QString filename)
{
    QString appDataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dir(appDataDir);
    if (!dir.exists())
        dir.mkpath(appDataDir);

    return new QFile(appDataDir + "/" + filename);
}

QString Configurations::askForDBPath()
{
    QFileDialog dialog;
    QString selectedFile = dialog.getSaveFileName(nullptr,
                                                   "Selecione o caminho do banco de dados...",
                                                   "db.sqlite",
                                                   "SQLITE database file (*.sqlite)",
                                                   nullptr,
                                                   QFileDialog::DontConfirmOverwrite);

    if (!selectedFile.isEmpty() && !selectedFile.contains(".sqlite"))
        selectedFile += ".sqlite";

    return selectedFile;
}

QString Configurations::readVariable(const QString filename, const QString variableName)
{
    QString result = "";

    QFile* configFile = getConfigFile(filename);
    if (configFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!configFile->atEnd())
        {
            QString configLine = configFile->readLine();
            if (configLine.contains(variableName))
                result = configLine.split('=')[1].trimmed();
        }

        configFile->close();
    }

    return result;
}

void Configurations::writeVariable(const QString filename, const QString variableName, const QString value)
{
    QFile* configFile = getConfigFile(filename);
    if (configFile->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(configFile);
        stream << variableName << "=" << value << Qt::endl;
        configFile->close();
    }
}

void Configurations::removeVariable(const QString filename, const QString variableName)
{
    QFile* configFile = getConfigFile(filename);
    if (configFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(configFile);
        QString newFileContents = "";

        while (!configFile->atEnd())
        {
            QString configLine = configFile->readLine();
            if(!configLine.contains(variableName))
                newFileContents.append(configLine + "\n");
        }

        configFile->resize(0);
        stream << newFileContents;
        configFile->close();
    }
}
