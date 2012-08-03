#ifndef DATABASE_SIZE_H
#define DATABASE_SIZE_H

#include <QList>
#include "model/size.h"

namespace Database {

class Size
{
public:
    static Model::Size getById(int id);
    static QList<Model::Size> getAll();
};

}

#endif // DATABASE_SIZE_H
