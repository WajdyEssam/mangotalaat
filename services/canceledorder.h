#ifndef SERVICES_CANCELEDORDER_H
#define SERVICES_CANCELEDORDER_H

#include "model/canceledorder.h"

namespace Services {

class CanceledOrder
{
public:
    static bool add(Model::CanceledOrder canceledOrder);
    static Model::CanceledOrder getById(int id);
    static QList<Model::CanceledOrder> getAll();
};

}

#endif // SERVICES_CANCELEDORDER_H
