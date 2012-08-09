#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSignalMapper>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

#include "categorieswidget.h"

#include "../../MangoModel/category.h"
#include "../../MangoService/category.h"

CategoriesWidget::CategoriesWidget(QWidget *parent) :
    QWidget(parent)
{
    initCategoryGroupBox();
    //initNavigationGroupBox();
    initUi();

    this->setObjectName("categoryWidget");
    this->signalMapper = new QSignalMapper(this);
    connect(this->signalMapper, SIGNAL(mapped(int)), this, SIGNAL(selectCategory(int)));

    this->createCategories();
}

void CategoriesWidget::createCategories()
{
    // Remove pervious buttons from grid layout
    this->removeCategories();

    // get all categories
    QList<Model::Category> categories = Services::Category::getAll();

    int i=0, col = 0, row = 1;
    for(QList<Model::Category>::iterator p = categories.begin();
            p != categories.end(); ++p ) {

        QToolButton* button = new QToolButton;
        button->setObjectName(QString("%1_CategoryButton").arg(p->id()));
        button->setText(p->arabicName());
        button->setFont(QFont("Droid Arabic Naskh", 16, QFont::Bold));
        button->setIcon(QIcon(QString(":/images/juices/category_%1.png").arg(p->id())));
        button->setIconSize(QSize(128,128));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->arabicName());
        button->setStatusTip(p->arabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(button, p->id());
        contentGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

void CategoriesWidget::removeCategories()
{
    QLayoutItem* item;
    while ((item = this->contentGridLayout->takeAt(0)) != NULL ) {
        delete item->widget();
        delete item;
    }
}

void CategoriesWidget::initCategoryGroupBox()
{
    this->categoryGroupBox = new QGroupBox(tr("Categories"));

    this->containerHBoxLayout = new QHBoxLayout;
    this->subContainerVBoxLayout = new QVBoxLayout;
    this->contentGridLayout = new QGridLayout;

    this->containerHBoxLayout->addStretch();
    this->containerHBoxLayout->addLayout(this->subContainerVBoxLayout);
    this->containerHBoxLayout->addStretch();

    this->subContainerVBoxLayout->addStretch();
    this->subContainerVBoxLayout->addLayout(this->contentGridLayout);
    this->subContainerVBoxLayout->addStretch();

    this->containerHBoxLayout->setSpacing(0);
    this->contentGridLayout->setVerticalSpacing(0);
    this->contentGridLayout->setHorizontalSpacing(0);
    this->contentGridLayout->setAlignment(Qt::AlignTop);

    this->categoryGroupBox->setLayout(containerHBoxLayout);
}

void CategoriesWidget::initNavigationGroupBox()
{
    this->navigationGroupBox = new QGroupBox(tr("Navigations"));
    this->navigationContainerVBoxLayout = new QVBoxLayout;

    QLabel* label = new QLabel;
    label->setPixmap(QPixmap(":/images/steps/steps.png"));

    this->navigationContainerVBoxLayout->addWidget(label);

    this->navigationGroupBox->setLayout(navigationContainerVBoxLayout);
}

void CategoriesWidget::initUi()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->addWidget(navigationGroupBox);
    mainLayout->addWidget(categoryGroupBox);
    this->setLayout(mainLayout);
}

