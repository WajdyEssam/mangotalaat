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
#include <QEvent>

#include "propertywidget.h"
#include "toolbutton.h"
#include "keypaddialog.h"
#include "sugardialog.h"

#include "../../MangoModel/component.h"
#include "../../MangoModel/additional.h"
#include "../../MangoModel/category.h"
#include "../../MangoModel/itemdetail.h"
#include "../../MangoModel/itemcomponent.h"
#include "../../MangoService/component.h"
#include "../../MangoService/additional.h"
#include "../../MangoService/itemdetail.h"
#include "../../MangoService/itemcomponent.h"
#include "../../MangoService/componentprice.h"
#include "../../MangoService/sugar.h"

#include "../language.h"

PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent), m_orderDetail(0)
{
    this->setObjectName("propertyWidget");
    this->componentSignalMapper = new QSignalMapper(this);
    this->additionalSignalMapper = new QSignalMapper(this);

    orderGroupBox = new QGroupBox(tr("Order Options"));
    componentsGroupBox = new QGroupBox(tr("Components"));
    additionalsGroupBox = new QGroupBox(tr("Additionals"));

    orderDetailVBoxLayout = new QVBoxLayout;

    orderControlVBoxLayout = new QVBoxLayout;
    orderControlVBoxLayout->setSizeConstraint(QGridLayout::SetMinAndMaxSize);

    componentsGridLayout = new QGridLayout;
    additionalsGridLayout = new QGridLayout;

    orderGroupBox->setLayout(orderControlVBoxLayout);
    componentsGroupBox->setLayout(componentsGridLayout);
    additionalsGroupBox->setLayout(additionalsGridLayout);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(orderDetailVBoxLayout);
    leftLayout->addWidget(componentsGroupBox);
    leftLayout->addWidget(additionalsGroupBox);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(orderGroupBox);
    this->setLayout(layout);

    connect(this->componentSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentComponent(int)));
    connect(this->additionalSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentAdditional(int)));

    this->initOrderDetailsUI();
    this->initOrderControlUI();
    this->initCommandButtonsUI();
    this->initComponentsUI();
    this->initAdditionalsUI();
}

void PropertyWidget::retransilateUi()
{
    orderGroupBox->setTitle(tr("Order Options"));
    componentsGroupBox->setTitle(tr("Components"));
    additionalsGroupBox->setTitle(tr("Additionals"));

    itemQuantityButton->setText(tr("Qunatity"));
    itemSugarButton->setText(tr("Sugar"));
    itemPriceLabel->setText(tr("Item Price"));
    totalPriceLabel->setText(tr("Total Price"));
}

void PropertyWidget::initOrderDetailsUI()
{
    itemNameLabel = new QLabel;
    itemNameLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    itemNameLabel->setStyleSheet("color: blue; font-weight: bold; font-size: 21px;");

    itemComponentsLabel = new QLabel;
    itemComponentsLabel->setWordWrap(true);
    itemComponentsLabel->setMinimumHeight(35);
    itemComponentsLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    itemAdditionalsLabel = new QLabel;
    itemAdditionalsLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(itemNameLabel);
    layout->addWidget(itemComponentsLabel);
    layout->addWidget(itemAdditionalsLabel);

    orderDetailVBoxLayout->addLayout(layout);
}


void PropertyWidget::initCommandButtonsUI()
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
    orderControlVBoxLayout->addLayout(layout);
}

