#include "itemdetail.h"

namespace Model {

ItemDetail::ItemDetail()
{}

ItemDetail::ItemDetail(int id, Model::Item item, Model::Size size, int price) :
    m_id(id), m_item(item), m_size(size), m_price(price)
{}

void ItemDetail::setItem(Item item)
{
    m_item = item;
}

void ItemDetail::setSize(Size size)
{
    m_size = size;
}

int ItemDetail::id() const
{
    return m_id;
}

Model::Item ItemDetail::item() const
{
    return m_item;
}

Model::Size ItemDetail::size() const
{
    return m_size ;
}

int ItemDetail::price() const
{
    return m_price;
}

}
