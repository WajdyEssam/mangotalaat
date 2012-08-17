#include "headerwidget.h"
#include "../language.h"
#include <QDebug>

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
    retranslateUi();
}

void HeaderWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QLinearGradient background(0,0, 0,100);
    background.setColorAt(0, QColor("black"));
    background.setColorAt(1, QColor(65,65,65));
    p.fillRect(QRect(0,0,width(),100), QBrush(background));
}

void HeaderWidget::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange) {
        retranslateUi();
    }

    QWidget::changeEvent(event);
}

void HeaderWidget::init()
{
    this->setObjectName("headerWidget");
    this->signalMapper = new QSignalMapper(this);
    this->setFixedHeight(100);
    this->createToolButtons();
    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(emitSignal(int)));
}

void HeaderWidget::retranslateUi()
{
    backButton->setText(tr("Back"));
    backButton->setToolTip(backButton->text());
    backButton->setStatusTip(backButton->toolTip());
    backButton->setIcon((Settings::Language::getCurrentLanguage() == Settings::Language::Arabic) ? QIcon(":/images/back_ar.png") : QIcon(":/images/back_en.png"));

    homeButton->setText(tr("Start"));
    homeButton->setToolTip(homeButton->text());
    homeButton->setStatusTip(homeButton->toolTip());

    reportsButton->setText(tr("Reports"));
    reportsButton->setToolTip(reportsButton->text());
    reportsButton->setStatusTip(reportsButton->toolTip());

    systemButton->setText(tr("System"));
    systemButton->setToolTip(systemButton->text());
    systemButton->setStatusTip(systemButton->toolTip());

    exitButton->setText(tr("Exit"));
    exitButton->setToolTip(exitButton->text());
    exitButton->setStatusTip(exitButton->toolTip());

    todayLogginReportAction->setText(tr("Logins daily report"));
    todayOrdersReportAction->setText(tr("Orders daily report"));
    todayOrdersDetailsReportAction->setText(tr("Order details daily report"));
    generalReportAction->setText(tr("Complete report"));
    closeSystemAction->setText(tr("Close today accounts"));
    aboutSystemAction->setText(tr("About System"));
    returnOrderSystemAction->setText(tr("Return Order"));
    arabicLocaleAct->setText(tr("Arabic"));
    englishLocaleAct->setText(tr("English"));
}

void HeaderWidget::createToolButtons()
{
    QFont font("Hacen Liner Print-out Light", 12, QFont::Normal);

    backButton = new QToolButton;
    backButton->setIcon(QIcon(":/images/back_ar.png"));
    backButton->setIconSize(QSize(64,64));
    backButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    backButton->setFont(font);

    homeButton = new QToolButton;
    homeButton->setIcon(QIcon(":/images/system.png"));
    homeButton->setIconSize(QSize(64,64));
    homeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    homeButton->setFont(font);

    reportsButton = new QToolButton;
    reportsButton->setIcon(QIcon(":/images/report.png"));
    reportsButton->setIconSize(QSize(64,64));
    reportsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    reportsButton->setFont(font);

    // add menu for report button
    todayLogginReportAction = new QAction(QIcon(":/images/find.png"),tr("Logins daily report"), this);
    connect(todayLogginReportAction, SIGNAL(triggered()), this, SIGNAL(todayLogginReportActionClicked()));

    todayOrdersReportAction = new QAction(QIcon(":/images/find.png"),tr("Orders daily report"), this);
    connect(todayOrdersReportAction, SIGNAL(triggered()), this, SIGNAL(todayOrdersReportActionClicked()));

    todayOrdersDetailsReportAction = new QAction(QIcon(":/images/find.png"),tr("Order details daily report"), this);
    connect(todayOrdersDetailsReportAction, SIGNAL(triggered()), this, SIGNAL(todayOrdersDetailsReportActionClicked()));

    generalReportAction = new QAction(QIcon(":/images/find.png"),tr("Complete report"), this);
    connect(generalReportAction, SIGNAL(triggered()), this, SIGNAL(generalReportActionClicked()));

    QMenu *reportMenu = new QMenu(this);
    reportMenu->addAction(todayLogginReportAction);
    reportMenu->addAction(todayOrdersReportAction);
    reportMenu->addAction(todayOrdersDetailsReportAction);
    reportMenu->addSeparator();
    reportMenu->addAction(generalReportAction);

    reportsButton->setMenu(reportMenu);
    reportsButton->setPopupMode(QToolButton::InstantPopup);

    systemButton = new QToolButton;
    systemButton->setIcon(QIcon(":/images/accounting.png"));
    systemButton->setIconSize(QSize(64,64));
    systemButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    systemButton->setFont(font);

    // add menu for system button
    closeSystemAction = new QAction(QIcon(":/images/find.png"),tr("Close today accounts"), this);
    connect(closeSystemAction, SIGNAL(triggered()), this, SIGNAL(closeSystemActionClicked()));

    aboutSystemAction = new QAction(QIcon(":/images/find.png"), tr("About System"), this);
    connect(aboutSystemAction, SIGNAL(triggered()), this, SIGNAL(aboutSystemActionClicked()));

    returnOrderSystemAction = new QAction(QIcon(":/images/find.png"), tr("Return Order"), this);
    connect(returnOrderSystemAction, SIGNAL(triggered()), this, SIGNAL(returnOrderSystemActionClicked()));

    QActionGroup* localeGroup = new QActionGroup(this);

    arabicLocaleAct = new QAction(QIcon(":/images/ar.png"), tr("Arabic"), localeGroup);
    arabicLocaleAct->setCheckable(true);
    connect(arabicLocaleAct, SIGNAL(triggered()), this, SIGNAL(arabicLocaleClicked()));

    englishLocaleAct = new QAction(QIcon(":/images/en.png"), tr("English"), localeGroup);
    englishLocaleAct->setCheckable(true);
    connect(englishLocaleAct, SIGNAL(triggered()), this, SIGNAL(englishLocaleClicked()));

    if (Settings::Language::getCurrentLanguage() == Settings::Language::Arabic)
        arabicLocaleAct->setChecked(true);
    else
        englishLocaleAct->setChecked(true);

    QMenu *systemMenu = new QMenu(this);
    systemMenu->addAction(closeSystemAction);
    systemMenu->addAction(returnOrderSystemAction);
    systemMenu->addSeparator();
    systemMenu->addAction(arabicLocaleAct);
    systemMenu->addAction(englishLocaleAct);
    systemMenu->addSeparator();
    systemMenu->addAction(aboutSystemAction);

    systemButton->setMenu(systemMenu);
    systemButton->setPopupMode(QToolButton::InstantPopup);

    exitButton = new QToolButton;
    exitButton->setIcon(QIcon(":/images/logout.png"));
    exitButton->setIconSize(QSize(64,64));
    exitButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    exitButton->setFont(font);

    QHBoxLayout* headerLayout = new QHBoxLayout(this);
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(homeButton);
    headerLayout->addWidget(reportsButton);
    headerLayout->addWidget(systemButton);
    headerLayout->addWidget(exitButton);

    this->signalMapper->setMapping(backButton, 1);
    this->signalMapper->setMapping(homeButton, 2);
    this->signalMapper->setMapping(exitButton, 3);

    connect(backButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(homeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(exitButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
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


