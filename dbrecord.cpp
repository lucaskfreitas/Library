#include "dbrecord.h"

#include <QSqlQuery>
#include <QVariant>

void DbRecord::setTitle(const QString value)
{
    title = value;
}

QString DbRecord::getTitle()
{
    return title;
}

void DbRecord::setNumPages(const int value)
{
    numPages = value;
}

int DbRecord::getNumPages()
{
    return numPages;
}

void DbRecord::setVolume(const QString value)
{
    volume = value;
}

QString DbRecord::getVolume()
{
    return volume;
}

void DbRecord::setNumber(const int value)
{
    number = value;
}

int DbRecord::getNumber()
{
    return number;
}

void DbRecord::save()
{
    QSqlQuery query;
    query.prepare("insert into record (title, n_pages, volume, number) values (:title, :numPages, :volume, :number)");
    query.bindValue(":title", title);
    query.bindValue(":numPages", numPages);
    query.bindValue(":volume", volume);
    query.bindValue(":number", number);
    query.exec();
}
