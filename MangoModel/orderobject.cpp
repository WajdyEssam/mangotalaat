#include "orderobject.h"

OrderObject::OrderObject(QObject *parent) :
    QObject(parent)
{
}

OrderObject::OrderObject(int orderId, QString orderIndexId, QString name, QString description, QString cost, int orderCategory, QObject *parent) :
    QObject(parent), m_orderId(orderId), m_orderIndexId(orderIndexId), m_orderName(name), m_orderDescription(description), m_orderCost(cost), m_orderCategory(orderCategory)
{
}

int OrderObject::orderId()
{
    return m_orderId;
}

QString OrderObject::orderIndexId()
{
    return m_orderIndexId;
}


QString OrderObject::orderName()
{
    return m_orderName;
}

QString OrderObject::orderDescription()
{
    return m_orderDescription;
}

QString OrderObject::orderCost()
{
    return m_orderCost;
}

int OrderObject::orderCategory()
{
    return m_orderCategory;
}
