#include "recordtypecombobox.h"

#include <QSqlQuery>
#include <QVariant>

RecordTypeComboBox::RecordTypeComboBox()
{
    QSqlQuery query("select name from record_type");
    while (query.next())
        this->comboList << query.value(0).toString();
}

const QStringList RecordTypeComboBox::getComboList()
{
    return this->comboList;
}

void RecordTypeComboBox::setComboList(const QStringList &comboList)
{
    if (this->comboList != comboList)
    {
        this->comboList = comboList;
        emit comboListChanged();
    }
}
