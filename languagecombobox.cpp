#include "languagecombobox.h"

#include <QSqlQuery>
#include <QVariant>

LanguageComboBox::LanguageComboBox()
{
    QSqlQuery query("select id, name from language");
    while (query.next())
    {
        LanguageDb *language = new LanguageDb();
        language->setId(query.value(0).toInt());
        language->setName(query.value(1).toString());

        this->comboList.append(language);
    }
}

const QList<LanguageDb*> LanguageComboBox::getComboList()
{
    return this->comboList;
}

void LanguageComboBox::setComboList(const QList<LanguageDb*> &comboList)
{
    if (this->comboList != comboList)
    {
        this->comboList = comboList;
        emit comboListChanged();
    }
}
