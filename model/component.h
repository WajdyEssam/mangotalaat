#ifndef MODEL_COMPONENT_H
#define MODEL_COMPONENT_H

#include <QString>
#include "baseitem.h"

namespace Model
{

class Component : public BaseItem
{
public:
    Component(int id);
    Component(int id, const QString& arabicName, const QString& englishName);
};

}

#endif // MODEL_COMPONENT_H
