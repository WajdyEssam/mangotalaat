#include "item.h"

namespace Model
{

Item::Item(int id) :
    BaseItem(id)
{}

Item::Item(int id, Model::Category category, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName), m_category(category)
{}

void Item::setCategory(Category category)
{
    m_category = category;
}

}
