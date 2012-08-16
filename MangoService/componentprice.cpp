#include "componentprice.h"

#include "../MangoDatabase/componentprice.h"
#include "../MangoService/component.h"
#include "../MangoService/size.h"

namespace Services {

Model::ComponentPrice ComponentPrice::getById(int componentId, int sizeId) {
    Model::ComponentPrice price = Database::ComponentPrice::getById(componentId, sizeId);
    price.setComponent(Services::Component::getById(price.component().id()));
    price.setSize(Services::Size::getById(price.size().id()));

    return price;
}

}
