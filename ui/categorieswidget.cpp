#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSignalMapper>
#include <QIcon>
#include <QDebug>

#include "categorieswidget.h"
#include "database/databasemanager.h"

CategoriesWidget::CategoriesWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("categoryWidget");
    this->signalMapper = new QSignalMapper(this);
    this->horizontalGroupBox = new QGroupBox(tr("Categories"));
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

    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentCategory(int)));

    this->createCategories();

}

CategoriesWidget::~CategoriesWidget()
{
}

void CategoriesWidget::createCategories()
{
    // Remove pervious buttons from grid layout
    this->removeCategories();

    // get all categories
    Database::DatabaseManager databaseManager;
    std::vector<Category> categories = databaseManager.getCategories();

    int i=0, col = 0, row = 1;
    for(std::vector<Category>::iterator p = categories.begin();
            p != categories.end(); ++p ) {

        QToolButton* button = new QToolButton;
        button->setObjectName(QString("%1_CategoryButton").arg(p->getId()));
        button->setText(p->getEnglishName());
        button->setIcon(QIcon(QString(":/images/juices/category_%1.png").arg(p->getId())));
        button->setIconSize(QSize(100,100));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->getEnglishName());
        button->setStatusTip(p->getEnglishName());
        button->setContentsMargins(0,0,0,0);
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

void CategoriesWidget::setCurrentCategory(int id){
    QString buttonName = QString::number(id) + "_CategoryButton";
    QList<QToolButton*> buttons = this->findChildren<QToolButton*>();
    foreach (QToolButton* button,buttons) {
        if (button->objectName() == buttonName)
            button->setChecked(true);
        else
            button->setChecked(false);
    }

    emit selectCategory(id);
}

void CategoriesWidget::removeCategories()
{
    QLayoutItem* item;
    while ((item = this->layout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}

