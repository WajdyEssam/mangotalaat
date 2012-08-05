#ifndef DATABASE_ITEMCOMPONENT_H
#define DATABASE_ITEMCOMPONENT_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/itemcomponent.h"

namespace Database {

class MANGODATABASESHARED_EXPORT ItemComponent
{
public:
    static QList<Model::ItemComponent> getByItemId(int itemId);
    static Model::ItemComponent getById(int id);
};

}

#endif // DATABASE_ITEMCOMPONENT_H
