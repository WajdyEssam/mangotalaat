#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

namespace Model
{
    class Category
    {
    public:
        Category(int aId, const QString& aArabicName, const QString& aEnglishName);
        int getId() const { return this->id; }
        QString getArabicName() const { return this->arabicName; }
        QString getEnglishName() const { return this->englishName; }
    private:
        int id;
        QString arabicName;
        QString englishName;
    };
}

#endif // CATEGORY_H
