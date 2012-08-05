#include "component.h"
#include "../MangoDatabase/component.h"

namespace Services {

Model::Component Component::getById(int id)
{
    return Database::Component::getById(id);
}

QList<Model::Component> Component::getAll()
{
    return Database::Component::getAll();
}

QStringList Component::componentsToStringList(QList<Model::Component> components)
{
    QStringList list;
    foreach (Model::Component component, components) {
        list.append(QString::number(component.id()));
    }

    return list;
}

QList<Model::Component> Component::stringListToComponents(QStringList list)
{
    QList<Model::Component> components;
    foreach (QString id, list) {
        Model::Component component = getById(id.toInt());
        components.append(component);
    }

    return components;
}

}
