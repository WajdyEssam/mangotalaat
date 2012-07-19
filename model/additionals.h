#ifndef ADDITIONALS_H
#define ADDITIONALS_H

#include <QString>

namespace Model {
    class Additionals
    {
    public:
        Additionals() {}
        Additionals(int aId, const QString& aArabicName, const QString& aEnglishName, int aPrice);

        int getId() const { return this->id; }
        QString getArabicName() const { return this->arabicName; }
        QString getEnglishName() const { return this->englishName; }
        int getPrice() const { return this->price; }

    private:
        int id;
        QString arabicName;
        QString englishName;
        int price;
    };
}

#endif // ADDITIONALS_H
