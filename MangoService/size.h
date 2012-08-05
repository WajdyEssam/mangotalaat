#ifndef SERVICES_SIZE_H
#define SERVICES_SIZE_H

#include "MangoService_global.h"
#include "../MangoModel/size.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Size
{
public:
    static Model::Size getById(int id);
    static QList<Model::Size> getAll();
};

}

#endif // SERVICES_SIZE_H
