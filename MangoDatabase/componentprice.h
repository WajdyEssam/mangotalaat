#ifndef DATABASE_COMPONENTPRICE_H
#define DATABASE_COMPONENTPRICE_H

#include "MangoDatabase_global.h"
#include "../MangoModel/componentprice.h"

namespace Database {

class MANGODATABASESHARED_EXPORT ComponentPrice
{
public:
    static Model::ComponentPrice getById(int componentId, int sizeId);
};

}

#endif // COMPONENTPRICE_H
