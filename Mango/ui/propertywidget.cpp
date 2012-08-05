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

    commandButtonHBoxLayout = new QHBoxLayout;
    orderVBoxLayout = new QVBoxLayout;
    componentsGridLayout = new QGridLayout;
    additionalsGridLayout = new QGridLayout;

    orderGroupBox->setLayout(orderVBoxLayout);
    componentsGroupBox->setLayout(componentsGridLayout);
    additionalsGroupBox->setLayout(additionalsGridLayout);

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->addLayout(commandButtonHBoxLayout);
    mainVBoxLayout->addWidget(orderGroupBox);
    mainVBoxLayout->addWidget(componentsGroupBox);
    mainVBoxLayout->addWidget(additionalsGroupBox);
    this->setLayout(mainVBoxLayout);

    connect(this->componentSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentComponent(int)));
    connect(this->additionalSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentAdditional(int)));

    this->initCommandButtons();
    this->initOrder();
    this->initComponents();
    this->initAdditionals();
}

void PropertyWidget::initCommandButtons()
{
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

    commandButtonHBoxLayout->addWidget(addButton);
    commandButtonHBoxLayout->addWidget(updateButton);
    commandButtonHBoxLayout->addWidget(removeButton);
    commandButtonHBoxLayout->addStretch();
}

void PropertyWidget::initOrder()
{
    itemNameLineEdit = new QLineEdit;
    itemNameLineEdit->setReadOnly(true);

    itemSizeLineEdit = new QLineEdit;
    itemSizeLineEdit->setReadOnly(true);

    itemComponentsLineEdit = new QLineEdit;
    itemComponentsLineEdit->setReadOnly(true);

    itemAdditionalsLineEdit = new QLineEdit;
    itemAdditionalsLineEdit->setReadOnly(true);

    QFormLayout* leftLayout = new QFormLayout;
    leftLayout->addRow(tr("Item"), itemNameLineEdit);
    leftLayout->addRow(tr("Size"), itemSizeLineEdit);
    leftLayout->addRow(tr("Components"), itemComponentsLineEdit);
    leftLayout->addRow(tr("Additionals"), itemAdditionalsLineEdit);

    QLabel* itemQuantityLabel = new QLabel(tr("Quantity"));
    itemQuantityLineEdit = new QLineEdit;
    itemQuantityLineEdit->setReadOnly(true);
    QPushButton* quantityButton = new QPushButton("+");
    connect(quantityButton, SIGNAL(clicked()), SLOT(openKeypadDialog()));

    QLabel* itemPriceLabel = new QLabel(tr("Item Price"));
    itemPriceLineEdit = new QLineEdit;
    itemPriceLineEdit->setReadOnly(true);

    QLabel* totalPriceLabel = new QLabel(tr("Total Price"));
    totalPriceLineEdit = new QLineEdit;
    totalPriceLineEdit->setReadOnly(true);

    QLabel* itemSugarLabel = new QLabel(tr("Sugar"));
    itemSugarLineEdit = new QLineEdit;
    itemSugarLineEdit->setReadOnly(true);
    QPushButton* sugarButton = new QPushButton("+");

    QGridLayout* rightLayout = new QGridLayout;
    rightLayout->addWidget(itemQuantityLabel, 0, 0, 1, 1);
    rightLayout->addWidget(itemQuantityLineEdit, 0, 1, 1, 5);
    rightLayout->addWidget(quantityButton, 0, 6, 1 ,1);

    rightLayout->addWidget(itemSugarLabel, 1, 0, 1, 1);
    rightLayout->addWidget(itemSugarLineEdit, 1, 1, 1, 5);
    rightLayout->addWidget(sugarButton, 1, 6);

    rightLayout->addWidget(itemPriceLabel, 2, 0, 1, 1);
    rightLayout->addWidget(itemPriceLineEdit, 2, 1, 1, 5);

    rightLayout->addWidget(totalPriceLabel, 3, 0, 1, 1);
    rightLayout->addWidget(totalPriceLineEdit, 3, 1, 1, 5);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(leftLayout, 1);
    layout->addLayout(rightLayout, 1);

    orderVBoxLayout->addLayout(layout);
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
        this->setActiveComponents();
        this->setActiveAdditionals();
    }

    itemNameLineEdit->setText(m_orderDetail.itemDetail().item().arabicName());
    itemQuantityLineEdit->setText(QString::number(m_orderDetail.qunatity()));
    itemSizeLineEdit->setText(m_orderDetail.itemDetail().size().arabicName());
    itemPriceLineEdit->setText(QString::number(m_orderDetail.cash()));
    itemSugarLineEdit->setText(QString::number(m_orderDetail.sugar()));

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
    if (itemQuantityLineEdit->text().toInt() <= 0) {
        QMessageBox::warning(this, tr("Operation faild"), tr("Please enter the quantity"));
        return ;
    }

    int id = this->m_orderDetail.itemDetail().id();
    QStringList components = readActiveComponents();
    QStringList additionals = readActiveAdditionals();
    int sugar = readSugar();
    int quantity = readQunatity();
    QString orderIndexId = this->m_orderDetail.orderIndexId();

    //Model::OrderDetail orderDetail(id, m_orderDetail.order(), m_orderDetail.itemDetail(), quantity, components, additionals, sugar, cash);

    //emit addItem(orderDetail);
}

