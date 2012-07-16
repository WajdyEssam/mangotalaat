#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

namespace Model
{
    class Component
    {
    public:
        Component();
        Component(int aId, const QString& aArabicName, const QString& aEnglishName);

        int getId() const { return this->id; }
        QString getArabicName() const { return this->arabicName; }
        QString getEnglishName() const { return this->englishName; }

    private:
        int id;
        QString arabicName;
        QString englishName;
    };
}

#endif // COMPONENT_H
