#include "dbperson.h"

#include <QSqlQuery>
#include <QVariant>

int DbPerson::getId()
{
    return id;
}

void DbPerson::setName(const QString value)
{
    name = value;
}

QString DbPerson::getName()
{
    return name;
}

bool DbPerson::getIsAuthor()
{
    return isAuthor;
}

void DbPerson::setIsAuthor(const bool value)
{
    isAuthor = value;
}

void DbPerson::save()
{
    QSqlQuery query;
    query.prepare("insert into person (name, is_author) values (:name, :isAuthor)");
    query.bindValue(":name", name);
    query.bindValue(":isAuthor", isAuthor);
    query.exec();

    loadByName(name);
}

bool DbPerson::loadByName(const QString name)
{
    QSqlQuery query;
    query.prepare("select id, name from person where name = :name");
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
