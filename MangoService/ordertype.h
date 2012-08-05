#ifndef SERVICES_ORDERTYPE_H
#define SERVICES_ORDERTYPE_H

#include "MangoService_global.h"
#include "../MangoModel/ordertype.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT OrderType
{
public:
    static Model::OrderType getById(int id);
    static QList<Model::OrderType> getAll();
};

}

#endif // SERVICES_ORDERTYPE_H
