#include "sugar.h"

namespace Model
{

Sugar::Sugar(int id) :
    BaseItem(id)
{}

Sugar::Sugar(int id, const QString& arabicName, const QString& englishName) :
    BaseItem(id, arabicName, englishName)
{}

}
