#ifndef SERVICES_ADDITIONAL_H
#define SERVICES_ADDITIONAL_H

#include "MangoService_global.h"
#include "../MangoModel/additional.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Additional
{
public:
    static Model::Additional getById(int id);
    static QList<Model::Additional> getAll();
};


}
#endif // SERVICES_ADDITIONAL_H
