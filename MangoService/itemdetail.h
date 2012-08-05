#ifndef SERVICES_ITEMDETAIL_H
#define SERVICES_ITEMDETAIL_H

#include <QList>
#include "MangoService_global.h"
#include "../MangoModel/itemdetail.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT ItemDetail
{
public:
    static Model::ItemDetail getById(int id);
    static QList<Model::ItemDetail> getByItemId(int itemId);
};

}

#endif // SERVICES_ITEMDETAIL_H
