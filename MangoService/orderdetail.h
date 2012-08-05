#ifndef SERVICES_ORDERdETAIL_H
#define SERVICES_ORDERdETAIL_H

#include <QObject>
#include <QStringList>
#include "MangoService_global.h"
#include "../MangoModel/orderdetail.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT OrderDetail
{
public:
    static bool add(QList<Model::OrderDetail> orderDetails, int orderId);
    static QList<Model::OrderDetail> getByOrderId(int orderId);
};

}
#endif // SERVICES_ORDERdETAIL_H
