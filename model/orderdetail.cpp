#include "orderdetail.h"
#include "database/databasemanager.h"
#include "model/itemdetail.h"

namespace Model {

OrderDetail::OrderDetail(int id) :
    m_id(id)
{
    m_orderIndexId = getCurrentTimeStamp();
}

OrderDetail::OrderDetail(int id, Model::Order order, Model::ItemDetail itemDetail, int qunatity, QList<Model::Component> components,
            QList<Model::Additional> additionals, int sugar, int cash) :
    m_id(id), m_order(order), m_itemDetail(itemDetail), m_quantity(qunatity), m_components(components), m_additionals(additionals),
    m_sugar(sugar), m_cash(cash)
{
    m_orderIndexId = getCurrentTimeStamp();
}

int OrderDetail::id() const
{
    return m_id;
}

Model::Order OrderDetail::order() const
{
    return m_order;
}

Model::ItemDetail OrderDetail::itemDetail() const
{
    return m_itemDetail;
}

int OrderDetail::qunatity() const
{
    return m_quantity;
}

QList<Model::Component> OrderDetail::components() const
{
    return m_components;
}

QList<Model::Additional> OrderDetail::additionals() const
{
    return m_additionals;
}

int OrderDetail::sugar() const
{
    return m_sugar;
}

int OrderDetail::cash() const
{
    return m_cash;
}

QString OrderDetail::orderIndexId() const
{
    return m_orderIndexId;
}

void OrderDetail::setOrder(Order order)
{
    m_order = order;
}

void OrderDetail::setItemDetail(ItemDetail itemDetail)
{
    m_itemDetail = itemDetail;
}

void OrderDetail::setComponent(QList<Component> components)
{
    m_components = components;
}

void OrderDetail::setAdditionals(QList<Additional> additionals)
{
    m_additionals = additionals;
}

QString OrderDetail::getCurrentTimeStamp()
{
    return QString::number(QDateTime::currentMSecsSinceEpoch());
}

}


