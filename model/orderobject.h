#ifndef ORDEROBJECT_H
#define ORDEROBJECT_H

#include <QObject>

class OrderObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int orderId READ orderId)
    Q_PROPERTY(QString orderIndexId READ orderIndexId)
    Q_PROPERTY(QString orderName READ orderName)
    Q_PROPERTY(QString orderDescription READ orderDescription)
    Q_PROPERTY(QString orderCost READ orderCost)
    Q_PROPERTY(int orderCategory READ orderCategory)

public:
    explicit OrderObject(QObject *parent = 0);
    explicit OrderObject(int orderId, QString orderIndexId, QString name, QString description, QString cost, int orderCategory, QObject *parent = 0);

    int orderId();
    QString orderIndexId();
    QString orderName();
    QString orderDescription();
    QString orderCost();
    int orderCategory();

signals:
    
public slots:

private:
    int m_orderId;
    QString m_orderIndexId;
    QString m_orderName;
    QString m_orderDescription;
    QString m_orderCost;
    int m_orderCategory;
};

#endif // ORDEROBJECT_H
