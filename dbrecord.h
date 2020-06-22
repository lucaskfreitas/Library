#ifndef DBRECORD_H
#define DBRECORD_H

#include <QObject>

class DbRecord : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int numPages READ numPages WRITE setNumPages NOTIFY numPagesChanged)
    Q_PROPERTY(QString volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)

public:
    DbRecord();
    void setTitle(QString aValue);
    void setNumPages(int aValue);
    void setVolume(QString aValue);
    void setNumber(int aValue);
    QString title();
    int numPages();
    QString volume();
    int number();

signals:
    void titleChanged();
    void numPagesChanged();
    void volumeChanged();
    void numberChanged();

public slots:
    void save();

private:
    QString sTitle;
    int iNumPages;
    QString sVolume;
    int iNumber;
};

#endif // DBRECORD_H
