#ifndef SERVICES_CANCELEDORDER_H
#define SERVICES_CANCELEDORDER_H

#include "MangoService_global.h"
#include "../MangoModel/canceledorder.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT CanceledOrder
{
public:
    static bool add(Model::CanceledOrder canceledOrder);
    static Model::CanceledOrder getById(int id);
    static QList<Model::CanceledOrder> getAll();
};

}

#endif // SERVICES_CANCELEDORDER_H
