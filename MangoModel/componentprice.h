#ifndef MODEL_COMPONENTPRICE_H
#define MODEL_COMPONENTPRICE_H

#include "MangoModel_global.h"
#include "component.h"
#include "size.h"

namespace Model {

class MANGOMODELSHARED_EXPORT ComponentPrice
{
public:
    ComponentPrice();
    ComponentPrice(Model::Component component, Model::Size size, int price);

    Model::Component component() const;
    Model::Size size() const;
    int price() const;

    void setComponent(Model::Component components);
    void setSize(Model::Size size);

private:
    Model::Component m_component;
    Model::Size m_size;
    int m_price;
};

}

#endif // COMPONENTPRICE_H
