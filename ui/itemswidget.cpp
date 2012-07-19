#include <QDebug>

#include "itemswidget.h"
#include "database/databasemanager.h"

ItemsWidget::ItemsWidget(QWidget *parent) :
    QWidget(parent)
{
}

ItemsWidget::~ItemsWidget()
{
}

void ItemsWidget::addWidgets(int categoryId) {
    if (this->layout() != 0)
        delete this->layout();

    this->signalMapper = new QSignalMapper(this);

    this->horizontalGroupBox = new QGroupBox(tr("Items"));
    QGridLayout *layout = new QGridLayout;

    // get all items
    Database::DatabaseManager databaseManager;
    std::vector<Item> items = databaseManager.getItemsInCategory(categoryId);

    int i=0, col = 0, row = 1;
    for(std::vector<Item>::iterator p = items.begin(); p != items.end(); ++p ) {
        buttons[i] = new QPushButton(p->getEnglishName());
        buttons[i]->setObjectName(QString("%1_itemButton").arg(p->getId()));
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

void ItemsWidget::setCurrentItem(int id){
    QString buttonName = QString::number(id) + "_itemButton";
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton* button,buttons) {
        if (button->objectName() == buttonName)
            button->setChecked(true);
        else
            button->setChecked(false);
    }

    emit selectItem(id);
}
