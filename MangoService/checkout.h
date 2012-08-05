#ifndef SERVICES_CHECKOUT_H
#define SERVICES_CHECKOUT_H

#include "MangoService_global.h"
#include "../MangoModel/checkout.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Checkout
{
public:
    static bool closeTodayOrders();
    static Model::Checkout getById(int id);
    static QList<Model::Checkout> getAll();
};

}

#endif // SERVICES_CHECKOUT_H
