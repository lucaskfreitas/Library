#ifndef RECORDTYPECOMBOBOX_H
#define RECORDTYPECOMBOBOX_H

#include "recordtypedb.h"

#include <QObject>

class RecordTypeComboBox : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<RecordTypeDb*> comboList READ getComboList WRITE setComboList NOTIFY comboListChanged)

    public:
        RecordTypeComboBox();

    signals:
        void comboListChanged();

    private:
        const QList<RecordTypeDb*> getComboList();
        void setComboList(const QList<RecordTypeDb*> &comboList);
        QList<RecordTypeDb*> comboList;
};

#endif // RECORDTYPECOMBOBOX_H
