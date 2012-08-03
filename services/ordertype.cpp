#include "ordertype.h"
#include "database/ordertype.h"

namespace Services {

Model::OrderType OrderType::getById(int id)
{
    return Database::OrderType::getById(id);
}

QList<Model::OrderType> OrderType::getAll()
{
    return Database::OrderType::getAll();
}

}
