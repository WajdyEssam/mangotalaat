#include "ordertype.h"

namespace Model {

OrderType::OrderType(int id) :
    BaseItem(id)
{}

OrderType::OrderType(int id, QString arabicName, QString englishName) :
    BaseItem(id, arabicName, englishName)
{}

}
