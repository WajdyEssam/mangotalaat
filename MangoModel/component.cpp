#include "component.h"

namespace Model
{

Component::Component(int id) :
    BaseItem(id)
{}

Component::Component(int id, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName)
{}

}
