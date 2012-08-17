#include "headerwidget.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

void HeaderWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QLinearGradient background(0,0, 0,100);
    background.setColorAt(0, QColor("black"));
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
    QFont font("Hacen Liner Print-out Light", 12, QFont::Normal);

    backButton = new QToolButton;
    backButton->setIcon(QIcon(":/images/back_ar.png"));
    backButton->setText("عودة");
    backButton->setIconSize(QSize(64,64));
    backButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    backButton->setToolTip("عودة");
    backButton->setStatusTip(backButton->toolTip());
    backButton->setFont(font);

    QToolButton* homeButton = new QToolButton;
    homeButton->setIcon(QIcon(":/images/system.png"));
    homeButton->setText("البداية");
    homeButton->setIconSize(QSize(64,64));
    homeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    homeButton->setToolTip("البداية");
    homeButton->setStatusTip(homeButton->toolTip());
    homeButton->setFont(font);

    reportsButton = new QToolButton;
    reportsButton->setIcon(QIcon(":/images/report.png"));
    reportsButton->setText("التقارير");
    reportsButton->setIconSize(QSize(64,64));
    reportsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    reportsButton->setToolTip("التقارير");
    reportsButton->setStatusTip(reportsButton->toolTip());
    reportsButton->setFont(font);

    // add menu for report button
    QAction *todayLogginReportAction = new QAction(QIcon(":/images/find.png"),tr("تقرير يومي بعمليات الدخول"), this);
    connect(todayLogginReportAction, SIGNAL(triggered()), this, SIGNAL(todayLogginReportActionClicked()));

    QAction *todayOrdersReportAction = new QAction(QIcon(":/images/find.png"),tr("تقرير يومي بالطلبات"), this);
    connect(todayOrdersReportAction, SIGNAL(triggered()), this, SIGNAL(todayOrdersReportActionClicked()));

    QAction *todayOrdersDetailsReportAction = new QAction(QIcon(":/images/find.png"),tr("تقرير يومي بتفاصيل الطلبات"), this);
    connect(todayOrdersDetailsReportAction, SIGNAL(triggered()), this, SIGNAL(todayOrdersDetailsReportActionClicked()));

    QAction *generalReportAction = new QAction(QIcon(":/images/find.png"),tr("تقرير شامل"), this);
    connect(generalReportAction, SIGNAL(triggered()), this, SIGNAL(generalReportActionClicked()));

    QMenu *reportMenu = new QMenu(this);
    reportMenu->addAction(todayLogginReportAction);
    reportMenu->addAction(todayOrdersReportAction);
    reportMenu->addAction(todayOrdersDetailsReportAction);
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
    closeSystemAction = new QAction(QIcon(":/images/find.png"),tr("اغلاق حساب اليوم"), this);
    connect(closeSystemAction, SIGNAL(triggered()), this, SIGNAL(closeSystemActionClicked()));

    aboutSystemAction = new QAction(QIcon(":/images/find.png"), tr("عن النظام"), this);
    connect(aboutSystemAction, SIGNAL(triggered()), this, SIGNAL(aboutSystemActionClicked()));

    QAction *returnOrderSystemAction = new QAction(QIcon(":/images/find.png"), tr("ارجاع الطلب"), this);
    connect(returnOrderSystemAction, SIGNAL(triggered()), this, SIGNAL(returnOrderSystemActionClicked()));

    QMenu *systemMenu = new QMenu(this);
    systemMenu->addAction(closeSystemAction);
    systemMenu->addAction(aboutSystemAction);
    systemMenu->addAction(returnOrderSystemAction);

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
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(homeButton);
    headerLayout->addWidget(reportsButton);
    headerLayout->addWidget(systemButton);
    headerLayout->addWidget(signOutButton);

    this->signalMapper->setMapping(backButton, 1);
    this->signalMapper->setMapping(homeButton, 2);
    this->signalMapper->setMapping(signOutButton, 3);

    connect(backButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(homeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signOutButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
}

void HeaderWidget::emitSignal(int id)
{
    switch (id) {
    case 1:
        emit backClicked();
        break;
    case 2:
        emit homeClicked();
        break;
    case 3:
        emit logoutClicked();
        break;
    }
}

void HeaderWidget::enableBackButton(bool value)
{
    backButton->setEnabled(value);
}

void HeaderWidget::enableUserButtons()
{
    reportsButton->setEnabled(false);
    closeSystemAction->setEnabled(false);
}

void HeaderWidget::enableAdminButtons()
{
    reportsButton->setEnabled(true);
    closeSystemAction->setEnabled(true);
}


