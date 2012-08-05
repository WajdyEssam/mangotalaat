#ifndef DATABASE_CHECKOUT_H
#define DATABASE_CHECKOUT_H

#include "MangoDatabase_global.h"
#include "../MangoModel/checkout.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Checkout
{
public:
    static bool add(Model::Checkout checkout);
    static Model::Checkout getById(int id);
    static QList<Model::Checkout> getAll();
};


}
#endif // DATABASE_CHECKOUT_H
