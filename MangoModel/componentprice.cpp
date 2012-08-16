#include "componentprice.h"

namespace Model {
ComponentPrice::ComponentPrice()
    :m_component(0), m_size(0), m_price(0)
{
}

ComponentPrice::ComponentPrice(Model::Component component, Model::Size size, int price)
    :m_component(component), m_size(size), m_price(price)
{
}

Model::Component ComponentPrice::component() const
{
    return m_component;
}

Model::Size ComponentPrice::size() const
{
    return m_size;
}

int ComponentPrice::price() const
{
    return m_price;
}

void ComponentPrice::setComponent(Model::Component components)
{
    this->m_component = components;
}

void ComponentPrice::setSize(Model::Size size)
{
    this->m_size = size;
}

}
