#include "canceledorder.h"
#include "database/canceledorder.h"
#include "services/order.h"

namespace Services {

bool CanceledOrder::add(Model::CanceledOrder canceledOrder)
{
    return Database::CanceledOrder::add(canceledOrder);
}

Model::CanceledOrder CanceledOrder::getById(int id)
{
    Model::CanceledOrder canceledOrder = Database::CanceledOrder::getById(id);
    canceledOrder.setOrder(Services::Order::getById(canceledOrder.order().id()));
    return canceledOrder;
}

QList<Model::CanceledOrder> CanceledOrder::getAll()
{
    QList<Model::CanceledOrder> canceledOrders = Database::CanceledOrder::getAll();
    for (QList<Model::CanceledOrder>::iterator i = canceledOrders.begin(); i != canceledOrders.end(); ++i) {
        i->setOrder(Services::Order::getById(i->order().id()));
    }

    return canceledOrders;
}

}
