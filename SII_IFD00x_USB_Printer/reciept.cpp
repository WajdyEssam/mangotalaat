#include "reciept.h"

Reciept::Reciept()
{
}

void Reciept::addItem(Item item)
{
    m_items.append(item);
}

QList<Item> Reciept::items() const
{
    return m_items;
}

void Reciept::setTotal(QString total)
{
    m_total = total;
}

void Reciept::setDiscount(QString discount)
{
    m_discount = discount;
}

void Reciept::setCash(QString cash)
{
    m_cash = cash;
}

QString Reciept::total() const
{
    return m_total;
}

QString Reciept::discount() const
{
    return m_discount;
}

QString Reciept::cash() const
{
    return m_cash;
}
