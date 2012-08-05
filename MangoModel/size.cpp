#include "size.h"

namespace Model
{

Size::Size(int id) :
    BaseItem(id)
{}

Size::Size(int id, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName)
{}

}
