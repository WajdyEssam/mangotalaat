#ifndef SERVICES_COMPONENTPRICE_H
#define SERVICES_COMPONENTPRICE_H

#include "MangoService_global.h"
#include "../MangoModel/componentprice.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT ComponentPrice
{
public:
    static Model::ComponentPrice getById(int componentId, int sizeId);
};

}

#endif // SERVICES_COMPONENTPRICE_H
