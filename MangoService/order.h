#ifndef SERVICES_ORDER_H
#define SERVICES_ORDER_H

#include "MangoService_global.h"
#include "../MangoModel/order.h"
#include "../MangoModel/orderdetail.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Order
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
