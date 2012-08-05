#include "baseitem.h"

namespace Model
{

BaseItem::BaseItem(int id) :
    m_id(id)
{}

BaseItem::BaseItem(int id, const QString& arabicName, const QString& englishName) :
    m_id(id), m_arabicName(arabicName), m_englishName(englishName)
{}

BaseItem::~BaseItem()
{}

int BaseItem::id() const
{
    return this->m_id;
}

QString BaseItem::arabicName() const
{
    return this->m_arabicName;
}

QString BaseItem::englishName() const
{
    return this->m_englishName;
}

void BaseItem::setId(int id)
{
    m_id = id;
}

void BaseItem::setArabicName(QString arabicName)
{
    m_arabicName = arabicName;
}

void BaseItem::setEnglishName(QString englishName)
{
    m_englishName = englishName;
}

}
