#include "recordtypedb.h"

#include <QSqlQuery>
#include <QVariant>

int RecordTypeDb::getId()
{
    return id;
}

void RecordTypeDb::setId(int id)
{
    if (this->id == id)
        return;

    this->id = id;
    emit idChanged();
}


QString RecordTypeDb::getName()
{
    return name;
}

void RecordTypeDb::setName(QString name)
{
    if (this->name == name)
        return;

    this->name = name;
    emit nameChanged();
}


void RecordTypeDb::save()
{
    QSqlQuery query;
    query.prepare("insert into person (name) values (:name)");
    query.bindValue(":name", this->name);
    query.exec();

    loadByName(this->name);
}

bool RecordTypeDb::load(const int type_id)
{
    QSqlQuery query;
    query.prepare("select id, name from record_type where id = :id");
    query.bindValue(":id", type_id);
    query.exec();

    if (query.next())
    {
        this->id = query.value(0).toInt();
        this->name = query.value(1).toString();
        return true;
    }
    else
        return false;
}

bool RecordTypeDb::loadByName(const QString name)
{
    QSqlQuery query;
    query.prepare("select id, name from record_type where name = :name");
    query.bindValue(":name", name);
    query.exec();

    if (query.next())
    {
        this->id = query.value(0).toInt();
        this->name = query.value(1).toString();
        return true;
    }
    else
        return false;
}
