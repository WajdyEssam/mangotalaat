#ifndef SERVICES_COMPONENT_H
#define SERVICES_COMPONENT_H

#include "MangoService_global.h"
#include "../MangoModel/component.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Component
{
public:
    static Model::Component getById(int id);
    static QList<Model::Component> getAll();
};

}
#endif // SERVICES_COMPONENT_H
