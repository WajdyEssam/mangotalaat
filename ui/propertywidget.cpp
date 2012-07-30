#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QIcon>
#include <QDebug>

#include "propertywidget.h"
#include "database/databasemanager.h"
#include "ui/toolbutton.h"
#include "model/constants.h"

PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("propertyWidget");
    this->componentSignalMapper = new QSignalMapper(this);
    this->additionalSignalMapper = new QSignalMapper(this);

    orderGroupBox = new QGroupBox(tr("Order"));
    componentsGroupBox = new QGroupBox(tr("Components"));
    additionalsGroupBox = new QGroupBox(tr("Additionals"));

    orderGridLayout = new QGridLayout;
    componentsGridLayout = new QGridLayout;
    additionalsGridLayout = new QGridLayout;

    orderGroupBox->setLayout(orderGridLayout);
    componentsGroupBox->setLayout(componentsGridLayout);
    additionalsGroupBox->setLayout(additionalsGridLayout);

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->addWidget(orderGroupBox);
    mainVBoxLayout->addWidget(componentsGroupBox);
    mainVBoxLayout->addWidget(additionalsGroupBox);
    this->setLayout(mainVBoxLayout);

    connect(this->componentSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentComponent(int)));
    connect(this->additionalSignalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentAdditional(int)));

    this->initOrder();
    this->initComponents();
    this->initAdditionals();
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
}

void PropertyWidget::initOrder()
{
    QHBoxLayout* layout = new QHBoxLayout;

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
    layout->addStretch();

    orderGridLayout->addLayout(layout,0,0);
}

void PropertyWidget::initComponents()
{
    // get all Components
    Database::DatabaseManager databaseManager;
    std::vector<Component> components = databaseManager.getAllCompnents();

    int i=0, col = 0, row = 1;

    for(std::vector<Component>::iterator p= components.begin();
            p != components.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_ComponentButton").arg(p->getId()));
        button->setText(p->getArabicName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(p->getId())));
        button->setIconSize(QSize(64,64));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->getArabicName());
        button->setStatusTip(p->getArabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), componentSignalMapper, SLOT(map()));
        this->componentSignalMapper->setMapping(button, p->getId());
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
    Database::DatabaseManager databaseManager;
    std::vector<Additionals> additionals = databaseManager.getAllAdditionals();

    int i=0, col = 0, row = 1;

    for(std::vector<Additionals>::iterator p= additionals.begin();
            p != additionals.end(); ++p) {

        ToolButton* button = new ToolButton;
        button->setObjectName(QString("%1_AdditionalsButton").arg(p->getId()));
        button->setText(p->getArabicName());
        button->setActiveState(ToolButton::NotActive);
        button->setIcon(QIcon(QString(":/images/additionals/additional_notactive_%1.png").arg(p->getId())));
        button->setIconSize(QSize(64,64));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->getArabicName());
        button->setStatusTip(p->getArabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), additionalSignalMapper, SLOT(map()));
        this->additionalSignalMapper->setMapping(button, p->getId());
        additionalsGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
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
}

void PropertyWidget::addItemClicked()
{
    int itemDetailId = this->m_orderDetail.getItemDetialId();
    QStringList components = readActiveComponents();
    QStringList additionals = readActiveAdditionals();
    SUGAR sugar = readSugar();
    int quantity = readQunatity();
    QString orderIndexId = this->m_orderDetail.getOrderIndexId();

    Model::OrderDetail orderDetail(itemDetailId, quantity, components, additionals, sugar, orderIndexId);

    emit addItem(orderDetail);
}

void PropertyWidget::updateItemClicked()
{
    int itemDetailId = this->m_orderDetail.getItemDetialId();
    QStringList components = readActiveComponents();
    QStringList additionals = readActiveAdditionals();
    SUGAR sugar = readSugar();
    int quantity = readQunatity();
    QString orderIndexId = this->m_orderDetail.getOrderIndexId();

    Model::OrderDetail orderDetail(itemDetailId, quantity, components, additionals, sugar, orderIndexId);

    emit updateItem(this->m_orderDetail, orderDetail);
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

void PropertyWidget::recheckComponentsButtons()
{
    Database::DatabaseManager databaseManager;
    QStringList componentsList = this->m_orderDetail.getComponentsIds();

    foreach(QString componentId, componentsList) {
        Component component = databaseManager.getComponentById(componentId.toInt());
        int id = component.getId();
        QString buttonName = QString::number(id) + "_ComponentButton";
        ToolButton* button = this->findChild<ToolButton*>(buttonName);
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/components/component_active_%1.png").arg(id)));
    }
}

void PropertyWidget::recheckAdditionalsButtons()
{
    Database::DatabaseManager databaseManager;
    QStringList additionalsList = this->m_orderDetail.getAdditionalsIds();

    foreach(QString additionalId, additionalsList) {
        Additionals additional = databaseManager.getAdditionalsById(additionalId.toInt());
        int id = additional.getId();
        QString buttonName = QString::number(id) + "_ComponentButton";
        ToolButton* button = this->findChild<ToolButton*>(buttonName);
        button->setActiveState(ToolButton::Active);
        button->setIcon(QIcon(QString(":/images/additionals/additional_active_%1.png").arg(id)));
    }
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

SUGAR PropertyWidget::readSugar()
{
    return NORMAL;
}

int PropertyWidget::readQunatity()
{
    return 1;
}
