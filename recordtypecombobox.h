#ifndef RECORDTYPECOMBOBOX_H
#define RECORDTYPECOMBOBOX_H

#include <QObject>

class RecordTypeComboBox : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList comboList READ getComboList WRITE setComboList NOTIFY comboListChanged)

    public:
        RecordTypeComboBox();

    signals:
        void comboListChanged();

    private:
        const QStringList getComboList();
        void setComboList(const QStringList &comboList);
        QStringList comboList;
};

#endif // RECORDTYPECOMBOBOX_H
