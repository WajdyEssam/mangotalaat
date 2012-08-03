#ifndef SERVICES_ITEMCOMPONENT_H
#define SERVICES_ITEMCOMPONENT_H

#include <QList>
#include "model/itemcomponent.h"

namespace Services {

class ItemComponent
{
public:
    static QList<Model::ItemComponent> getByItemId(int itemId);
    static Model::ItemComponent getById(int id);
};

}

#endif // SERVICES_ITEMCOMPONENT_H
