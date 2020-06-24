#ifndef DBPERSON_H
#define DBPERSON_H

#include <QObject>

class DbPerson : QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    public:
        void save();
        bool loadByName(const QString name);

        int getId();

        QString getName();
        void setName(const QString value);

        bool getIsAuthor();
        void setIsAuthor(const bool value);

    signals:
        void nameChanged();

    private:
        int id = -1;
        bool isAuthor = false;
        QString name = "";
};

#endif // DBPERSON_H
