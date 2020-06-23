#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <QGuiApplication>
#include <QFile>

class Configurations
{
    public:
        static QString getDBPath();

    private:
        static QFile* getConfigFile(const QString filename);
        static QString askForDBPath();
        static QString readVariable(const QString filename, const QString variableName);
        static void writeVariable(const QString filename, const QString variableName, const QString value);
        static void removeVariable(const QString filename, const QString variableName);
};

#endif // CONFIGURATIONS_H
