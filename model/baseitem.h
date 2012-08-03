#ifndef MODEL_BASEITEM_H
#define MODEL_BASEITEM_H

#include <QString>

namespace Model {

class BaseItem
{

public:
    BaseItem(int id);
    BaseItem(int id, const QString& arabicName, const QString& englishName);
    virtual ~BaseItem() = 0;

    int id() const;
    QString arabicName() const;
    QString englishName() const;

    void setId(int id);
    void setArabicName(QString arabicName);
    void setEnglishName(QString englishName);

private:
    int m_id;
    QString m_arabicName;
    QString m_englishName;
};

}

#endif // MODEL_BASEITEM_H
