#ifndef SERVICES_ORDER_H
#define SERVICES_ORDER_H

#include "model/order.h"
#include "model/orderdetail.h"

namespace Services {

class Order
{
public:
    static bool add(Model::Order order, QList<Model::OrderDetail> orderDetails);
    static bool update(Model::Order order);
    static bool cancel(Model::Order order);
    static Model::Order getById(int order_id);
    static QList<Model::Order> getAll();
    static QList<Model::Order> getOrdersBetweenDateTime(QDateTime from, QDateTime to);
};


}
#endif // SERVICES_ORDER_H
