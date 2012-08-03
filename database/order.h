#ifndef DATABASE_ORDER_H
#define DATABASE_ORDER_H

#include <QList>
#include <QDateTime>

#include "model/order.h"

namespace Database {

class Order
{
public:
    static int add(Model::Order order);
    static bool update(Model::Order order);
    static Model::Order getById(int order_id);
    static QList<Model::Order> getAll();
    static QList<Model::Order> getOrdersBetweenDateTime(QDateTime from, QDateTime to);
};

}

#endif // DATABASE_ORDER_H
