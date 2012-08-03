#ifndef SERVICES_SIZE_H
#define SERVICES_SIZE_H

#include "model/size.h"

namespace Services {

class Size
{
public:
    static Model::Size getById(int id);
    static QList<Model::Size> getAll();
};

}

#endif // SERVICES_SIZE_H
