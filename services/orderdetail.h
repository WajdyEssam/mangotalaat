#ifndef SERVICES_ORDERdETAIL_H
#define SERVICES_ORDERdETAIL_H

#include <QObject>
#include <QStringList>

#include "model/orderdetail.h"

namespace Services {

class OrderDetail
{
public:
    static bool add(QList<Model::OrderDetail> orderDetails, int orderId);
    static QList<Model::OrderDetail> getByOrderId(int orderId);
};

}
#endif // SERVICES_ORDERdETAIL_H
