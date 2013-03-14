#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item(QString qunatity, QString size, QString name, QString sugar,
         QString components, QString additionals, QString price);

    QString quantity() const;
    QString size() const;
    QString name() const;
    QString sugar() const;
    QString components() const;
    QString additionals() const;
    QString price() const;

private:
    QString m_quantity;
    QString m_size;
    QString m_name;
    QString m_sugar;
    QString m_components;
    QString m_additionals;
    QString m_price;
};

#endif // ITEM_H
