#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>

#include "model/order.h"

class QDeclarativeView;
class QVBoxLayout;

class OrderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrderWidget(QWidget *parent = 0);
    
signals:
    void orderItemClick(QString);
    void applyClicked();
    void cancelClicked();

public slots:
    void updateOrders(QList<Model::Order>);

private:
    void initOrderList();
    void initOrderCommand();

    QVBoxLayout* layout;
    QDeclarativeView* m_declarativeView;
};


#endif // ORDERWIDGET_H
