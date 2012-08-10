#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QDebug>
#include <QMessageBox>
#include <QLCDNumber>

#include "propertywidget.h"
#include "toolbutton.h"
#include "keypaddialog.h"
#include "../../MangoModel/component.h"
#include "../../MangoModel/additional.h"
#include "../../MangoModel/category.h"
#include "../../MangoModel/itemdetail.h"
#include "../../MangoModel/itemcomponent.h"
#include "../../MangoService/component.h"
#include "../../MangoService/additional.h"
#include "../../MangoService/itemdetail.h"
#include "../../MangoService/itemcomponent.h"

PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent), m_orderDetail(0)
{
    this->setObjectName("propertyWidget");
    this->componentSignalMapper = new QSignalMapper(this);
    this->additionalSignalMapper = new QSignalMapper(this);

    orderGroupBox = new QGroupBox(tr("Order"));
    componentsGroupBox = new QGroupBox(tr("Components"));
    additionalsGroupBox = new QGroupBox(tr("Additionals"));

    commandButtonVBoxLayout = new QVBoxLayout;

    orderDetailVBoxLayout = new QVBoxLayout;
    orderDetailVBoxLayout->setSizeConstraint(QGridLayout::SetMinAndMaxSize);

    componentsGridLayout = new QGridLayout;
    additionalsGridLayout = new QGridLayout;
//    additionalsGridLayout->setSizeConstraint(QGridLayout::SetMinAndMaxSize);

    orderGroupBox->setLayout(orderDetailVBoxLayout);
    componentsGroupBox->setLayout(componentsGridLayout);
    additionalsGroupBox->setLayout(additionalsGridLayout);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(commandButtonVBoxLayout);
    leftLayout->addWidget(componentsGroupBox);
    leftLayout->addWidget(additionalsGroupBox);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(orderGroupBox);
    this->setLayout(layout);

    connect(this->componentSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentComponent(int)));
    connect(this->additionalSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentAdditional(int)));

    this->initOrder();
    this->initCommandButtons();
    this->initComponents();
    this->initAdditionals();
}

void PropertyWidget::initCommandButtons()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    addButton = new QPushButton;
    addButton->setFixedSize(161,56);
    addButton->setStyleSheet("border-width: 4px; border-image: url(:/images/buttons/add_cart_button.png) 4 4 4 4 stretch stretch; width: 177px; height: 55px;");
    connect(addButton, SIGNAL(clicked()), this, SLOT(addItemClicked()));

    updateButton = new QPushButton;
    updateButton->setFixedSize(161,56);
    updateButton->setStyleSheet("border-width: 4px; border-image: url(:/images/buttons/update_cart_button.png) 4 4 4 4 stretch stretch; width: 177px; height: 55px;");
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateItemClicked()));

    removeButton = new QPushButton;
    removeButton->setFixedSize(161,56);
    removeButton->setStyleSheet("border-width: 4px; border-image: url(:/images/buttons/remove_cart_button.png) 4 4 4 4 stretch stretch; width: 177px; height: 55px;");
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeItemClicked()));

    layout->addWidget(addButton);
    layout->addWidget(updateButton);
    layout->addWidget(removeButton);
    orderDetailVBoxLayout->addLayout(layout);
}

void PropertyWidget::initOrder()
{
    itemNameLineEdit = new QLabel;
    itemSizeLineEdit = new QLabel;
    itemComponentsLineEdit = new QLabel;
    itemAdditionalsLineEdit = new QLabel;


    QFormLayout* leftLayout = new QFormLayout;
    leftLayout->addRow(tr("Item"), itemNameLineEdit);
    leftLayout->addRow(tr("Size"), itemSizeLineEdit);
    leftLayout->addRow(tr("Components"), itemComponentsLineEdit);
    leftLayout->addRow(tr("Additionals"), itemAdditionalsLineEdit);

    QLabel* itemQuantityLabel = new QLabel(tr("Quantity"));
    itemQuantityLCDNumber = new QLCDNumber;
    QPushButton* quantityButton = new QPushButton("+");
    connect(quantityButton, SIGNAL(clicked()), SLOT(openKeypadDialog()));

    QLabel* itemPriceLabel = new QLabel(tr("Item Price"));
    itemPriceLCDNumber = new QLCDNumber;


    QLabel* totalPriceLabel = new QLabel(tr("Total Price"));
    totalPriceLCDNumber = new QLCDNumber;

    QLabel* itemSugarLabel = new QLabel(tr("Sugar"));
    itemSugarLCDNumber = new QLCDNumber;
    QPushButton* sugarButton = new QPushButton("+");

    QGridLayout* rightLayout = new QGridLayout;
    rightLayout->addWidget(itemQuantityLabel, 0, 0);
    rightLayout->addWidget(itemQuantityLCDNumber, 0, 1);
    rightLayout->addWidget(quantityButton, 0, 2);

    rightLayout->addWidget(itemSugarLabel, 1, 0);
    rightLayout->addWidget(itemSugarLCDNumber, 1, 1);
    rightLayout->addWidget(sugarButton, 1, 2);

    rightLayout->addWidget(itemPriceLabel, 2, 0);
    rightLayout->addWidget(itemPriceLCDNumber, 2, 1);

    rightLayout->addWidget(totalPriceLabel, 3, 0);
    rightLayout->addWidget(totalPriceLCDNumber, 3, 1);

    orderDetailVBoxLayout->addLayout(rightLayout);
    orderDetailVBoxLayout->addStretch();
}

