#ifndef LANGUAGEDB_H
#define LANGUAGEDB_H

#include <QObject>

class LanguageDb : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    public:
        void save();
        bool load(const int id);

        int getId();
        void setId(const int value);

        QString getName();
        void setName(const QString value);

    signals:
        void idChanged();
        void nameChanged();

    private:
        int id = -1;
        QString name = "";
};

#endif // LANGUAGEDB_H
