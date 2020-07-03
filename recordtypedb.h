#ifndef RECORDTYPEDB_H
#define RECORDTYPEDB_H

#include <QObject>

class RecordTypeDb : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    public:
        void save();
        bool load(const int type_id);

        int getId();
        void setId(int name);

        QString getName();
        void setName(QString name);

    signals:
        void idChanged();
        void nameChanged();

    private:
        int id;
        QString name;
};

#endif // RECORDTYPEDB_H
