#include "sizewidget.h"
#include "ui_sizewidget.h"

SizeWidget::SizeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SizeWidget)
{
    ui->setupUi(this);
}

SizeWidget::~SizeWidget()
{
    delete ui;
}
