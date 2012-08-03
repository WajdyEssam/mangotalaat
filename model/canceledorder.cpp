#include "canceledorder.h"

namespace Model {

CanceledOrder::CanceledOrder()
{}

CanceledOrder::CanceledOrder(int id, Model::Order order, QDateTime createdDateTime) :
    m_id(id), m_order(order), m_createdDateTime(createdDateTime)
{}

int CanceledOrder::id() const
{
    return m_id;
}

Model::Order CanceledOrder::order() const
{
    return m_order;
}

QDateTime CanceledOrder::canceledDateTime() const
{
    return m_canceledDateTime;
}

void CanceledOrder::setOrder(Order order)
{
    m_order = order;
}


}
