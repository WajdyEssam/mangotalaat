#ifndef DATABASE_CHECKOUT_H
#define DATABASE_CHECKOUT_H

#include "model/checkout.h"

namespace Database {

class Checkout
{
public:
    static bool add(Model::Checkout checkout);
    static Model::Checkout getById(int id);
    static QList<Model::Checkout> getAll();
};


}
#endif // DATABASE_CHECKOUT_H
