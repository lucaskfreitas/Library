#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

#include <QSettings>

class ProgramSettings
{
    public:
        QSettings settingsFile;

        ProgramSettings();
        QString getDBPath();

    private:
        QString askForDBPath();
};

#endif // PROGRAMSETTINGS_H
