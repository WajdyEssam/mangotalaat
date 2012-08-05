#ifndef DATABASE_ORDERDETAIL_H
#define DATABASE_ORDERDETAIL_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/orderdetail.h"

namespace Database {

class MANGODATABASESHARED_EXPORT OrderDetail
{
public:
    static bool add(QList<Model::OrderDetail> orderDetails, int orderId);
    static QList<Model::OrderDetail> getByOrderId(int orderId);
private:
    static bool add(Model::OrderDetail orderDetail, int orderId);
};


}
#endif // DATABASE_ORDERDETAIL_H
