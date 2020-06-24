#ifndef DBRECORD_H
#define DBRECORD_H

#include <QObject>

class DbRecord : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int numPages READ getNumPages WRITE setNumPages NOTIFY numPagesChanged)
    Q_PROPERTY(QString volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString referenceNumber READ getReferenceNumber WRITE setReferenceNumber NOTIFY referenceNumberChanged)
    Q_PROPERTY(int copies READ getCopies WRITE setCopies NOTIFY copiesChanged)
    Q_PROPERTY(QString obs READ getObs WRITE setObs NOTIFY obsChanged)
    Q_PROPERTY(bool borrowed READ getBorrowed WRITE setBorrowed NOTIFY borrowedChanged)

    signals:
        void titleChanged();
        void numPagesChanged();
        void volumeChanged();
        void numberChanged();
        void referenceNumberChanged();
        void copiesChanged();
        void obsChanged();
        void borrowedChanged();

    public slots:
        void save();

    private:
        QString title = "";
        int numPages = -1;
        QString volume = "";
        int number = -1;
        QString referenceNumber = "";
        int copies = -1;
        QString obs = "";
        bool borrowed = false;

        void setTitle(const QString value);
        void setNumPages(const int value);
        void setVolume(const QString value);
        void setNumber(const int value);
        void setReferenceNumber(const QString value);
        void setCopies(const int value);
        void setObs(const QString value);
        void setBorrowed(const bool value);

        QString getTitle();
        int getNumPages();
        QString getVolume();
        int getNumber();
        QString getReferenceNumber();
        int getCopies();
        QString getObs();
        bool getBorrowed();
};

#endif // DBRECORD_H
