#ifndef SERVICES_ITEMDETAIL_H
#define SERVICES_ITEMDETAIL_H

#include <QList>
#include "model/itemdetail.h"

namespace Services {

class ItemDetail
{
public:
    static Model::ItemDetail getById(int id);
    static QList<Model::ItemDetail> getByItemId(int itemId);
};

}

#endif // SERVICES_ITEMDETAIL_H
