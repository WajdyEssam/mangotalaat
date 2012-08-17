#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSignalMapper>
#include <QIcon>
#include <QEvent>
#include <QDebug>

#include "itemswidget.h"

#include "../../MangoModel/item.h"
#include "../../MangoService/item.h"

#include "../language.h"

ItemsWidget::ItemsWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("itemWidget");
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
        QToolButton* button = new QToolButton;
        button->setObjectName(QString("%1_itemButton").arg(p->id()));
        button->setText((Settings::Language::getCurrentLanguage() == Settings::Language::Arabic) ? p->arabicName() : p->englishName());
        button->setFont(QFont("Hacen Liner Screen Bd", 14, QFont::Normal));
        button->setIconSize(QSize(128,128));
        //button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        button->setToolTip(button->text());
        button->setStatusTip(button->text());
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(button, p->id());
        layout->addWidget(button, row, col);

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

void ItemsWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        //createItems();
    }

    QWidget::changeEvent(event);
}
