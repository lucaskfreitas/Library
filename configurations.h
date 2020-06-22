#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <QGuiApplication>
#include <QFile>

class Configurations
{
    public:
        static QString GetDBPath();

    private:
        static QFile* GetConfigFile(QString aFilename);
        static QString AskForDBPath();
        static QString ReadVariable(QString aFilename, QString aVariableName);
        static void WriteVariable(QString aFilename, QString aVariableName, QString aValue);
        static void RemoveVariable(QString aFilename, QString aVariableName);
};

#endif // CONFIGURATIONS_H
