#ifndef MODEL_ORDERDETAIL_H
#define MODEL_ORDERDETAIL_H

#include <QStringList>
#include <QList>
#include "MangoModel_global.h"
#include "order.h"
#include "itemdetail.h"
#include "component.h"
#include "additional.h"
#include "sugar.h"

namespace Model {

class MANGOMODELSHARED_EXPORT OrderDetail
{
public:
    OrderDetail();
    OrderDetail(int id);
    OrderDetail(int id, Model::Order order, Model::ItemDetail itemDetail, int qunatity, QList<Model::Component> components,
                QList<Model::Additional> additionals, Model::Sugar sugar, int cash);

    int id() const;
    Model::Order order() const;
    Model::ItemDetail itemDetail() const;
    int qunatity()const;
    QList<Model::Component> components() const;
    QList<Model::Additional> additionals() const;
    Model::Sugar sugar() const;
    int cash() const;
    QString orderIndexId() const;

    void setOrder(Model::Order order);
    void setItemDetail(Model::ItemDetail itemDetail);
    void setQuantity(int quantity);
    void setComponent(QList<Model::Component> components);
    void setAdditionals(QList<Model::Additional> additionals);
    void setSugar(Model::Sugar sugar);
    void setCash(int cash);

private:
    QString getCurrentTimeStamp();

    int m_id;
    Model::Order m_order;
    Model::ItemDetail m_itemDetail;
    int m_quantity;
    QList<Model::Component> m_components;
    QList<Model::Additional> m_additionals;
    Model::Sugar m_sugar;
    int m_cash;
    QString m_orderIndexId;
};

}

#endif // MODEL_ORDERDETAIL_H
