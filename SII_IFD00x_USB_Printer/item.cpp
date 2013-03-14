#include "item.h"


Item::Item(QString qunatity, QString size, QString name, QString sugar, QString components, QString additionals, QString price) :
    m_quantity(qunatity),
    m_size(size),
    m_name(name),
    m_sugar(sugar),
    m_components(components),
    m_additionals(additionals),
    m_price(price)
{
}

QString Item::quantity() const
{
    return m_quantity;
}

QString Item::size() const
{
    return m_size;
}

QString Item::name() const
{
    return m_name;
}

QString Item::sugar() const
{
    return m_sugar;
}

QString Item::components() const
{
    return m_components;
}

QString Item::additionals() const
{
    return m_additionals;
}

QString Item::price() const
{
    return m_price;
}
