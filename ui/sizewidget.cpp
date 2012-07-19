#include "sizewidget.h"
#include "database/databasemanager.h"

SizeWidget::SizeWidget(QWidget *parent) :
    QWidget(parent)
{
    this->signalMapper = new QSignalMapper(this);

    this->horizontalGroupBox = new QGroupBox(tr("Items"));
    this->layout = new QGridLayout;

    this->horizontalGroupBox->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBox);
    this->setLayout(mainLayout);

    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentItemSize(int)));
}

SizeWidget::~SizeWidget()
{
}

void SizeWidget::createItemSizes(int itemId)
{
    // Remove pervious buttons from grid layout
    this->removeItemSizes();

    // get all size
    Database::DatabaseManager databaseManager;
    std::vector<ItemDetail> itemsDetial = databaseManager.getItemDetails(itemId);

    int i=0, col = 0, row = 1;
    for(std::vector<ItemDetail>::iterator p = itemsDetial.begin(); p != itemsDetial.end(); ++p ) {
        int sizeId = p->getSizeId();
        QString description = databaseManager.getItemSizeDescription(sizeId, Database::DatabaseManager::ENGLISH);

        buttons[i] = new QPushButton(description);
        buttons[i]->setObjectName(QString("%1_toolButton").arg(p->getId()));
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(buttons[i], p->getId());
        layout->addWidget(buttons[i], row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void SizeWidget::setCurrentItemSize(int id){
    QString buttonName = QString::number(id) + "_toolButton";
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton* button,buttons) {
        if (button->objectName() == buttonName)
            button->setChecked(true);
        else
            button->setChecked(false);
    }

    emit selectItemDetail(id);
}

void SizeWidget::removeItemSizes()
{
    QLayoutItem* item;
    while ((item = this->layout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}
