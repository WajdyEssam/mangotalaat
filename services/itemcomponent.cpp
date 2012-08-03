#include "itemcomponent.h"
#include "database/itemcomponent.h"
#include "services/item.h"
#include "services/component.h"

namespace Services {

QList<Model::ItemComponent> ItemComponent::getByItemId(int itemId)
{
    QList<Model::ItemComponent> itemComponents = Database::ItemComponent::getByItemId(itemId);
    for (QList<Model::ItemComponent>::iterator i = itemComponents.begin(); i != itemComponents.end(); ++i) {
        i->setItem(Services::Item::getById(i->item().id()));
        i->setComponent(Services::Component::getById(i->component().id()));
    }
}

Model::ItemComponent ItemComponent::getById(int id)
{
    Model::ItemComponent itemComponent = Database::ItemComponent::getById(id);
    itemComponent.setItem(Services::Item::getById(itemComponent.item().id()));
    itemComponent.setComponent(Services::Component::getById(itemComponent.component().id()));
}


}
