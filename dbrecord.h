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

    signals:
        void titleChanged();
        void numPagesChanged();
        void volumeChanged();
        void numberChanged();

    public slots:
        void save();

    private:
        QString title;
        int numPages;
        QString volume;
        int number;

        void setTitle(const QString value);
        void setNumPages(const int value);
        void setVolume(const QString value);
        void setNumber(const int value);
        QString getTitle();
        int getNumPages();
        QString getVolume();
        int getNumber();
};

#endif // DBRECORD_H
