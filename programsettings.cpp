#include "programsettings.h"

#include <QFileDialog>

ProgramSettings::ProgramSettings()
    : settingsFile(QSettings::IniFormat, QSettings::UserScope, "LKF", "Library") {}

QString ProgramSettings::getDBPath()
{
    QString dbPath = settingsFile.value("DB_PATH").toString();

    if (!dbPath.isEmpty() && !QFile::exists(dbPath)) //Invalid path
    {
        dbPath = "";
        settingsFile.remove("DB_PATH");
    }

    if (dbPath.isEmpty())
    {
        dbPath = askForDBPath();

        if (!dbPath.isEmpty())
            settingsFile.setValue("DB_PATH", dbPath);
    }

    return dbPath;
}

QString ProgramSettings::askForDBPath()
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
