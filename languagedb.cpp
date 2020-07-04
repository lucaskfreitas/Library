#include "languagedb.h"

#include <QSqlQuery>
#include <QVariant>

int LanguageDb::getId()
{
    return id;
}

void LanguageDb::setId(const int value)
{
    id = value;
}

void LanguageDb::setName(const QString value)
{
    name = value;
}

QString LanguageDb::getName()
{
    return name;
}

void LanguageDb::save()
{
    QSqlQuery query;
    query.prepare("insert into language (name) values (:name)");
    query.bindValue(":name", name);
    query.exec();

    load(query.lastInsertId().toInt());
}

bool LanguageDb::load(const int language_id)
{
    QSqlQuery query;
    query.prepare("select id, name from language where id = :id");
    query.bindValue(":id", language_id);
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
