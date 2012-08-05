#include <QDebug>

#include "itemswidget.h"

#include "../../MangoModel/item.h"
#include "../../MangoService/item.h"

ItemsWidget::ItemsWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("itemWidget");
    this->signalMapper = new QSignalMapper(this);
    this->horizontalGroupBox = new QGroupBox(tr("Items"));
    this->layout = new QGridLayout;

    this->horizontalGroupBox->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBox);
    this->setLayout(mainLayout);

    connect(this->signalMapper, SIGNAL(mapped(int)), this, SIGNAL(selectItem(int)));
}

ItemsWidget::~ItemsWidget()
{
}

void ItemsWidget::createItems(int categoryId)
{
    // Remove pervious buttons from grid layout
    this->removeItems();

    // Get all items
    QList<Model::Item> items = Services::Item::getByCategoryId(categoryId);

    int i=0, col = 0, row = 1;
    for(QList<Model::Item>::iterator p = items.begin(); p != items.end(); ++p ) {
        buttons[i] = new QPushButton(p->arabicName());
        buttons[i]->setObjectName(QString("%1_itemButton").arg(p->id()));
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(buttons[i], p->id());
        layout->addWidget(buttons[i], row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void ItemsWidget::removeItems()
{
    QLayoutItem* item;
    while ((item = this->layout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}
