#include "recordtypedb.h"

RecordTypeDb::RecordTypeDb()
{

}

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
