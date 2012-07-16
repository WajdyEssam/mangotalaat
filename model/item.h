#ifndef ITEM_H
#define ITEM_H

#include <QString>

namespace Model
{
    class Item
    {
    public:
        Item();
        Item(int aId, const QString& aArabicName, const QString& aEnglishName, int aCategoryId, int aSizeId, int aPrice);

        int getId() const { return this->id; }
        QString getArabicName() const { return this->arabicName; }
        QString getEnglishName() const { return this->englishName; }
        int getCategoryId() const { return this->categoryId; }
        int getSizeId() const { return this->sizeId ;}
        int getPrice() const { return this->price; }

    private:
        int id;
        QString arabicName;
        QString englishName;
        int categoryId;
        int sizeId;
        int price;
    };

}
#endif // ITEM_H
