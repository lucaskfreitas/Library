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

int RecordDb::getType()
{
    return type.getId();
}

void RecordDb::setType(const int type_id)
{
    if (type_id == 0)
        return;

    if (!type.load(type_id))
        type.save();
}

void RecordDb::setAuthors(const QString author_names)
{
    authors = author_names;
}

QString RecordDb::getAuthors()
{
    return authors;
    /*QString result = "";
    for (PersonDb* author : this->authors)
    {
        if (!result.isEmpty())
            result += "; ";
        result += author->getName();
    }

    return result;*/
}

int RecordDb::getLanguage()
{
    return language.getId();
}

void RecordDb::setLanguage(const int language_id)
{
    if (language_id == 0)
        return;

    if (!language.load(language_id))
        language.save();
}

void RecordDb::save()
{
    QSqlQuery query;
    query.prepare("insert into record (title, type_id, day, month, year, n_pages, volume, number, reference_number, copies, obs, borrowed, borrowed_to, language_id) values (:title, :type_id, :day, :month, :year, :numPages, :volume, :number, :referenceNumber, :copies, :obs, :borrowed, :borrowedTo, :language_id)");
    query.bindValue(":title", title);
    query.bindValue(":type_id", type.getId());
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
    query.bindValue(":language_id", language.getId());
    query.exec();
    this->id = query.lastInsertId().toInt();

    //Authors
    query.prepare("insert into record_author (record_id, author_id) values (:record_id, :author_id)");
    query.bindValue(":record_id", this->id);

    for (QString author_name : this->authors.split(QLatin1Char(';')))
    {
        PersonDb author;
        if (!author.loadByName(author_name))
        {
            author.setName(author_name.trimmed());
            author.setIsAuthor(true);
            author.save();
        }

        query.bindValue(":author_id", author.getId());
        query.exec();
    }
}
