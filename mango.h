#ifndef MANGO_H
#define MANGO_H

#include <vector>
#include <string>

namespace Mango {

class Category {
public:
    Category(int aId, const std::string& aArabicName, const std::string& aEnglishName);
    int getId() const { return this->id; }
    std::string getArabicName() const { return this->arabicName; }
    std::string getEnglishName() const { return this->englishName; }

private:
    int id;
    std::string arabicName;
    std::string englishName;
};

class Item {
public:
    Item();

    Item(int aId, const std::string& aArabicName, const std::string& aEnglishName,
         int sizeId, int price);

    int getId() const { return this->id; }
    std::string getArabicName() const { return this->arabicName; }
    std::string getEnglishName() const { return this->englishName; }
    int getSizeId() const { return this->sizeId ;}
    int getPrice() const { return this->price; }

private:
    int id;
    std::string arabicName;
    std::string englishName;
    int sizeId;
    int price;
};

static std::vector<Category> getCategories();
static std::vector<Item> getItemsInCategory(int categoryId);
static Item getItemDetails(int itemId);
}

#endif // MANGO_H
