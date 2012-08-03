#ifndef DATABASE_ORDERTYPE_H
#define DATABASE_ORDERTYPE_H

#include <QList>
#include "model/ordertype.h"

namespace Database {

class OrderType
{
public:
    static Model::OrderType getById(int id);
    static QList<Model::OrderType> getAll();
};

}

#endif // DATABASE_ORDERTYPE_H
