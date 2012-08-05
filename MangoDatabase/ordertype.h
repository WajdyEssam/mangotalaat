#ifndef DATABASE_ORDERTYPE_H
#define DATABASE_ORDERTYPE_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/ordertype.h"

namespace Database {

class MANGODATABASESHARED_EXPORT OrderType
{
public:
    static Model::OrderType getById(int id);
    static QList<Model::OrderType> getAll();
};

}

#endif // DATABASE_ORDERTYPE_H
