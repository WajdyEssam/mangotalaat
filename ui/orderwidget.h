#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>

class OrderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrderWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void init();
};

#endif // ORDERWIDGET_H
