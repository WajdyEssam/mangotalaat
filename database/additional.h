#ifndef DATABASE_ADDITIONAL_H
#define DATABASE_ADDITIONAL_H

#include <QList>
#include "model/additional.h"

namespace Database {

class Additional
{
public:
    static Model::Additional getById(int id);
    static QList<Model::Additional> getAll();
};

}

#endif // DATABASE_ADDITIONAL_H
