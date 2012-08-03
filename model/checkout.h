#ifndef MODEL_CHECKOUT_H
#define MODEL_CHECKOUT_H

#include <QDateTime>

namespace Model {

class Checkout
{
public:
    Checkout();
    Checkout(int id, QDateTime createdDateTime);

    int id() const;
    QDateTime createdDateTime() const;

    void setCreatedDateTime(QDateTime createdDateTime);

private:
    int m_id;
    QDateTime m_createdDateTime;
};

}

#endif // MODEL_CHECKOUT_H
