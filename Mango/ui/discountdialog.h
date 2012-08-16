#ifndef DISCOUNTDIALOG_H
#define DISCOUNTDIALOG_H

#include <QDialog>
#include "../../MangoModel/ordertype.h"

class QLCDNumber;
class QComboBox;

class DiscountDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DiscountDialog(int totalCashBeforeDiscount, QWidget *parent = 0);

    int discount() const;
    Model::OrderType::OrderTypes orderType() const;

public slots:
    
private:
    void setupUi();
    Model::OrderType::OrderTypes m_orderType;
    int m_totalCashBeforeDiscount;
    int m_totalCashAfterDiscount;
    int m_discount;

    QLCDNumber* cashBeforeLCDNumber;
    QLCDNumber* cashAfterLCDNumber;
    QComboBox* discountComboBox;
};

#endif // DISCOUNTDIALOG_H
