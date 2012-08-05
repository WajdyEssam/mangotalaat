#include "itemcomponent.h"

namespace Model {

ItemComponent::ItemComponent(int id) :
    m_id(id),m_item(0), m_component(0)
{}

ItemComponent::ItemComponent(int id, Model::Item item, Model::Component component) :
    m_id(id), m_item(item), m_component(component)
{}

int ItemComponent::id() const
{
    return m_id;
}

Model::Item ItemComponent::item() const
{
    return m_item;
}

Model::Component ItemComponent::component() const
{
    return m_component;
}

void ItemComponent::setItem(Item item)
{
    m_item = item;
}

void ItemComponent::setComponent(Component component)
{
    m_component = component;
}

}
