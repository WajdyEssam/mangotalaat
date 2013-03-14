#ifndef RECIEPT_H
#define RECIEPT_H

#include <QList>
#include <QString>

#include "item.h"

class Reciept
{
public:
    Reciept();

    void addItem(Item item);
    QList<Item> items() const;

    QString total() const;
    QString discount() const;
    QString cash() const;

    void setTotal(QString total);
    void setDiscount(QString discount);
    void setCash(QString cash);

private:
    QList<Item> m_items;
    QString m_total;
    QString m_discount;
    QString m_cash;
};

#endif // RECIEPT_H
