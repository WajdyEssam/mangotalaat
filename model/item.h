#ifndef MODEL_ITEM_H
#define MODEL_ITEM_H

#include <QString>
#include "baseitem.h"
#include "category.h"

namespace Model
{

class Item : public BaseItem
{
public:
    Item(int id);
    Item(int id, Model::Category category, const QString& arabicName, const QString& englishName);

    void setCategory(Model::Category category);
    Model::Category category() const { return m_category; }

private:
    Model::Category m_category;
};

}
#endif // MODEL_ITEM_H
