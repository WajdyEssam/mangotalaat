#include "itempropertiesdialog.h"
#include "ui_itempropertiesdialog.h"

#include "database/databasemanager.h"
#include "model/additionals.h"
#include "model/component.h"
#include "model/itemdetail.h"

ItemPropertiesDialog::ItemPropertiesDialog(Model::OrderDetail aOrderDetail, bool newOrder, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemPropertiesDialog),
    orderDetail(aOrderDetail)
{
    ui->setupUi(this);
    this->isNewOrder = newOrder;

    fillAllComponentsAndAdditionalsFromStore();
    fillCurrentItemDescriptionAndQuantity();

    if ( newOrder )
        fillDefualtComponentsAndAdditionalsForThisOrder();
    else
        fillModifiedComponentsAndAdditionalsForThisOrder();
}

ItemPropertiesDialog::~ItemPropertiesDialog()
{
    delete ui;
}

void ItemPropertiesDialog::on_buttonBox_accepted()
{
    // build modified order here
    QStringList newComponentsList = getNewComponentList();
    QStringList newAdditionalsList = getNewAdditionalList();
    SUGAR sugar = NORMAL;
    int quantity = ui->quantitySpinBox->value();

    this->modifiedOrderDetail = Model::OrderDetail(this->orderDetail.getItemDetialId(), quantity, newComponentsList, newAdditionalsList,
                                       sugar,this->orderDetail.getOrderIndexId() );

    this->isCancel = false;
    this->hide();
}

QStringList ItemPropertiesDialog::getNewComponentList() {
    QStringList componentList;

    for(int i=0; i<ui->currentComponentsListWidget->count(); i++) {
        componentList.append(ui->currentComponentsListWidget->item(i)->text());
    }

    return componentList;
}

QStringList ItemPropertiesDialog::getNewAdditionalList() {
    QStringList additionalList;

    for(int i=0; i<ui->currentAdditionalListWidget->count(); i++) {
        additionalList.append(ui->currentAdditionalListWidget->item(i)->text());
    }

    return additionalList;
}

void ItemPropertiesDialog::on_buttonBox_rejected()
{
    this->isCancel = true;
    this->hide();
}

void ItemPropertiesDialog::fillDefualtComponentsAndAdditionalsForThisOrder() {
    Database::DatabaseManager database;
    Model::ItemDetail itemDetial = database.getItemDetailById(this->orderDetail.getItemDetialId());
    std::vector<Component> currentComponentInItem = database.getCompnentsInItem(itemDetial.getItemId());

    for(std::vector<Component>::iterator p= currentComponentInItem.begin();
            p != currentComponentInItem.end(); ++p) {
        QString name = p->getArabicName();
        this->ui->currentComponentsListWidget->addItem(name);
    }
}

void ItemPropertiesDialog::fillModifiedComponentsAndAdditionalsForThisOrder() {
    Database::DatabaseManager database;
    QStringList componentsList = this->orderDetail.getComponentsIds();
    foreach(QString componentId, componentsList) {
        Component component = database.getComponentById(componentId.toInt());
        this->ui->currentComponentsListWidget->addItem(component.getArabicName());
    }

    QStringList additionalsList = this->orderDetail.getAdditionalsIds();
    foreach(QString additionalId, additionalsList) {
        Additionals additional = database.getAdditionalsById(additionalId.toInt());
        this->ui->currentAdditionalListWidget->addItem(additional.getArabicName());
    }
}

void ItemPropertiesDialog::fillCurrentItemDescriptionAndQuantity() {
    Database::DatabaseManager database;
    Model::ItemDetail itemDetial = database.getItemDetailById(this->orderDetail.getItemDetialId());
    Model::Item item = database.getItemById(itemDetial.getItemId());
    QString sizeDescription = database.getItemSizeDescription(itemDetial.getSizeId(), database.ARABIC);

    this->ui->orderLineEdit->setText(item.getArabicName() + " - " + sizeDescription);
    this->ui->quantitySpinBox->setValue(this->orderDetail.getQunatity());
}

void ItemPropertiesDialog::fillAllComponentsAndAdditionalsFromStore() {
    Database::DatabaseManager database;

    std::vector<Additionals> additionals = database.getAllAdditionals();
    std::vector<Component> components = database.getAllCompnents();

    for(std::vector<Additionals>::iterator p= additionals.begin();
            p != additionals.end(); ++p) {
        QString name = p->getArabicName();
        this->ui->allAdditionalListWidget->addItem(name);
    }

    for(std::vector<Component>::iterator p= components.begin();
            p != components.end(); ++p) {
        QString name = p->getArabicName();
        this->ui->allComponentsListWidget->addItem(name);
    }
}
