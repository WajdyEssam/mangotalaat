#ifndef ORDEROBJECT_H
#define ORDEROBJECT_H

#include <QObject>
#include "MangoModel_global.h"

class MANGOMODELSHARED_EXPORT OrderObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int orderId READ orderId CONSTANT)
    Q_PROPERTY(QString orderIndexId READ orderIndexId CONSTANT)
    Q_PROPERTY(QString orderName READ orderName CONSTANT)
    Q_PROPERTY(QString orderDescription READ orderDescription CONSTANT)
    Q_PROPERTY(QString orderCost READ orderCost CONSTANT)
    Q_PROPERTY(int orderCategory READ orderCategory CONSTANT)

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
