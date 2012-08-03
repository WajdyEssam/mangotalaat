#ifndef SERVICES_COMPONENT_H
#define SERVICES_COMPONENT_H

#include "model/component.h"

namespace Services {

class Component
{
public:
    static Model::Component getById(int id);
    static QList<Model::Component> getAll();
};

}
#endif // SERVICES_COMPONENT_H
