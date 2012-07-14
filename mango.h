#ifndef MANGO_H
#define MANGO_H

#include <vector>
#include <string>
#include <QtSql/QtSql>
#include <QDebug>

namespace Mango {

class Category {
public:
    Category(int aId, const std::string& aArabicName, const std::string& aEnglishName) {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
    }

    int getId() const { return this->id; }
    std::string getArabicName() const { return this->arabicName; }
    std::string getEnglishName() const { return this->englishName; }

private:
    int id;
    std::string arabicName;
    std::string englishName;
};

class Component {
public:
    Component() {

    }

    Component(int aId, const std::string& aArabicName, const std::string& aEnglishName) {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
    }

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
    Item() {

    }

    Item(int aId, const std::string& aArabicName, const std::string& aEnglishName,
         int aCategoryId, int aSizeId, int aPrice) {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
        this->categoryId = aCategoryId;
        this->sizeId = aSizeId;
        this->price = aPrice;
    }

    int getId() const { return this->id; }
    std::string getArabicName() const { return this->arabicName; }
    std::string getEnglishName() const { return this->englishName; }
    int getCategoryId() const { return this->categoryId; }
    int getSizeId() const { return this->sizeId ;}
    int getPrice() const { return this->price; }

private:
    int id;
    std::string arabicName;
    std::string englishName;
    int categoryId;
    int sizeId;
    int price;
};

class DatabaseManager {
public:
    DatabaseManager() {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:\\database\\mango.db");
        database.open();
    }

    ~DatabaseManager() {
        database.close();
    }

    std::vector<Mango::Category> getCategories() {
        std::vector<Mango::Category> categories;

        QSqlQuery query("SELECT * FROM categories");
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            Mango::Category category(id, arabicName.toStdString(), englishName.toStdString());
            categories.push_back(category);
        }

        return categories;
    }

    std::vector<Mango::Item> getItemsInCategory(int categoryId) {
        std::vector<Mango::Item> items;
        QSqlQuery query(QString("SELECT * FROM items WHERE categories_id = %1").arg(categoryId));

        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();
            int categoryId = query.value(3).toInt();
            int sizeId = query.value(4).toInt();
            int price = query.value(5).toInt();

            Mango::Item item(id, arabicName.toStdString(), englishName.toStdString(), categoryId, sizeId, price);
            items.push_back(item);
        }

        return items;
    }

    Mango::Item getItemDetails(int itemId) {
        Mango::Item item;

        QSqlQuery query(QString("SELECT * FROM items WHERE id = %1").arg(itemId));
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();
            int categoryId = query.value(3).toInt();
            int sizeId = query.value(4).toInt();
            int price = query.value(5).toInt();

            item = Mango::Item(id, arabicName.toStdString(), englishName.toStdString(), categoryId, sizeId, price);
        }

        return item;
    }

    std::vector<Mango::Component> getAllCompnents() {
        std::vector<Mango::Component> components;

        QSqlQuery query(QString("SELECT * FROM components"));
        while(query.next()){
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            Mango::Component component(id, arabicName.toStdString(), englishName.toStdString());
            components.push_back(component);
        }

        return components;
    }

    std::vector<Mango::Component> getCompnentsInItem(int itemId) {
        std::vector<Mango::Component> components;

        QSqlQuery query(QString("SELECT * FROM item_components WHERE item_id = %1").arg(itemId));
        while(query.next()){
            int componentId = query.value(2).toInt();
            components.push_back(getComponentById(componentId));
        }

        return components;
    }

    Mango::Component getComponentById(int componentId){
        Mango::Component component;

        QSqlQuery query(QString("SELECT * FROM components WHERE id = %1").arg(componentId));
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            component = Mango::Component(id, arabicName.toStdString(), englishName.toStdString());
        }

        return component;
    }

private:
    QSqlDatabase database;
};

}

#endif // MANGO_H