void PropertyWidget::initComponents()
{
    // get all Components
    QList<Model::Component> components = Services::Component::getAll();

    int i=0, col = 0, row = 1;

    for(QList<Model::Component>::iterator p= components.begin();
            p != components.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_ComponentButton").arg(p->id()));
        button->setText(p->arabicName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(p->id())));
        button->setIconSize(QSize(64,64));
        button->setFont(QFont("Droid Arabic Naskh", 10, QFont::Bold));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->arabicName());
        button->setStatusTip(p->arabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), componentSignalMapper, SLOT(map()));
        this->componentSignalMapper->setMapping(button, p->id());
        componentsGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void PropertyWidget::initAdditionals()
{
    // get all dditionals
    QList<Model::Additional> additionals = Services::Additional::getAll();

    int i=0, col = 0, row = 1;

    for(QList<Model::Additional>::iterator p= additionals.begin();
            p != additionals.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_AdditionalsButton").arg(p->id()));
        button->setText(p->arabicName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/additionals/additional_notactive_%1.png").arg(p->id())));
        button->setIconSize(QSize(64,64));
        button->setFont(QFont("Droid Arabic Naskh", 10, QFont::Bold));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->arabicName());
        button->setStatusTip(p->arabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), additionalSignalMapper, SLOT(map()));
        this->additionalSignalMapper->setMapping(button, p->id());
        additionalsGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void PropertyWidget::setOrder(Model::OrderDetail orderDetail, bool isOpenedInEditMode)
{
    this->uncheckComponentsButtons();
    this->uncheckAdditionalsButtons();

    if (isOpenedInEditMode)
        showEditButton();
    else
        showAddButton();

    m_orderDetail = orderDetail;

    this->recheckComponentsButtons();
    this->recheckAdditionalsButtons();

    int categoryId = m_orderDetail.itemDetail().item().category().id();
    if ( categoryId != Model::Category::Cocktails && categoryId != Model::Category::Speical_Cocktial ) {
        this->componentsGroupBox->setVisible(false);
    } else {
        this->componentsGroupBox->setVisible(true);
    }

    itemNameLineEdit->setText(m_orderDetail.itemDetail().item().arabicName());
    itemQuantityLCDNumber->display(QString::number(m_orderDetail.qunatity()));
    itemSizeLineEdit->setText(m_orderDetail.itemDetail().size().arabicName());
    itemPriceLCDNumber->display(QString::number(m_orderDetail.itemDetail().price()));
    itemSugarLCDNumber->display(QString::number(m_orderDetail.sugar()));

    // Fill after set active components and additionals
    this->fillItemDetialsLineEdit();
}

void PropertyWidget::setCurrentComponent(int id)
{
    QString buttonName = QString::number(id) + "_ComponentButton";
    ToolButton* button = this->findChild<ToolButton*>(buttonName);

    if (button->activeState() == ToolButton::Active) {
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(id)));
    } else {
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/components/component_active_%1.png").arg(id)));
    }

    fillItemDetialsLineEdit();
}

void PropertyWidget::setCurrentAdditional(int id)
{
    QString buttonName = QString::number(id) + "_AdditionalsButton";
    ToolButton* button = this->findChild<ToolButton*>(buttonName);

    if (button->activeState() == ToolButton::Active) {
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/additionals/additional_notactive_%1.png").arg(id)));
    } else {
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/additionals/additional_active_%1.png").arg(id)));
    }

    fillItemDetialsLineEdit();
}

void PropertyWidget::addItemClicked()
{
    if ((int)itemQuantityLCDNumber->value() <= 0) {
        QMessageBox::warning(this, tr("Operation faild"), tr("Please enter the quantity"));
        return ;
    }

    m_orderDetail.setComponent(readActiveComponents());
    m_orderDetail.setAdditionals(readActiveAdditionals());
    m_orderDetail.setSugar(this->readSugar());
    m_orderDetail.setQuantity(this->readQunatity());
    m_orderDetail.setCash((int)totalPriceLCDNumber->value());

    emit addItem(m_orderDetail);
}

