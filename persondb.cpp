#include "persondb.h"

#include <QSqlQuery>
#include <QVariant>

int PersonDb::getId()
{
    return id;
}

void PersonDb::setName(const QString value)
{
    name = value;
}

QString PersonDb::getName()
{
    return name;
}

bool PersonDb::getIsAuthor()
{
    return isAuthor;
}

void PersonDb::setIsAuthor(const bool value)
{
    isAuthor = value;
}

void PersonDb::save()
{
    QSqlQuery query;
    query.prepare("insert into person (name, is_author) values (:name, :isAuthor)");
    query.bindValue(":name", name);
    query.bindValue(":isAuthor", isAuthor);
    query.exec();

    loadByName(name);
}

bool PersonDb::loadByName(const QString name)
{
    QSqlQuery query;
    query.prepare("select id, name, is_author from person where name = :name");
    query.bindValue(":name", name);
    query.exec();

    if (query.next())
    {
        this->id = query.value(0).toInt();
        this->name = query.value(1).toString();
        this->isAuthor = query.value(2).toBool();
        return true;
    }
    else
        return false;
}
