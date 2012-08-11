#include <QApplication>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QSignalMapper>
#include <QAction>
#include <QMenu>

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
    p.fillRect(QRect(0,0,width(),100), QBrush(background));
}

void HeaderWidget::init()
{
    this->setObjectName("headerWidget");
    this->signalMapper = new QSignalMapper(this);
    this->setFixedHeight(100);
    this->createToolButtons();
    this->setLayoutDirection(Qt::RightToLeft);
    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(emitSignal(int)));
}

void HeaderWidget::createToolButtons()
{
    QFont font("Droid Arabic Naskh", 12, QFont::Bold);

    QToolButton* HomeButton = new QToolButton;
    HomeButton->setIcon(QIcon(":/images/system.png"));
    HomeButton->setText("البداية");
    HomeButton->setIconSize(QSize(64,64));
    HomeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    HomeButton->setToolTip("البداية");
    HomeButton->setStatusTip(HomeButton->toolTip());
    HomeButton->setFont(font);

    QToolButton* reportsButton = new QToolButton;
    reportsButton->setIcon(QIcon(":/images/report.png"));
    reportsButton->setText("التقارير");
    reportsButton->setIconSize(QSize(64,64));
    reportsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    reportsButton->setToolTip("التقارير");
    reportsButton->setStatusTip(reportsButton->toolTip());
    reportsButton->setFont(font);

    // add menu for report button
    QAction *todayLogginReportAction = new QAction(QIcon(":/images/find.png"),tr("التقرير اليومي"), this);
    connect(todayLogginReportAction, SIGNAL(triggered()), this, SIGNAL(todayLogginReportActionClicked()));

    QAction *generalReportAction = new QAction(QIcon(":/images/find.png"),tr("تقرير مخصص"), this);
    connect(generalReportAction, SIGNAL(triggered()), this, SIGNAL(generalReportActionClicked()));

    QMenu *reportMenu = new QMenu(this);
    reportMenu->addAction(todayLogginReportAction);
    reportMenu->addAction(generalReportAction);

    reportsButton->setMenu(reportMenu);
    reportsButton->setPopupMode(QToolButton::InstantPopup);

    QToolButton* systemButton = new QToolButton;
    systemButton->setIcon(QIcon(":/images/accounting.png"));
    systemButton->setText("النظام");
    systemButton->setIconSize(QSize(64,64));
    systemButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    systemButton->setToolTip("النظام");
    systemButton->setStatusTip(systemButton->toolTip());
    systemButton->setFont(font);

    // add menu for system button
    QAction *closeSystemAction = new QAction(QIcon(":/images/find.png"),tr("اغلاق حساب اليوم"), this);
    connect(closeSystemAction, SIGNAL(triggered()), this, SIGNAL(closeSystemActionClicked()));

    QAction *aboutSystemAction = new QAction(QIcon(":/images/find.png"), tr("عن النظام"), this);
    connect(aboutSystemAction, SIGNAL(triggered()), this, SIGNAL(aboutSystemActionClicked()));

    QMenu *systemMenu = new QMenu(this);
    systemMenu->addAction(closeSystemAction);
    systemMenu->addAction(aboutSystemAction);

    systemButton->setMenu(systemMenu);
    systemButton->setPopupMode(QToolButton::InstantPopup);

    QToolButton* signOutButton = new QToolButton;
    signOutButton->setIcon(QIcon(":/images/logout.png"));
    signOutButton->setText("خروج");
    signOutButton->setIconSize(QSize(64,64));
    signOutButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    signOutButton->setToolTip("خروج");
    signOutButton->setStatusTip(signOutButton->toolTip());
    signOutButton->setFont(font);

    QHBoxLayout* headerLayout = new QHBoxLayout(this);
    headerLayout->addWidget(HomeButton);
    headerLayout->addWidget(reportsButton);
    headerLayout->addWidget(systemButton);
    headerLayout->addWidget(signOutButton);

    this->signalMapper->setMapping(HomeButton, 1);
    this->signalMapper->setMapping(signOutButton, 2);

    connect(HomeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signOutButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
}

void HeaderWidget::emitSignal(int id)
{
    switch (id) {
    case 1:
        emit homeClicked();
        break;
    case 2:
        emit logoutClicked();
        break;
    }
}


