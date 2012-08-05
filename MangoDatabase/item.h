#ifndef DATABASE_ITEM_H
#define DATABASE_ITEM_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/item.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Item
{
public:
    static Model::Item getById(int id);
    static QList<Model::Item> getByCategoryId(int categoryId);
    static QList<Model::Item> getAll();
};

}

#endif // DATABASE_ITEM_H
