#include "order.h"
#include "../MangoDatabase/order.h"
#include "ordertype.h"
#include "orderdetail.h"
#include "canceledorder.h"
#include <QDebug>

namespace Services {

bool Order::add(Model::Order order, QList<Model::OrderDetail> orderDetails)
{
    int order_id = Database::Order::add(order);

    if (order_id == -1)
        return false;

    return Services::OrderDetail::add(orderDetails, order_id);
}

bool Order::update(Model::Order order)
{
    return Database::Order::update(order);
}

bool Order::cancel(Model::Order order)
{
    order.setIsCancelled(true);
    bool ok = update(order);

    if (!ok)
        return false;

    Model::CanceledOrder canceledOrder;
    canceledOrder.setOrder(order);

    return Services::CanceledOrder::add(canceledOrder);
}

Model::Order Order::getById(int order_id)
{
    Model::Order order = Database::Order::getById(order_id);
    order.setOrderType(Services::OrderType::getById(order.orderType().id()));
    return order;
}

QList<Model::Order> Order::getAll()
{
    QList<Model::Order> orders = Database::Order::getAll();
    for (QList<Model::Order>::iterator i = orders.begin(); i != orders.end(); ++i) {
        i->setOrderType(Services::OrderType::getById(i->orderType().id()));
    }

    return orders;
}

QList<Model::Order> Order::getByUserId(int userId)
{
    QList<Model::Order> orders = Database::Order::getByUserId(userId);
    for (QList<Model::Order>::iterator i = orders.begin(); i != orders.end(); ++i) {
        i->setOrderType(Services::OrderType::getById(i->orderType().id()));
    }

    return orders;
}

QList<Model::Order> Order::getOrdersBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Order> orders = Database::Order::getOrdersBetweenDateTime(from, to);
    for (QList<Model::Order>::iterator i = orders.begin(); i != orders.end(); ++i) {
        i->setOrderType(Services::OrderType::getById(i->orderType().id()));
    }

    return orders;
}

QList<Model::Order> Order::getNotCancelledOrdersBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Order> orders = Database::Order::getNotCancelledOrdersBetweenDateTime(from, to);
    for (QList<Model::Order>::iterator i = orders.begin(); i != orders.end(); ++i) {
        i->setOrderType(Services::OrderType::getById(i->orderType().id()));
    }

    return orders;
}
}
