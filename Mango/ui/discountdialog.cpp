#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

#include "discountdialog.h"
#include "../../MangoService/ordertype.h"

DiscountDialog::DiscountDialog(int totalCashBeforeDiscount, QWidget *parent) :
    QDialog(parent), m_totalCashBeforeDiscount(totalCashBeforeDiscount), m_totalCashAfterDiscount(totalCashBeforeDiscount),
    m_discount(0)
{
    setupUi();
}

int DiscountDialog::discount() const
{
    return m_discount;
}

Model::OrderType::OrderTypes DiscountDialog::orderType() const
{
    return static_cast<Model::OrderType::OrderTypes>(discountComboBox->itemData(discountComboBox->currentIndex()).toInt());
}

void DiscountDialog::setupUi()
{
    QLabel* cashBeforeDiscountLabel = new QLabel(tr("الإجمالي قبل الخصم"));
    QLabel* cashAfterDiscountLabel = new QLabel(tr("الإجمالي بعد الخصم"));
    QLabel* discountTypeLabel = new QLabel(tr("نوع الخصم"));

    cashBeforeLCDNumber = new QLCDNumber;
    cashAfterLCDNumber = new QLCDNumber;

    discountComboBox = new QComboBox;

    // Get all order types
    foreach (Model::OrderType orderType, Services::OrderType::getAll()) {
        // Remove CASH and COBON from list
        if (orderType.id() == Model::OrderType::CASH || orderType.id() == Model::OrderType::CUPON)
            continue;
        discountComboBox->addItem(orderType.arabicName(), orderType.id());
    }

    discountComboBox->setCurrentIndex(0);

    QPushButton* okButton = new QPushButton(tr("موافق"));
    QPushButton* cancelButton = new QPushButton(tr("الغاء"));

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addStretch();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(discountComboBox);
    layout->addLayout(buttonsLayout);

}
