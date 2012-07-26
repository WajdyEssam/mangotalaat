#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSignalMapper>
#include <QIcon>
#include <QDebug>

#include "sizewidget.h"
#include "database/databasemanager.h"

SizeWidget::SizeWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("sizeWidget");
    this->signalMapper = new QSignalMapper(this);
    this->horizontalGroupBox = new QGroupBox(tr("Items"));
    this->containerLayout = new QHBoxLayout;
    this->subContainerLayout = new QVBoxLayout;
    this->layout = new QGridLayout;

    this->containerLayout->addStretch();
    this->containerLayout->addLayout(this->subContainerLayout);
    this->containerLayout->addStretch();

    this->subContainerLayout->addStretch();
    this->subContainerLayout->addLayout(this->layout);
    this->subContainerLayout->addStretch();

    this->containerLayout->setSpacing(0);
    this->layout->setVerticalSpacing(0);
    this->layout->setHorizontalSpacing(0);
    this->layout->setAlignment(Qt::AlignTop);

    this->horizontalGroupBox->setLayout(containerLayout);

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

        QToolButton* button = new QToolButton;
        QString description = databaseManager.getItemSizeDescription(p->getSizeId(), Database::DatabaseManager::ENGLISH);
        button->setObjectName(QString("%1_SizeButton").arg(p->getId()));
        button->setText(description);

        button->setIcon(QIcon(QString(":/images/prices/%1_%2_%3.png").arg(p->getSizeId()).arg(p->getPrice()).arg("en")));
        button->setIconSize(QSize(135,135));
        button->setToolTip(description);
        button->setStatusTip(description);
        //button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(button, p->getId());
        layout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void SizeWidget::setCurrentItemSize(int id)
{
    QString buttonName = QString::number(id) + "_SizeButton";
    QList<QToolButton*> buttons = this->findChildren<QToolButton*>();
    foreach (QToolButton* button,buttons) {
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
