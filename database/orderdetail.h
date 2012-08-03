#ifndef DATABASE_ORDERDETAIL_H
#define DATABASE_ORDERDETAIL_H

#include <QList>
#include "model/orderdetail.h"

namespace Database {

class OrderDetail
{
public:
    static bool add(QList<Model::OrderDetail> orderDetails, int orderId);
    static QList<Model::OrderDetail> getByOrderId(int orderId);
private:
    static bool add(Model::OrderDetail orderDetail, int orderId);
};


}
#endif // DATABASE_ORDERDETAIL_H
