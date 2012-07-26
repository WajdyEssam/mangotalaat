#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QSignalMapper>
#include <QIcon>
#include <QDebug>

#include "propertywidget.h"
#include "database/databasemanager.h"

PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("propertyWidget");
    this->signalMapper = new QSignalMapper(this);
    orderGroupBox = new QGroupBox(tr("Order"));
    componentsGroupBox = new QGroupBox(tr("Components"));
    additionalsGroupBox = new QGroupBox(tr("Additionals"));

    orderGridLayout = new QGridLayout;
    componentsGridLayout = new QGridLayout;
    additionalsGridLayout = new QGridLayout;

    orderGroupBox->setLayout(orderGridLayout);
    componentsGroupBox->setLayout(componentsGridLayout);
    additionalsGroupBox->setLayout(additionalsGridLayout);

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->addWidget(orderGroupBox);
    mainVBoxLayout->addWidget(componentsGroupBox);
    mainVBoxLayout->addWidget(additionalsGroupBox);
    this->setLayout(mainVBoxLayout);

    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentComponent(int)));

    //this->initOrder();
    this->initComponents();
    //this->initAdditionals();
}

void PropertyWidget::setOrder(Model::Order order)
{
}

void PropertyWidget::initOrder()
{

}

void PropertyWidget::initComponents()
{
    // get all Components
    Database::DatabaseManager databaseManager;
    std::vector<Component> components = databaseManager.getAllCompnents();

    int i=0, col = 0, row = 1;

    for(std::vector<Component>::iterator p= components.begin();
            p != components.end(); ++p) {

        QToolButton* button = new QToolButton;
        button->setObjectName(QString("%1_ComponentButton").arg(p->getId()));
        button->setText(p->getArabicName());
        button->setCheckable(true);
        button->setChecked(false);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(p->getId())));
        button->setIconSize(QSize(64,64));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->getArabicName());
        button->setStatusTip(p->getArabicName());
        button->setContentsMargins(0,0,0,0);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        this->signalMapper->setMapping(button, p->getId());
        componentsGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}

/*void PropertyWidget::initAdditionals()
{
    // get all Components
    Database::DatabaseManager databaseManager;
    std::vector<Additionals> additionals = databaseManager.getAllAdditionals();

    int i=0, col = 0, row = 1;

    for(std::vector<Additionals>::iterator p= additionals.begin();
            p != additionals.end(); ++p) {

        QToolButton* button = new QToolButton;
        button->setObjectName(QString("%1_AdditionalsButton").arg(p->getId()));
        button->setText(p->getArabicName());
        button->setIcon(QIcon(QString(":/images/juices/additionals_%1.png").arg(p->getId())));
        button->setIconSize(QSize(60,60));
        button->setFixedSize(QSize(100,100));
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setToolTip(p->getArabicName());
        button->setStatusTip(p->getArabicName());
        button->setContentsMargins(0,0,0,0);
        //connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        //this->signalMapper->setMapping(button, p->getId());
        additionalsGridLayout->addWidget(button, row, col);

        col++;
        i++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }
}
*/


void PropertyWidget::setCurrentComponent(int id)
{
//    QToolButton* senderButton = (QToolButton*) sender();
//    senderButton->toggle();

//    if (senderButton->isChecked()) {
//        qDebug() << senderButton->objectName() + " is checked after toggle";
//    } else {
//        qDebug() << senderButton->objectName() + " is not checked after toggle";
//    }

    QString buttonName = QString::number(id) + "_ComponentButton";
    QToolButton* button = this->findChild<QToolButton*>(buttonName);

    if ( !button->isChecked()) {
        qDebug() << button->objectName() + " is checked";
        button->setChecked(false);
        button->setIcon(QIcon(QString(":/images/components/component_notactive_%1.png").arg(id)));
    } else if ( button->isChecked() ){
        qDebug() << button->objectName() + " is not checked";
        button->setChecked(true);
        button->setIcon(QIcon(QString(":/images/components/component_active_%1.png").arg(id)));
    }
}
