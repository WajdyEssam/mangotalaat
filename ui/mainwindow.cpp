#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"

#include <vector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowSize();
    this->createWidgetPages();
    this->createDockWidgets();
    this->createStatusBar();
    this->establishConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setWindowSize()
{
    this->setWindowState(Qt::WindowMaximized); // WindowFullScreen
    this->setStyleSheet("MainWindow {background-image: url(:/images/background.png);}");
}

void MainWindow::createWidgetPages()
{
    this->categoriesWidget = new CategoriesWidget;
    this->itemsWidget = new ItemsWidget;
    this->sizeWidget = new SizeWidget;

    this->stackedWidget =new QStackedWidget(this);
    this->stackedWidget->addWidget(this->categoriesWidget);
    this->stackedWidget->addWidget(this->itemsWidget);
    this->stackedWidget->addWidget(this->sizeWidget);

    this->stackedWidget->setCurrentWidget(this->categoriesWidget);
    this->setCentralWidget(this->stackedWidget);
}

void MainWindow::createDockWidgets()
{
    createHeaderDockWidget();
    createOrderDockWidget();
}

void MainWindow::createHeaderDockWidget()
{
    QDockWidget *headerDockWidget = new QDockWidget(this);
    headerDockWidget->setObjectName("headerDockWidget");
    headerDockWidget->setFloating(false);
    headerDockWidget->setTitleBarWidget(new QWidget);

    //headerDockWidget->setFixedWidth(220);
    //headerDockWidget->setFixedHeight(490);

    this->headerWidget = new HeaderWidget;
    headerDockWidget->setWidget(this->headerWidget);
    this->addDockWidget(Qt::TopDockWidgetArea, headerDockWidget);
}

void MainWindow::createOrderDockWidget()
{
    QDockWidget *orderDockWidget = new QDockWidget(this);
    orderDockWidget->setObjectName("OrderDockWidget");
    orderDockWidget->setFloating(false);
    orderDockWidget->setTitleBarWidget(new QWidget);
    orderDockWidget->setFixedWidth(220);
    orderDockWidget->setFixedHeight(490);

    this->orderWidget = new OrderWidget;
    orderDockWidget->setWidget(this->orderWidget);
    this->addDockWidget(Qt::LeftDockWidgetArea, orderDockWidget);
}

void MainWindow::createStatusBar()
{
    this->versionLabel = new QLabel(this);
    this->statusBar()->showMessage("");
    this->statusBar()->addPermanentWidget(new QLabel("Mango Talaat - 2012"));
    this->statusBar()->addPermanentWidget(versionLabel);

    this->helpLabel = new QLabel(this);
    this->helpLabel->setOpenExternalLinks(true);
    this->helpLabel->setText(tr("Version 1.1"));
    this->statusBar()->addPermanentWidget(helpLabel);
}

void MainWindow::establishConnections()
{
    connect(this->categoriesWidget, SIGNAL(selectCategory(int)), this, SLOT(selectCategorySlot(int)));
    connect(this->itemsWidget, SIGNAL(selectItem(int)), this, SLOT(selectItemSlot(int)));
}

void MainWindow::selectCategorySlot(int id)
{
    qDebug() << "The Selected Category Id: " << id;
    this->itemsWidget->addWidgets(id);
    this->stackedWidget->setCurrentIndex(1);
}

void MainWindow::selectItemSlot(int id)
{
    qDebug() << "The Selected Item Id: " << id;
    this->stackedWidget->setCurrentIndex(2);
}

