#include "itempropertiesdialog.h"
#include "ui_itempropertiesdialog.h"

ItemPropertiesDialog::ItemPropertiesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemPropertiesDialog)
{
    ui->setupUi(this);
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
