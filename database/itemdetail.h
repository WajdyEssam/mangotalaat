#ifndef DATABASE_ITEMDETAIL_H
#define DATABASE_ITEMDETAIL_H

#include <QList>
#include "model/itemdetail.h"

namespace Database {

class ItemDetail
{
public:
    static Model::ItemDetail getById(int id);
    static QList<Model::ItemDetail> getByItemId(int itemId);
};


}
#endif // DATABASE_ITEMDETAIL_H
