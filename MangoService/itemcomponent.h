#ifndef SERVICES_ITEMCOMPONENT_H
#define SERVICES_ITEMCOMPONENT_H

#include <QList>
#include "MangoService_global.h"
#include "../MangoModel/itemcomponent.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT ItemComponent
{
public:
    static QList<Model::ItemComponent> getByItemId(int itemId);
    static Model::ItemComponent getById(int id);
};

}

#endif // SERVICES_ITEMCOMPONENT_H
