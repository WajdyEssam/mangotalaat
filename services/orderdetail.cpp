#include "orderdetail.h"
#include "database/orderdetail.h"
#include "services/order.h"
#include "services/item.h"
#include "services/additional.h"
#include "services/component.h"
#include "services/itemdetail.h"

namespace Services {

bool OrderDetail::add(QList<Model::OrderDetail> orderDetails, int orderId)
{
    return Database::OrderDetail::add(orderDetails, orderId);
}

QList<Model::OrderDetail> OrderDetail::getByOrderId(int orderId)
{
    QList<Model::OrderDetail> orderDetails = Database::OrderDetail::getByOrderId(orderId);
    for (QList<Model::OrderDetail>::iterator i = orderDetails.begin(); i != orderDetails.end(); ++i) {
        i->setOrder(Services::Order::getById(i->order().id()));
        i->setItemDetail(Services::ItemDetail::getById(i->itemDetail().id()));

        QList<Model::Component> components;
        foreach (Model::Component c, i->components()) {
            c = Services::Component::getById(c.id());
            components.append(c);
        }

        i->setComponent(components);

        QList<Model::Additional> additional;
        foreach (Model::Additional a, i->additionals()) {
            a = Services::Additional::getById(a.id());
            additional.append(a);
        }

        i->setAdditionals(additional);
    }

    return orderDetails;
}

}


