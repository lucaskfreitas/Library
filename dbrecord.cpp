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

void DbRecord::setReferenceNumber(const QString value)
{
    referenceNumber = value;
}

QString DbRecord::getReferenceNumber()
{
    return referenceNumber;
}

void DbRecord::setCopies(const int value)
{
    copies = value;
}

int DbRecord::getCopies()
{
    return copies;
}

void DbRecord::setObs(const QString value)
{
    obs = value;
}

QString DbRecord::getObs()
{
    return obs;
}

void DbRecord::setBorrowed(const bool value)
{
    borrowed = value;
}

bool DbRecord::getBorrowed()
{
    return borrowed;
}

void DbRecord::save()
{
    QSqlQuery query;
    query.prepare("insert into record (title, n_pages, volume, number, reference_number, copies, obs, borrowed) values (:title, :numPages, :volume, :number, :referenceNumber, :copies, :obs, :borrowed)");
    query.bindValue(":title", title);
    query.bindValue(":numPages", numPages);
    query.bindValue(":volume", volume);
    query.bindValue(":number", number);
    query.bindValue(":referenceNumber", referenceNumber);
    query.bindValue(":copies", copies);
    query.bindValue(":obs", obs);
    query.bindValue(":borrowed", borrowed);
    query.exec();
}
