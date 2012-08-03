#ifndef DATABASE_CANCELEDORDER_H
#define DATABASE_CANCELEDORDER_H

#include "model/canceledorder.h"

namespace Database {

class CanceledOrder
{
public:
    static bool add(Model::CanceledOrder canceledOrder);
    static Model::CanceledOrder getById(int id);
    static QList<Model::CanceledOrder> getAll();
};

}

#endif // DATABASE_CANCELEDORDER_H
