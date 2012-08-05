#include "category.h"

namespace Model
{

Category::Category(int id) :
    BaseItem(id)
{}

Category::Category(int id, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName)
{}

}
