#ifndef COMPONENTPRICE_H
#define COMPONENTPRICE_H

#include "MangoModel_global.h"
#include "component.h"
#include "size.h"

namespace Model {

class MANGOMODELSHARED_EXPORT ComponentPrice
{
public:
    ComponentPrice(Model::Component component, Model::Size size, int price);

    Model::Component component() const;
    Model::Size size() const;
    int price() const;

private:
    Model::Component m_component;
    Model::Size m_size;
    int m_price;
};

}

#endif // COMPONENTPRICE_H
