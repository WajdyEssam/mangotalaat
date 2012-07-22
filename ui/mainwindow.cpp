#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"
#include "SlidingStackedWidget.h"

#include <vector>
#include <QDebug>

#include "model/order.h"
#include "database/databasemanager.h"

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

    this->stackedWidget = new SlidingStackedWidget(this);
    this->stackedWidget->addWidget(this->categoriesWidget);
    this->stackedWidget->addWidget(this->itemsWidget);
    this->stackedWidget->addWidget(this->sizeWidget);
    this->stackedWidget->setSpeed(700);

    this->setCurrentPage(CategoryPage);
    this->setCentralWidget(this->stackedWidget);
}

void MainWindow::createDockWidgets()
{
    createHeaderDockWidget();
    createOrderDockWidget();
}

void MainWindow::createHeaderDockWidget()
{
    this->headerWidget = new HeaderWidget;
    connect(this->headerWidget, SIGNAL(homeClicked()), SLOT(ShowHomePage()));
    connect(this->headerWidget, SIGNAL(reportClicked()), SLOT(reportClickedSlot()));

    QDockWidget *headerDockWidget = new QDockWidget(this);
    headerDockWidget->setObjectName("headerDockWidget");
    headerDockWidget->setFloating(false);
    headerDockWidget->setTitleBarWidget(new QWidget);

    //headerDockWidget->setFixedWidth(220);
    //headerDockWidget->setFixedHeight(490);

    headerDockWidget->setWidget(this->headerWidget);
    this->addDockWidget(Qt::TopDockWidgetArea, headerDockWidget);
}

void MainWindow::createOrderDockWidget()
{
    QDockWidget *orderDockWidget = new QDockWidget(this);
    orderDockWidget->setObjectName("OrderDockWidget");
    orderDockWidget->setFloating(false);
    orderDockWidget->setTitleBarWidget(new QWidget);

    this->orderWidget = new OrderWidget;
    orderDockWidget->setWidget(this->orderWidget);
    this->addDockWidget(Qt::LeftDockWidgetArea, orderDockWidget);

    connect(this, SIGNAL(orderAdded(QList<Model::Order>)), orderWidget, SLOT(updateOrders(QList<Model::Order>)));
}

void MainWindow::ShowHomePage()
{
    this->setCurrentPage(CategoryPage);
}

void MainWindow::reportClickedSlot()
{
    computeTotalCash();
}


void MainWindow::setCurrentPage(WidgetPage page)
{
    this->stackedWidget->slideInIdx(page);
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
    connect(this->sizeWidget, SIGNAL(selectItemDetail(int)), this, SLOT(selectItemDetialSlot(int)));
}

void MainWindow::selectCategorySlot(int categorId)
{
    this->itemsWidget->createItems(categorId);
    this->setCurrentPage(ItemPage);
}

void MainWindow::selectItemSlot(int itemId)
{
    this->sizeWidget->createItemSizes(itemId);
    this->setCurrentPage(SizePage);
}

void MainWindow::selectItemDetialSlot(int itemDetialId)
{
    Model::Order order(itemDetialId);
    ItemPropertiesDialog *dialog = new ItemPropertiesDialog(order, true, this);
    dialog->setModal(true);
    dialog->exec();

    if ( !dialog->isCancelled() ) {
        Model::Order order = dialog->getOrder();

        this->orders.append(order);
        this->stackedWidget->setCurrentIndex(0);
        emit orderAdded(this->orders);
    }
}

void MainWindow::computeTotalCash()
{
    this->discount = 0;

    qDebug() << "you have a " << this->orders.size() << " Orders";
    int cash = 0;

    foreach(Model::Order order, this->orders) {
        cash += order.getCash();
    }

    int totalCash = cash - this->discount;
    QDateTime now = QDateTime::currentDateTime();

    Database::DatabaseManager database;
    bool ret = database.addOrder(now, 1, cash, discount, totalCash, this->orders);

    qDebug() << "New Order Status: " << ret;

    if ( ret ) {
        clearShoppingCart();
    }
}

void MainWindow::clearShoppingCart()
{
    this->orders.clear();
}

void MainWindow::computeFree()
{

}

void MainWindow::computeCupon()
{

}

void MainWindow::setDiscount()
{
    this->discount = 0;
}
