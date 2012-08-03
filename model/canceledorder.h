#ifndef MODEL_CANCELEDORDER_H
#define MODEL_CANCELEDORDER_H

#include "model/order.h"

namespace Model {

class CanceledOrder
{
public:

    CanceledOrder();
    CanceledOrder(int id, Model::Order order, QDateTime createdDateTime);

    int id() const;
    Model::Order order() const;
    QDateTime canceledDateTime() const;

    void setOrder(Model::Order order);

private:
    int m_id;
    Model::Order m_order;
    QDateTime m_canceledDateTime;
};

}

#endif // MODEL_CANCELEDORDER_H
