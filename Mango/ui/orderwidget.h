#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>

#include "../MangoModel/orderdetail.h"

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
    void updateOrderDetails(QList<Model::OrderDetail>);

private:
    void initOrderList();
    void initOrderCommand();

    QVBoxLayout* layout;
    QDeclarativeView* m_declarativeView;
};


#endif // ORDERWIDGET_H
