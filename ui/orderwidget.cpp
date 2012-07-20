#include <QtDeclarative/QDeclarativeView>
#include <QVBoxLayout>
#include <QUrl>
#include <QGroupBox>
#include <QPushButton>

#include "orderwidget.h"

OrderWidget::OrderWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedWidth(420);
    this->setObjectName("orderWidget");

    layout = new QVBoxLayout(this);

    initOrderList();
    initOrderCommand();
}

void OrderWidget::initOrderList()
{
    m_declarativeView = new QDeclarativeView;
    m_declarativeView->setSource(QUrl("qrc:/ui/qml/orderlist.qml"));
    m_declarativeView->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    QGroupBox* box = new QGroupBox;
    box->setTitle("Shopping Cart");

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(m_declarativeView);

    box->setLayout(upperLayout);
    layout->addWidget(box);
}

void OrderWidget::initOrderCommand()
{
    QHBoxLayout* lowerLayout = new QHBoxLayout;
    QGroupBox* box = new QGroupBox;
    box->setTitle("Order Command");

    QHBoxLayout* contentLayout = new QHBoxLayout;

    QPushButton* applyButton = new QPushButton;
    QPushButton* cancelButton = new QPushButton;

    contentLayout->addWidget(applyButton);
    contentLayout->addWidget(cancelButton);

    box->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);

    box->setLayout(contentLayout);
    lowerLayout->addWidget(box);

    layout->addLayout(lowerLayout);
}
