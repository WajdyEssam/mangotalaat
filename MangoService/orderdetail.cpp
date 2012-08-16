#include "orderdetail.h"
#include "../MangoDatabase/orderdetail.h"
#include "../MangoModel/itemcomponent.h"
#include "order.h"
#include "item.h"
#include "additional.h"
#include "component.h"
#include "itemdetail.h"
#include "itemcomponent.h"
#include "sugar.h"

#include <QDebug>

namespace Services {

Model::OrderDetail OrderDetail::getEmptyOrderDetail(int itemDetailId)
{
    Model::OrderDetail orderDetail;
    orderDetail.setItemDetail(Services::ItemDetail::getById(itemDetailId));
    orderDetail.setCash(orderDetail.itemDetail().price());

    int categoryId = orderDetail.itemDetail().item().category().id();

    if ( categoryId == Model::Category::Cocktails || categoryId == Model::Category::Speical_Cocktial ) {

        QList<Model::Component> components;
        foreach (Model::ItemComponent itemComponent, Services::ItemComponent::getByItemId(orderDetail.itemDetail().item().id())) {
            Model::Component c = Services::Component::getById(itemComponent.component().id());
            components.append(c);
        }

        orderDetail.setComponent(components);
    }

    return orderDetail;
}

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
        i->setSugar(Services::Sugar::getById(i->sugar().id()));

        QList<Model::Component> components;
        foreach (Model::Component c, i->components()) {
            Model::Component tmp = Services::Component::getById(c.id());
            components.append(tmp);
        }

        i->setComponent(components);

        QList<Model::Additional> additional;
        foreach (Model::Additional a, i->additionals()) {
            Model::Additional tmp = Services::Additional::getById(a.id());
            additional.append(tmp);
        }

        i->setAdditionals(additional);
    }

    return orderDetails;
}

}


