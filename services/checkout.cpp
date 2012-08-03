#include "checkout.h"
#include "database/checkout.h"

namespace Services {

bool Checkout::closeTodayOrders()
{
    Model::Checkout checkout;
    checkout.setCreatedDateTime(QDateTime::currentDateTime());
    return Database::Checkout::add(checkout);
}

Model::Checkout Checkout::getById(int id)
{
    return Database::Checkout::getById(id);
}

QList<Model::Checkout> Checkout::getAll()
{
    return Database::Checkout::getAll();
}


}