void PropertyWidget::updateItemClicked()
{
//    int itemDetailId = m_orderDetail.itemDetail().id();
//    QStringList components = readActiveComponents();
//    QStringList additionals = readActiveAdditionals();
//    int sugar = readSugar();
//    int quantity = readQunatity();
//    QString orderIndexId = this->m_orderDetail.orderIndexId();

    //Model::OrderDetail orderDetail(itemDetailId, quantity, components, additionals, sugar, orderIndexId);

    m_orderDetail.setComponent(readActiveComponents());
    m_orderDetail.setAdditionals(readActiveAdditionals());
    m_orderDetail.setSugar(this->readSugar());
    m_orderDetail.setQuantity(this->readQunatity());
    m_orderDetail.setCash((int)totalPriceLCDNumber->value());

    emit updateItem(m_orderDetail);
}

void PropertyWidget::removeItemClicked()
{
    emit removeItem(m_orderDetail);
}

void PropertyWidget::uncheckComponentsButtons()
{
    QList<ToolButton*> buttons = this->componentsGroupBox->findChildren<ToolButton*>();

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            button->setActiveState(ToolButton::NotActive);
            button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(id)));
        }
    }
}

void PropertyWidget::uncheckAdditionalsButtons()
{
    QList<ToolButton*> buttons = this->additionalsGroupBox->findChildren<ToolButton*>();

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            button->setActiveState(ToolButton::NotActive);
            button->setIcon(QIcon(QString(":/images/additionals/additional_notactive_%1.png").arg(id)));
        }
    }
}

void PropertyWidget::clearItemDetailsLineEdit()
{
    itemNameLineEdit->clear();
    itemQuantityLCDNumber->display(0);
    itemSizeLineEdit->clear();
    itemPriceLCDNumber->display(0);
    itemSugarLCDNumber->display(0);
    itemComponentsLineEdit->clear();
    itemAdditionalsLineEdit->clear();
    totalPriceLCDNumber->display(0);
}

void PropertyWidget::recheckComponentsButtons()
{
    foreach(Model::Component component, m_orderDetail.components()) {
        int id = component.id();
        QString buttonName = QString::number(id) + "_ComponentButton";
        ToolButton* button = this->findChild<ToolButton*>(buttonName);
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/components/component_active_%1.png").arg(id)));
    }
}

void PropertyWidget::recheckAdditionalsButtons()
{
    foreach(Model::Additional additional, m_orderDetail.additionals()) {
        int id = additional.id();
        QString buttonName = QString::number(id) + "_AdditionalsButton";
        ToolButton* button = this->findChild<ToolButton*>(buttonName);
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/additionals/additional_active_%1.png").arg(id)));
    }
}

void PropertyWidget::fillItemDetialsLineEdit()
{
    QStringList components;
    foreach (Model::Component c, readActiveComponents()) {
        Model::Component component = Services::Component::getById(c.id());
        components.append(component.arabicName());
    }

    QStringList additionals;
    foreach (Model::Additional a, readActiveAdditionals()) {
        Model::Additional additional = Services::Additional::getById(a.id());
        additionals.append(additional.arabicName());
    }

    itemComponentsLineEdit->setText(components.join(" , "));
    itemAdditionalsLineEdit->setText(additionals.join(" , "));

    // Calculate total price
    calculateTotalPrice();
}

void PropertyWidget::showEditButton()
{
    addButton->setVisible(false);
    updateButton->setVisible(true);
    removeButton->setVisible(true);
}

void PropertyWidget::showAddButton()
{
    addButton->setVisible(true);
    updateButton->setVisible(false);
    removeButton->setVisible(false);
}

QList<Model::Component> PropertyWidget::readActiveComponents()
{
    QList<ToolButton*> buttons = this->componentsGroupBox->findChildren<ToolButton*>();
    QList<Model::Component> components;

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            Model::Component c(id);
            components.append(c);
        }
    }

    return components;
}

QList<Model::Additional> PropertyWidget::readActiveAdditionals()
{
    QList<ToolButton*> buttons = this->additionalsGroupBox->findChildren<ToolButton*>();
    QList<Model::Additional> additionals;

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            Model::Additional a(id);
            additionals.append(a);
        }
    }

    return additionals;
}

int PropertyWidget::readSugar()
{
    return (int)itemSugarLCDNumber->value();
}

int PropertyWidget::readQunatity()
{
    return (int)itemQuantityLCDNumber->value();
}


void PropertyWidget::openKeypadDialog()
{
    KeypadDialog keypadDialog;
    keypadDialog.setValue((int)itemQuantityLCDNumber->value());
    if (keypadDialog.exec() == QDialog::Accepted) {
        itemQuantityLCDNumber->display(QString::number(keypadDialog.value()));
        calculateTotalPrice();
    }
}

void PropertyWidget::calculateTotalPrice()
{
    int quantity = (int)itemQuantityLCDNumber->value();
    //int componentsCount = readActiveComponents().count();
    int addtionalCount = readActiveAdditionals().count();
    int itemPrice = (int)itemPriceLCDNumber->value();
    int totalPrice = itemPrice * quantity;
    //totalPrice = totalPrice + (componentsCount * 1);
    totalPrice = totalPrice + (addtionalCount * 1);

    totalPriceLCDNumber->display(QString::number(totalPrice));
}
