#include "ordertype.h"
#include "../MangoDatabase/ordertype.h"

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
