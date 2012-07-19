#include "itempropertiesdialog.h"
#include "ui_itempropertiesdialog.h"

#include "database/databasemanager.h"
#include "model/additionals.h"
#include "model/component.h"
#include "model/itemdetail.h"

ItemPropertiesDialog::ItemPropertiesDialog(int aItemDetialId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemPropertiesDialog)
{
    ui->setupUi(this);
    this->itemDetialId = aItemDetialId;

    fillComponentsAndAdditionals();
}

ItemPropertiesDialog::~ItemPropertiesDialog()
{
    delete ui;
}

void ItemPropertiesDialog::on_buttonBox_accepted()
{
    this->isCancel = false;
    this->hide();
}

void ItemPropertiesDialog::on_buttonBox_rejected()
{
    this->isCancel = true;
    this->hide();
}

void ItemPropertiesDialog::fillComponentsAndAdditionals() {
    Database::DatabaseManager database;

    std::vector<Additionals> additionals = database.getAllAdditionals();
    std::vector<Component> components = database.getAllCompnents();

    Model::ItemDetail itemDetial = database.getItemDetailById(this->itemDetialId);
    std::vector<Component> currentComponentInItem = database.getCompnentsInItem(itemDetial.getItemId());


}
