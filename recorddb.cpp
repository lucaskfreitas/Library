#include "recorddb.h"

#include <QSqlQuery>
#include <QVariant>

void RecordDb::setTitle(const QString value)
{
    title = value;
}

QString RecordDb::getTitle()
{
    return title;
}

void RecordDb::setNumPages(const int value)
{
    numPages = value;
}

int RecordDb::getNumPages()
{
    return numPages;
}

void RecordDb::setVolume(const QString value)
{
    volume = value;
}

QString RecordDb::getVolume()
{
    return volume;
}

void RecordDb::setNumber(const int value)
{
    number = value;
}

int RecordDb::getNumber()
{
    return number;
}

void RecordDb::setReferenceNumber(const QString value)
{
    referenceNumber = value;
}

QString RecordDb::getReferenceNumber()
{
    return referenceNumber;
}

void RecordDb::setCopies(const int value)
{
    copies = value;
}

int RecordDb::getCopies()
{
    return copies;
}

void RecordDb::setObs(const QString value)
{
    obs = value;
}

QString RecordDb::getObs()
{
    return obs;
}

void RecordDb::setBorrowed(const bool value)
{
    borrowed = value;
}

bool RecordDb::getBorrowed()
{
    return borrowed;
}

void RecordDb::setBorrowedTo(const QString person_name)
{
    if (person_name.isEmpty())
        return;

    if (!borrowedTo.loadByName(person_name))
    {
        borrowedTo.setIsAuthor(false);
        borrowedTo.setName(person_name);
        borrowedTo.save();
    }
}

QString RecordDb::getBorrowedTo()
{
    return borrowedTo.getName();
}

void RecordDb::setDay(const int value)
{
    day = value;
}

int RecordDb::getDay()
{
    return day;
}

void RecordDb::setMonth(const int value)
{
    month = value;
}

int RecordDb::getMonth()
{
    return month;
}

void RecordDb::setYear(const int value)
{
    year = value;
}

int RecordDb::getYear()
{
    return year;
}

void RecordDb::save()
{
    QSqlQuery query;
    query.prepare("insert into record (title, day, month, year, n_pages, volume, number, reference_number, copies, obs, borrowed, borrowed_to) values (:title, :day, :month, :year, :numPages, :volume, :number, :referenceNumber, :copies, :obs, :borrowed, :borrowedTo)");
    query.bindValue(":title", title);
    query.bindValue(":day", day);
    query.bindValue(":month", month);
    query.bindValue(":year", year);
    query.bindValue(":numPages", numPages);
    query.bindValue(":volume", volume);
    query.bindValue(":number", number);
    query.bindValue(":referenceNumber", referenceNumber);
    query.bindValue(":copies", copies);
    query.bindValue(":obs", obs);
    query.bindValue(":borrowed", borrowed);
    query.bindValue(":borrowedTo", borrowedTo.getId());
    query.exec();
}