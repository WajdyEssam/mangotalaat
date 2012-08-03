#include "additional.h"

namespace Model
{

Additional::Additional(int id) :
    BaseItem(id)
{}

Additional::Additional(int id, int price, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName), m_price(price)
{}

int Additional::price() const
{
    return m_price;
}

void Additional::setPrice(int price)
{
    m_price = price;
}

}
