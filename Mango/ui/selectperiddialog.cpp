#include "selectperiddialog.h"
#include "ui_selectperiddialog.h"

SelectPeridDialog::SelectPeridDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPeridDialog)
{
    ui->setupUi(this);
}

SelectPeridDialog::~SelectPeridDialog()
{
    delete ui;
}

void SelectPeridDialog::on_buttonBox_accepted()
{
    this->m_from = QDateTime(this->ui->fromWidget->selectedDate());
    this->m_to = QDateTime(this->ui->toWidget->selectedDate());
    this->m_accept = true;
    this->hide();
}

void SelectPeridDialog::on_buttonBox_rejected()
{
    this->m_accept = false;
    this->hide();
}

QDateTime SelectPeridDialog::from()
{
    return this->m_from;
}

QDateTime SelectPeridDialog::to()
{
    return this->m_to;
}

bool SelectPeridDialog::isAccepted()
{
    return this->m_accept;
}
