#include "itemdetail.h"
#include "database/itemdetail.h"
#include "services/item.h"
#include "services/size.h"

namespace Services {

Model::ItemDetail ItemDetail::getById(int id)
{
    Model::ItemDetail itemDetail = Database::ItemDetail::getById(id);
    itemDetail.setItem(Services::Item::getById(itemDetail.item().id()));
    itemDetail.setSize(Services::Size::getById(itemDetail.size().id()));
    return itemDetail;
}

QList<Model::ItemDetail> ItemDetail::getByItemId(int itemId)
{
    QList<Model::ItemDetail> itemDetails = Database::ItemDetail::getByItemId(itemId);
    for (QList<Model::ItemDetail>::iterator i = itemDetails.begin(); i != itemDetails.end(); ++i) {
        i->setItem(Services::Item::getById(i->item().id()));
        i->setSize(Services::Size::getById(i->size().id()));
    }

    return itemDetails;
}

}