void PropertyWidget::initOrderControlUI()
{
    itemQuantityButton = new QPushButton(tr("Qunatity"));
    connect(itemQuantityButton, SIGNAL(clicked()), SLOT(openKeypadDialog()));

    itemQuantityLCDNumber = new QLCDNumber;

    itemPriceLabel = new QLabel(tr("Item Price"));
    itemPriceLCDNumber = new QLCDNumber;
    itemPriceLCDNumber->setFixedSize(70, 70);

    totalPriceLabel = new QLabel(tr("Total Price"));
    totalPriceLCDNumber = new QLCDNumber;
    totalPriceLCDNumber->setFixedSize(70, 70);
    totalPriceLCDNumber->setStyleSheet("color: red");
    totalPriceLCDNumber->setSegmentStyle(QLCDNumber::Filled);

    itemSugarButton = new QPushButton(tr("Sugar"));
    connect(itemSugarButton, SIGNAL(clicked()), SLOT(openSugarDialog()));

    itemSugarLCDNumber = new QLCDNumber;

    QGridLayout* rightLayout = new QGridLayout;
    rightLayout->addWidget(itemQuantityButton, 0, 0);
    rightLayout->addWidget(itemQuantityLCDNumber, 0, 1, 2, 1);

    rightLayout->addWidget(itemSugarButton, 2, 0);
    rightLayout->addWidget(itemSugarLCDNumber, 2, 1, 2, 1);

    rightLayout->addWidget(itemPriceLabel, 4, 0);
    rightLayout->addWidget(itemPriceLCDNumber, 4, 1);

    rightLayout->addWidget(totalPriceLabel, 5, 0);
    rightLayout->addWidget(totalPriceLCDNumber, 5, 1);

    orderControlVBoxLayout->addLayout(rightLayout);
    orderControlVBoxLayout->addStretch();
}

void PropertyWidget::initComponentsUI()
{
    // get all Components
    QList<Model::Component> components = Services::Component::getAll();

    int i=0, col = 0, row = 1;

    for(QList<Model::Component>::iterator p= components.begin();
            p != components.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_ComponentButton").arg(p->id()));
        button->setText((Settings::Language::getCurrentLanguage() == Settings::Language::Arabic) ? p->arabicName() : p->englishName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(p->id())));
        button->setIconSize(QSize(64,64));
        button->setFont(QFont("Hacen Liner Screen Bd", 14, QFont::Normal));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(button->text());
        button->setStatusTip(button->text());
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

void PropertyWidget::initAdditionalsUI()
{
    // get all dditionals
    QList<Model::Additional> additionals = Services::Additional::getAll();

    int i=0, col = 0, row = 1;

    for(QList<Model::Additional>::iterator p= additionals.begin();
            p != additionals.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_AdditionalsButton").arg(p->id()));
        button->setText((Settings::Language::getCurrentLanguage() == Settings::Language::Arabic) ? p->arabicName() : p->englishName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/additionals/additional_notactive_%1.png").arg(p->id())));
        button->setIconSize(QSize(64,64));
        button->setFont(QFont("Hacen Liner Screen Bd", 14, QFont::Normal));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(button->text());
        button->setStatusTip(button->text());
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

    if (Settings::Language::getCurrentLanguage() == Settings::Language::Arabic) {
        itemNameLabel->setText(m_orderDetail.itemDetail().item().arabicName());
        itemNameLabel->setText(itemNameLabel->text() + " - " + m_orderDetail.itemDetail().size().arabicName());
    } else {
        itemNameLabel->setText(m_orderDetail.itemDetail().item().englishName());
        itemNameLabel->setText(itemNameLabel->text() + " - " + m_orderDetail.itemDetail().size().englishName());
    }

    itemQuantityLCDNumber->display(QString::number(m_orderDetail.qunatity()));
    itemPriceLCDNumber->display(QString::number(m_orderDetail.itemDetail().price()));
    itemSugarLCDNumber->display(QString::number(m_orderDetail.sugar().id()));

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
        QMessageBox::warning(this, tr("Unable to add item to shopping cart"), tr("Please make sure you have set the quantity correctly!"));
        return ;
    }

    m_orderDetail.setComponent(readActiveComponents());
    m_orderDetail.setAdditionals(readActiveAdditionals());
    m_orderDetail.setSugar(this->readSugar());
    m_orderDetail.setQuantity(this->readQunatity());
    m_orderDetail.setCash((int)totalPriceLCDNumber->value());

    emit addItem(m_orderDetail);
}

void PropertyWidget:: updateItemClicked()
{

    if ((int)itemQuantityLCDNumber->value() <= 0) {
        QMessageBox::warning(this, tr("Unable to add item to shopping cart"), tr("Please make sure you have set the quantity correctly!"));
        return ;
    }

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
    itemNameLabel->clear();
    itemQuantityLCDNumber->display(0);
    itemPriceLCDNumber->display(0);
    itemSugarLCDNumber->display(0);
    itemComponentsLabel->clear();
    itemAdditionalsLabel->clear();
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
        components.append(Settings::Language::getCurrentLanguage() == Settings::Language::Arabic ? component.arabicName() : component.englishName());
    }

    QStringList additionals;
    foreach (Model::Additional a, readActiveAdditionals()) {
        Model::Additional additional = Services::Additional::getById(a.id());
        additionals.append(Settings::Language::getCurrentLanguage() == Settings::Language::Arabic ? additional.arabicName() : additional.englishName());
    }

    if (components.count())
        itemComponentsLabel->setText(components.join(" , "));
    else
        itemComponentsLabel->setText(tr("<font color='red'>There is no components</font>"));

    if (additionals.count())
        itemAdditionalsLabel->setText(additionals.join(" , "));
    else
        itemAdditionalsLabel->setText(tr("<font color='red'>There is no additionals</font>"));

    // Calculate total price
    updateItemPriceForSpecialCocktail();
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
            Model::Component c = Services::Component::getById(id);
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
            Model::Additional a = Services::Additional::getById(id);
            additionals.append(a);
        }
    }

    return additionals;
}

