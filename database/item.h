#ifndef DATABASE_ITEM_H
#define DATABASE_ITEM_H

#include <QList>
#include "model/item.h"

namespace Database {

class Item
{
public:
    static Model::Item getById(int id);
    static QList<Model::Item> getByCategoryId(int categoryId);
    static QList<Model::Item> getAll();
};

}

#endif // DATABASE_ITEM_H
