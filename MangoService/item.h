#ifndef SERVICES_ITEM_H
#define SERVICES_ITEM_H

#include "MangoService_global.h"
#include "../MangoModel/item.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Item
{
public:
    static Model::Item getById(int id);
    static QList<Model::Item> getByCategoryId(int categoryId);
    static QList<Model::Item> getAll();
};

}

#endif // SERVICES_ITEM_H
