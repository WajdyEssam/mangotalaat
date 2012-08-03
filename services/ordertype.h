#ifndef SERVICES_ORDERTYPE_H
#define SERVICES_ORDERTYPE_H

#include "model/ordertype.h"

namespace Services {

class OrderType
{
public:
    static Model::OrderType getById(int id);
    static QList<Model::OrderType> getAll();
};

}

#endif // SERVICES_ORDERTYPE_H
