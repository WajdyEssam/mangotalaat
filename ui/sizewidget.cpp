#include "sizewidget.h"
#include "database/databasemanager.h"

SizeWidget::SizeWidget(QWidget *parent) :
    QWidget(parent)
{
}

SizeWidget::~SizeWidget()
{
}

void SizeWidget::addWidgets(int itemId) {
    this->signalMapper = new QSignalMapper(this);

    this->horizontalGroupBox = new QGroupBox(tr("Items"));
    QGridLayout *layout = new QGridLayout;

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

    this->horizontalGroupBox->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBox);
    this->setLayout(mainLayout);

    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentItem(int)));
}

void SizeWidget::setCurrentItem(int id){
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
