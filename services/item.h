#ifndef SERVICES_ITEM_H
#define SERVICES_ITEM_H

#include "model/item.h"

namespace Services {

class Item
{
public:
    static Model::Item getById(int id);
    static QList<Model::Item> getByCategoryId(int categoryId);
    static QList<Model::Item> getAll();
};

}

#endif // SERVICES_ITEM_H
