#include <QApplication>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QSignalMapper>

#include "headerwidget.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

void HeaderWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QLinearGradient background(0,0, 0,100);
    background.setColorAt(0, QColor(115,115,115));
    background.setColorAt(1, QColor(65,65,65));
    p.fillRect(QRect(0,0,width(),120), QBrush(background));
}

void HeaderWidget::init()
{
    this->setObjectName("headerWidget");
    this->signalMapper = new QSignalMapper(this);
    this->setFixedHeight(120);
    this->createToolButtons();
    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(emitSignal(int)));
}

void HeaderWidget::createToolButtons()
{
    QToolButton* HomeButton = new QToolButton;
    HomeButton->setIcon(QIcon(":/images/system.png"));
    HomeButton->setText("Home");
    HomeButton->setIconSize(QSize(70,70));
    HomeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    HomeButton->setToolTip("Home");
    HomeButton->setStatusTip(HomeButton->toolTip());

    QToolButton* reportsButton = new QToolButton;
    reportsButton->setIcon(QIcon(":/images/report.png"));
    reportsButton->setText("Report");
    reportsButton->setIconSize(QSize(70,70));
    reportsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    reportsButton->setToolTip("Report");
    reportsButton->setStatusTip(reportsButton->toolTip());

    QToolButton* systemButton = new QToolButton;
    systemButton->setIcon(QIcon(":/images/accounting.png"));
    systemButton->setText("System");
    systemButton->setIconSize(QSize(70,70));
    systemButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    systemButton->setToolTip("System");
    systemButton->setStatusTip(systemButton->toolTip());

    QToolButton* signOutButton = new QToolButton;
    signOutButton->setIcon(QIcon(":/images/logout.png"));
    signOutButton->setText("Logout");
    signOutButton->setIconSize(QSize(70,70));
    signOutButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    signOutButton->setToolTip("Logout");
    signOutButton->setStatusTip(signOutButton->toolTip());

    QHBoxLayout* headerLayout = new QHBoxLayout(this);
    headerLayout->addWidget(HomeButton);
    headerLayout->addWidget(reportsButton);
    headerLayout->addWidget(systemButton);
    headerLayout->addWidget(signOutButton);

    this->signalMapper->setMapping(HomeButton, 1);
    this->signalMapper->setMapping(reportsButton, 2);
    this->signalMapper->setMapping(systemButton, 3);
    this->signalMapper->setMapping(signOutButton, 4);

    connect(HomeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(reportsButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(systemButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signOutButton, SIGNAL(clicked()), signalMapper, SLOT(map()));

}

void HeaderWidget::emitSignal(int id)
{
    switch (id) {
    case 1:
        emit homeClicked();
        break;
    case 2:
        emit reportClicked();
        break;
    case 3:
        emit systemClicked();
        break;
    case 4:
        qApp->quit();
    }
}


