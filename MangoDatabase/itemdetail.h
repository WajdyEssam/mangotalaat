#ifndef DATABASE_ITEMDETAIL_H
#define DATABASE_ITEMDETAIL_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/itemdetail.h"

namespace Database {

class MANGODATABASESHARED_EXPORT ItemDetail
{
public:
    static Model::ItemDetail getById(int id);
    static QList<Model::ItemDetail> getByItemId(int itemId);
};


}
#endif // DATABASE_ITEMDETAIL_H
