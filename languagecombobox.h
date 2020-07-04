#ifndef LANGUAGECOMBOBOX_H
#define LANGUAGECOMBOBOX_H

#include "languagedb.h"

#include <QObject>

class LanguageComboBox : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<LanguageDb*> comboList READ getComboList WRITE setComboList NOTIFY comboListChanged)

    public:
        LanguageComboBox();

    signals:
        void comboListChanged();

    private:
        const QList<LanguageDb*> getComboList();
        void setComboList(const QList<LanguageDb*> &comboList);
        QList<LanguageDb*> comboList;
};

#endif // LANGUAGECOMBOBOX_H
