#include "componentprice.h"
#include "databasemanager.h"

namespace Database {

Model::ComponentPrice ComponentPrice::getById(int componentId, int sizeId) {
    DatabaseManager mgr;
    QSqlQuery query;

    Model::ComponentPrice componentPrice;

    query.prepare("SELECT * FROM component_price WHERE component_id = ? AND size_id = ?");
    query.addBindValue(componentId);
    query.addBindValue(sizeId);
    query.exec();

    while(query.next()) {
        int component_id = query.value(1).toInt();
        int size_id = query.value(2).toInt();
        int price = query.value(3).toInt();

        Model::Component component(component_id);
        Model::Size size(size_id);

        componentPrice = Model::ComponentPrice(component, size, price);
    }

    return componentPrice;
}
}
