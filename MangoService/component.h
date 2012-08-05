#ifndef SERVICES_COMPONENT_H
#define SERVICES_COMPONENT_H

#include "MangoService_global.h"
#include "../MangoModel/component.h"

#include <QStringList>

namespace Services {

class MANGOSERVICESHARED_EXPORT Component
{
public:
    static Model::Component getById(int id);
    static QList<Model::Component> getAll();

    static QStringList componentsToStringList(QList<Model::Component> components);
    static QList<Model::Component> stringListToComponents(QStringList list);
};

}
#endif // SERVICES_COMPONENT_H
