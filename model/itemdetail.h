#ifndef MODEL_ITEMDETAIL_H
#define MODEL_ITEMDETAIL_H

#include "model/size.h"
#include "model/item.h"

namespace Model {

class ItemDetail
{
public:
    ItemDetail();
    ItemDetail(int id, Model::Item item, Model::Size size, int price);

    int id() const;
    Model::Item item() const ;
    Model::Size size() const;
    int price() const;

    void setItem(Model::Item item);
    void setSize(Model::Size size);

private:
    int m_id;
    Model::Item m_item;
    Model::Size m_size;
    int m_price;
};

}

#endif // MODEL_ITEMDETAIL_H
