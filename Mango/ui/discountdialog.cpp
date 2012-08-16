#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

#include <cmath>

#include "discountdialog.h"
#include "keypaddialog.h"

#include "../../MangoService/ordertype.h"

DiscountDialog::DiscountDialog(int totalCashBeforeDiscount, QWidget *parent) :
    QDialog(parent), m_totalCashBeforeDiscount(totalCashBeforeDiscount),
    m_discount(0)
{
    setupUi();

    cashBeforeDiscountLCDNumber->display(m_totalCashBeforeDiscount);
    cashAfterDiscountLCDNumber->display(m_totalCashBeforeDiscount - m_discount);
    discountComboBox->setCurrentIndex(0);

    this->setWindowTitle(tr("الخصم"));
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
    QLabel* discountLabel = new QLabel(tr("الخصم"));

    cashBeforeDiscountLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    cashAfterDiscountLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    discountTypeLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    discountLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    cashBeforeDiscountLCDNumber = new QLCDNumber;
    cashAfterDiscountLCDNumber = new QLCDNumber;
    discountLCDNumber = new QLCDNumber;

    discountButton = new QPushButton("+");
    connect(discountButton, SIGNAL(clicked()), SLOT(openKeypadDialog()));

    discountComboBox = new QComboBox;
    connect(discountComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeWidget(int)));

    cashBeforeDiscountLCDNumber->setMinimumHeight(60);
    cashAfterDiscountLCDNumber->setMinimumHeight(60);
    discountLCDNumber->setMinimumHeight(60);
    discountComboBox->setMinimumWidth(100);

    // Get all order types
    foreach (Model::OrderType orderType, Services::OrderType::getAll()) {
        // Remove CASH and COBON from list
        if (orderType.id() == Model::OrderType::CASH || orderType.id() == Model::OrderType::CUPON)
            continue;
        discountComboBox->addItem(orderType.arabicName(), orderType.id());
    }

    QGridLayout* upperGridLayout = new QGridLayout;
    upperGridLayout->addWidget(cashBeforeDiscountLabel, 0, 0);
    upperGridLayout->addWidget(cashBeforeDiscountLCDNumber, 0, 1);

    upperGridLayout->addWidget(cashAfterDiscountLabel, 1, 0);
    upperGridLayout->addWidget(cashAfterDiscountLCDNumber, 1, 1);

    upperGridLayout->addWidget(discountTypeLabel, 2, 0);
    upperGridLayout->addWidget(discountComboBox, 2, 1);

    upperGridLayout->addWidget(discountLabel, 3, 0);
    upperGridLayout->addWidget(discountLCDNumber, 3, 1);
    upperGridLayout->addWidget(discountButton, 3, 2);

    QPushButton* okButton = new QPushButton(tr("تنفيذ الخصم وإغلاق الطلب"));
    connect(okButton, SIGNAL(clicked()), SLOT(applyDiscount()));

    QPushButton* cancelButton = new QPushButton(tr("الغاء"));
    connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addStretch();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(upperGridLayout);
    layout->addStretch();
    layout->addLayout(buttonsLayout);

}

void DiscountDialog::changeWidget(int index)
{
    Model::OrderType::OrderTypes orderType = static_cast<Model::OrderType::OrderTypes>(discountComboBox->itemData(index).toInt());
    if (orderType == Model::OrderType::FREE) {
        discountButton->setEnabled(false);
        m_discount = m_totalCashBeforeDiscount;
        cashAfterDiscountLCDNumber->display(0);
        discountLCDNumber->display(m_discount);
    } else if (orderType == Model::OrderType::DISCOUNT_PERCENTAGE) {
        discountButton->setEnabled(true);
        m_discount = 0;
        cashAfterDiscountLCDNumber->display(m_totalCashBeforeDiscount);
        discountLCDNumber->display(m_discount);
    } else if (orderType == Model::OrderType::DISCOUNT_VALUE) {
        discountButton->setEnabled(true);
        m_discount = 0;
        cashAfterDiscountLCDNumber->display(m_totalCashBeforeDiscount);
        discountLCDNumber->display(m_discount);
    }
}

void DiscountDialog::openKeypadDialog()
{
    KeypadDialog keypadDialog;
    keypadDialog.setValue(0);
    if (keypadDialog.exec() == QDialog::Accepted) {

        if (static_cast<Model::OrderType::OrderTypes>(discountComboBox->itemData(discountComboBox->currentIndex()).toInt()) == Model::OrderType::DISCOUNT_PERCENTAGE) {
            // Calc percentage
            int value = keypadDialog.value() > 100 ? 100 : keypadDialog.value();
            double percentage = (value * m_totalCashBeforeDiscount) / 100;
            m_discount = floor(percentage + 0.5);

        } else {
            m_discount = keypadDialog.value() > m_totalCashBeforeDiscount ? m_totalCashBeforeDiscount : keypadDialog.value();
        }

        discountLCDNumber->display(QString::number(m_discount));
        cashAfterDiscountLCDNumber->display(m_totalCashBeforeDiscount - m_discount);
    }
}

void DiscountDialog::applyDiscount()
{
    QMessageBox::StandardButton button = QMessageBox::information(this, "تنفيذ الخصم واغلاق الطلب", "هل أنت متأكد من تنفيذ الخصم وإغلاق الطلب وطباعة الفاتورة؟?",
                                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (button == QMessageBox::No)
        return;

    this->accept();
}
