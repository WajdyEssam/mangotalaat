#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>


class QDeclarativeView;
class QVBoxLayout;

class OrderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrderWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void initOrderList();
    void initOrderCommand();

    QVBoxLayout* layout;
    QDeclarativeView* m_declarativeView;
};

#endif // ORDERWIDGET_H
