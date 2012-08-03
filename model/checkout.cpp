#include "checkout.h"

namespace Model {

Checkout::Checkout()
{}

Checkout::Checkout(int id, QDateTime createdDateTime) :
    m_id(id), m_createdDateTime(createdDateTime)
{}

int Checkout::id() const
{
    return m_id;
}

QDateTime Checkout::createdDateTime() const
{
    return m_createdDateTime;
}

void Checkout::setCreatedDateTime(QDateTime createdDateTime)
{
    m_createdDateTime = createdDateTime;
}

}
