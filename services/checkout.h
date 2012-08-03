#ifndef SERVICES_CHECKOUT_H
#define SERVICES_CHECKOUT_H

#include "model/checkout.h"

namespace Services {

class Checkout
{
public:
    static bool closeTodayOrders();
    static Model::Checkout getById(int id);
    static QList<Model::Checkout> getAll();
};

}

#endif // SERVICES_CHECKOUT_H