void PropertyWidget::updateItemClicked()
{
    int itemDetailId = this->m_orderDetail.itemDetail().id();
    QStringList components = readActiveComponents();
    QStringList additionals = readActiveAdditionals();
    int sugar = readSugar();
    int quantity = readQunatity();
    QString orderIndexId = this->m_orderDetail.orderIndexId();

    //Model::OrderDetail orderDetail(itemDetailId, quantity, components, additionals, sugar, orderIndexId);

    //emit updateItem(this->m_orderDetail, orderDetail);
}

void PropertyWidget::removeItemClicked()
{
    emit removeItem(this->m_orderDetail);
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
    itemQuantityLineEdit->clear();
    itemSizeLineEdit->clear();
    itemPriceLineEdit->clear();
    itemSugarLineEdit->clear();
    itemComponentsLineEdit->clear();
    itemAdditionalsLineEdit->clear();
    totalPriceLineEdit->clear();
}

void PropertyWidget::recheckComponentsButtons()
{
    foreach(Model::Component component, this->m_orderDetail.components()) {
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
    foreach (QString id, readActiveComponents()) {
        Model::Component component = Services::Component::getById(id.toInt());
        components.append(component.arabicName());
    }

    QStringList additionals;
    foreach (QString id, readActiveAdditionals()) {
        Model::Additional additional = Services::Additional::getById(id.toInt());
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

QStringList PropertyWidget::readActiveComponents()
{
    QList<ToolButton*> buttons = this->componentsGroupBox->findChildren<ToolButton*>();
    QStringList components;

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            components.append(QString::number(id));
        }
    }

    return components;
}

QStringList PropertyWidget::readActiveAdditionals()
{
    QList<ToolButton*> buttons = this->additionalsGroupBox->findChildren<ToolButton*>();
    QStringList additionals;

    foreach (ToolButton* button, buttons) {

        int id = button->objectName().split("_").first().toInt();

        if ( button->activeState() == ToolButton::Active) {
            additionals.append(QString::number(id));
        }
    }

    return additionals;
}

int PropertyWidget::readSugar()
{
    return 1;
}

int PropertyWidget::readQunatity()
{
    return itemQuantityLineEdit->text().toInt();
}

void PropertyWidget::setActiveComponents()
{
    foreach (Model::ItemComponent itemComponent, Services::ItemComponent::getByItemId(m_orderDetail.itemDetail().item().id())) {
        Model::Component c = Services::Component::getById(itemComponent.id());
        int id = c.id();
        QString buttonName = QString::number(id) + "_ComponentButton";
        ToolButton* button = this->findChild<ToolButton*>(buttonName);
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/components/component_active_%1.png").arg(id)));
    }
}

void PropertyWidget::setActiveAdditionals()
{
}

void PropertyWidget::openKeypadDialog()
{
    KeypadDialog keypadDialog;
    keypadDialog.setValue(itemQuantityLineEdit->text().toInt());
    if (keypadDialog.exec() == QDialog::Accepted) {
        itemQuantityLineEdit->setText(QString::number(keypadDialog.value()));
        calculateTotalPrice();
    }
}

void PropertyWidget::calculateTotalPrice()
{
    int quantity = itemQuantityLineEdit->text().toInt();
    int componentsCount = readActiveComponents().count();
    int addtionalCount = readActiveAdditionals().count();
    int itemPrice = itemPriceLineEdit->text().toInt();
    int totalPrice = itemPrice * quantity;
    totalPrice = totalPrice + (componentsCount * 1);
    totalPrice = totalPrice + (addtionalCount * 1);

    totalPriceLineEdit->setText(QString::number(totalPrice));
}
