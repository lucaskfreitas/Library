#include "dbrecord.h"

#include <QSqlQuery>
#include <QVariant>

DbRecord::DbRecord()
{

}

void DbRecord::setTitle(QString aValue)
{
    sTitle = aValue;
}

QString DbRecord::title()
{
    return sTitle;
}

void DbRecord::setNumPages(int aValue)
{
    iNumPages = aValue;
}

int DbRecord::numPages()
{
    return iNumPages;
}

void DbRecord::setVolume(QString aValue)
{
    sVolume = aValue;
}

QString DbRecord::volume()
{
    return sVolume;
}

void DbRecord::setNumber(int aValue)
{
    iNumber = aValue;
}

int DbRecord::number()
{
    return iNumber;
}

void DbRecord::save()
{
    QSqlQuery query;
    query.prepare("insert into record (title, n_pages, volume, number) values (:title, :num_pages, :volume, :number)");
    query.bindValue(":title", sTitle);
    query.bindValue(":num_pages", iNumPages);
    query.bindValue(":volume", sVolume);
    query.bindValue(":number", iNumber);
    query.exec();
}
