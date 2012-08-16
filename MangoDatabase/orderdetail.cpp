#include "orderdetail.h"
#include "databasemanager.h"
#include "helper.h"

namespace Database {

bool OrderDetail::add(Model::OrderDetail orderDetail, int orderId)
{

    QStringList componentsIds;
    QStringList additionalsIds;

    foreach (Model::Component c, orderDetail.components()) {
        componentsIds.append(QString::number(c.id()));
    }

    foreach (Model::Additional a, orderDetail.additionals()) {
        additionalsIds.append(QString::number(a.id()));
    }

    QSqlQuery query;

    query.prepare("INSERT INTO order_details(id, order_id, item_detial_id, quantity, components_ids, additionals_ids, sugar, cash) VALUES(NULL, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(orderId);
    query.addBindValue(orderDetail.itemDetail().id());
    query.addBindValue(orderDetail.qunatity());

    query.addBindValue(componentsIds.join(","));
    query.addBindValue(additionalsIds.join(","));
    query.addBindValue(orderDetail.sugar().id());
    query.addBindValue(orderDetail.cash());

    return query.exec();
}

bool OrderDetail::add(QList<Model::OrderDetail> orderDetails, int orderId)
{
    DatabaseManager mgr;

    foreach (Model::OrderDetail orderDetail, orderDetails) {
        add(orderDetail, orderId);
    }

    return true;
}

QList<Model::OrderDetail> OrderDetail::getByOrderId(int orderId)
{
    DatabaseManager mgr;

    QList<Model::OrderDetail> orderDetails;

    QSqlQuery query;
    query.prepare("SELECT * FROM order_details WHERE order_id = ?");
    query.addBindValue(orderId);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        int orderId = query.value(1).toInt();
        int itemDetailId = query.value(2).toInt();
        int quantity = query.value(3).toInt();
        QStringList componentList = Helper::fromTextToList(query.value(4).toString());
        QStringList additionalList = Helper::fromTextToList(query.value(5).toString());
        int sugarId = query.value(6).toInt();
        int cash = query.value(7).toInt();

        Model::Order order(orderId);
        Model::ItemDetail itemDetail(itemDetailId);

        QList<Model::Component> components;
        foreach (QString c, componentList) {
            components.append(Model::Component(c.toInt()));
        }

        QList<Model::Additional> additionals;
        foreach (QString a, additionalList) {
            additionals.append(Model::Additional(a.toInt()));
        }

        Model::Sugar sugar(sugarId);

        Model::OrderDetail orderDetail(id, order, itemDetail, quantity, components, additionals, sugar, cash);
        orderDetails.append(orderDetail);
    }

    return orderDetails;
}

}
