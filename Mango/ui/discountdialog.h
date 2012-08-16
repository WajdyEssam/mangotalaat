#ifndef DISCOUNTDIALOG_H
#define DISCOUNTDIALOG_H

#include <QDialog>
#include "../../MangoModel/ordertype.h"

class QLCDNumber;
class QComboBox;
class QPushButton;

class DiscountDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DiscountDialog(int totalCashBeforeDiscount, QWidget *parent = 0);

    int discount() const;
    Model::OrderType::OrderTypes orderType() const;

public slots:
    void changeWidget(int);
    void openKeypadDialog();
    void applyDiscount();

private:
    void setupUi();
    Model::OrderType::OrderTypes m_orderType;
    int m_totalCashBeforeDiscount;
    int m_discount;

    QLCDNumber* cashBeforeDiscountLCDNumber;
    QLCDNumber* cashAfterDiscountLCDNumber;
    QLCDNumber* discountLCDNumber;
    QComboBox* discountComboBox;
    QPushButton* discountButton;
};

#endif // DISCOUNTDIALOG_H
