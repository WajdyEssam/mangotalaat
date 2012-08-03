#include "item.h"
#include "database/item.h"
#include "services/category.h"

namespace Services {

Model::Item Item::getById(int id)
{
    Model::Item item = Database::Item::getById(id);
    item.setCategory(Services::Category::getById(item.category().id()));
    return item;
}

QList<Model::Item> Item::getByCategoryId(int categoryId)
{
    QList<Model::Item> items = Database::Item::getByCategoryId(categoryId);
    for (QList<Model::Item>::iterator i = items.begin(); i != items.end(); ++i ) {
        i->setCategory(Services::Category::getById(i->category().id()));
    }

    return items;
}

QList<Model::Item> Item::getAll()
{
    QList<Model::Item> items = Database::Item::getAll();
    for (QList<Model::Item>::iterator i = items.begin(); i != items.end(); ++i ) {
        i->setCategory(Services::Category::getById(i->category().id()));
    }

    return items;
}

}
