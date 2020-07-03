#include "recordtypecombobox.h"

#include <QSqlQuery>
#include <QVariant>

RecordTypeComboBox::RecordTypeComboBox()
{
    QSqlQuery query("select id, name from record_type");
    while (query.next())
    {
        RecordTypeDb *recordType = new RecordTypeDb();
        recordType->setId(query.value(0).toInt());
        recordType->setName(query.value(1).toString());

        this->comboList.append(recordType);
    }
}

const QList<RecordTypeDb*> RecordTypeComboBox::getComboList()
{
    return this->comboList;
}

void RecordTypeComboBox::setComboList(const QList<RecordTypeDb*> &comboList)
{
    if (this->comboList != comboList)
    {
        this->comboList = comboList;
        emit comboListChanged();
    }
}
