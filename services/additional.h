#ifndef SERVICES_ADDITIONAL_H
#define SERVICES_ADDITIONAL_H

#include "model/additional.h"

namespace Services {

class Additional
{
public:
    static Model::Additional getById(int id);
    static QList<Model::Additional> getAll();
};


}
#endif // SERVICES_ADDITIONAL_H
