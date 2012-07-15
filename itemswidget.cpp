#include "itemswidget.h"
#include "ui_itemswidget.h"

ItemsWidget::ItemsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemsWidget)
{
    ui->setupUi(this);
}

ItemsWidget::~ItemsWidget()
{
    delete ui;
}
