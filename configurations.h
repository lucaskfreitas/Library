#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <QGuiApplication>
#include <QFile>

class Configurations
{
    public:
        static QString GetDBPath();

    private:
        static QFile* GetConfigFile();
        static QString AskForDBPath();
};

#endif // CONFIGURATIONS_H