Model::Sugar PropertyWidget::readSugar()
{
   int id = (int)itemSugarLCDNumber->value();
   return Services::Sugar::getById(id);
}

int PropertyWidget::readQunatity()
{
    return (int)itemQuantityLCDNumber->value();
}

void PropertyWidget::openKeypadDialog()
{
    KeypadDialog keypadDialog;
    keypadDialog.setValue(0);
    if (keypadDialog.exec() == QDialog::Accepted) {
        itemQuantityLCDNumber->display(QString::number(keypadDialog.value()));
        calculateTotalPrice();
    }
}

void PropertyWidget::openSugarDialog()
{
    SugarDialog sugarDialog;
    if (sugarDialog.exec() == QDialog::Accepted) {
        itemSugarLCDNumber->display(QString::number(sugarDialog.value()));
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
    totalPrice = totalPrice + (addtionalCount * 1 * quantity);

    totalPriceLCDNumber->display(QString::number(totalPrice));
}

void PropertyWidget::updateItemPriceForSpecialCocktail()
{
    if ( this->m_orderDetail.itemDetail().item().englishName() == "Special Cocktail" ) {
        Model::Size size = this->m_orderDetail.itemDetail().size();

        int id = size.id();
        if ( id == (int)Model::Size::SMALL ||
             id == (int)Model::Size::MEDIUM ||
             id == (int)Model::Size::JAMBO ) {

            QList<Model::Component> components = readActiveComponents();
            int itemPrice = getLargestComponentsPrice(components, size);
            itemPriceLCDNumber->display(itemPrice);
        }
    }
}

int PropertyWidget::getLargestComponentsPrice(QList<Model::Component>& components, Model::Size size) {
    int largePrice = 0;

    foreach(Model::Component component, components) {
        int price = Services::ComponentPrice::getById(component.id(), size.id()).price();
        if ( price > largePrice ) {
            largePrice = price;
        }
    }

    return largePrice;
}

void PropertyWidget::removeComponents()
{
    QLayoutItem* item;
    while ((item = this->componentsGridLayout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}


void PropertyWidget::removeAdditionals()
{
    QLayoutItem* item;
    while ((item = this->additionalsGridLayout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}


void PropertyWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        removeComponents();
        removeAdditionals();
        initComponentsUI();
        initAdditionalsUI();
        retransilateUi();
    }

    QWidget::changeEvent(event);
}
