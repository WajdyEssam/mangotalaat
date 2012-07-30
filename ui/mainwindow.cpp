#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"
#include "SlidingStackedWidget.h"

#include <vector>
#include <QDebug>

#include "model/orderdetail.h"
#include "database/databasemanager.h"
#include "model/login.h"

MainWindow::MainWindow(int aUserId, QWidget *parent) :
    QMainWindow(parent)
{
    this->userId = aUserId;

    this->setWindowSize();
    this->createWidgetPages();
    this->createDockWidgets();
    this->createStatusBar();
    this->establishConnections();
    this->addLoginEvent();
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
    this->propertyWidget = new PropertyWidget;

    this->stackedWidget = new SlidingStackedWidget(this);
    this->stackedWidget->addWidget(this->categoriesWidget);
    this->stackedWidget->addWidget(this->itemsWidget);
    this->stackedWidget->addWidget(this->sizeWidget);
    this->stackedWidget->addWidget(this->propertyWidget);

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
    connect(this->headerWidget, SIGNAL(systemClicked()), SLOT(systemClickedSlot()));
    connect(this->headerWidget, SIGNAL(logoutClicked()), SLOT(logoutClickedSlot()));

    QDockWidget *headerDockWidget = new QDockWidget(this);
    headerDockWidget->setObjectName("headerDockWidget");
    headerDockWidget->setFloating(false);
    headerDockWidget->setTitleBarWidget(new QWidget);

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

    connect(this, SIGNAL(orderDetailUpdated(QList<Model::OrderDetail>)), orderWidget, SLOT(updateOrderDetails(QList<Model::OrderDetail>)));
    connect(orderWidget, SIGNAL(orderItemClick(QString)), SLOT(orderItemClicked(QString)));
    connect(this->orderWidget, SIGNAL(applyClicked()), SLOT(applyOrderClickedSlot()));
    connect(this->orderWidget, SIGNAL(cancelClicked()), SLOT(cancelOrderClickedSlot()));
}

void MainWindow::addLoginEvent() {
    Database::DatabaseManager database;
    database.addLoginEventLogging(this->userId, QDateTime::currentDateTime(), 1);
}

void MainWindow::AddLogoutEvent() {
    Database::DatabaseManager database;
    database.addLoginEventLogging(this->userId, QDateTime::currentDateTime(), 2);
}

void MainWindow::ShowHomePage()
{
    this->setCurrentPage(CategoryPage);
}

void MainWindow::reportClickedSlot()
{
    // show reports
    // event logging table, order table, cancel table, summary table
    Database::DatabaseManager database;
    QList<QDateTime> times = database.getCheckoutTimes();

    QList<Login> logins = database.getLoginReport(times.first(), QDateTime::currentDateTime());

    foreach(Login login, logins) {
        qDebug() << login.getId() << " , " << login.getUser().getUsername() << " , " << login.getEventTime() <<  " , "
                 << login.getEventType();
    }

    QList<Order> orderReports = database.getOrderReport(times.first(), QDateTime::currentDateTime());
    foreach(Order order, orderReports) {
        qDebug() << order.getId() << " , " << order.getCash() << " , " << order.getOrderDate() ;
    }

    // from points to points
    // from last point to current time
}

void MainWindow::systemClickedSlot()
{
    Database::DatabaseManager database;
    database.closeTodayOrders(QDateTime::currentDateTime());
}

void MainWindow::logoutClickedSlot()
{
    this->AddLogoutEvent();
    qApp->quit();
}

void MainWindow::applyOrderClickedSlot()
{
    computeTotalCash();
}

void MainWindow::cancelOrderClickedSlot()
{
    clearShoppingCart();
}

void MainWindow::orderItemClicked(QString orderIndexId)
{
    Model::OrderDetail orderDetail = getOrderByIndexId(orderIndexId);
    this->propertyWidget->setOrder(orderDetail, true);
    this->setCurrentPage(PropertyPage);
}

Model::OrderDetail MainWindow::getOrderByIndexId(QString indexId) {
    foreach(Model::OrderDetail order, this->orderDetails) {
        if ( order.getOrderIndexId() == indexId )
            return order;
    }

    return this->orderDetails.at(0);
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
    connect(this->propertyWidget, SIGNAL(addItem(Model::OrderDetail)), this, SLOT(addItemToCart(Model::OrderDetail)));
    connect(this->propertyWidget, SIGNAL(updateItem(Model::OrderDetail,Model::OrderDetail)), this, SLOT(updateItemInCart(Model::OrderDetail,Model::OrderDetail)));
    connect(this->propertyWidget, SIGNAL(removeItem(Model::OrderDetail)), this, SLOT(removeItemFromCart(Model::OrderDetail)));
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
    Model::OrderDetail orderDetail(itemDetialId);
    this->propertyWidget->setOrder(orderDetail, false);
    this->setCurrentPage(PropertyPage);
}


void MainWindow::addItemToCart(Model::OrderDetail order)
{
    this->orderDetails.append(order);
    this->setCurrentPage(CategoryPage);
    emit orderDetailUpdated(this->orderDetails);
}

void MainWindow::updateItemInCart(OrderDetail oldOrder, OrderDetail newOrder)
{
    for(int i=0; i<this->orderDetails.size(); i++) {
        Model::OrderDetail order = this->orderDetails.at(i);
        if ( order.getOrderIndexId() == oldOrder.getOrderIndexId() ) {
            this->orderDetails.removeAt(i);
            break;
        }
    }

    this->orderDetails.append(newOrder);
    emit orderDetailUpdated(this->orderDetails);
}

void MainWindow::removeItemFromCart(OrderDetail oldOrder)
{
    for(int i=0; i<this->orderDetails.size(); i++) {
        Model::OrderDetail order = this->orderDetails.at(i);

        if ( order.getOrderIndexId() == oldOrder.getOrderIndexId() ) {
            this->orderDetails.removeAt(i);
            break;
        }
    }

    emit orderDetailUpdated(this->orderDetails);
}


void MainWindow::computeTotalCash()
{
    this->discount = 0;

    if ( this->orderDetails.isEmpty() )
        return;

    int cash = 0;

    foreach(Model::OrderDetail order, this->orderDetails) {
        cash += order.getCash();
    }

    int totalCash = cash - this->discount;
    QDateTime now = QDateTime::currentDateTime();

    Database::DatabaseManager database;
    bool ret = database.addOrder(now, 1, cash, discount, totalCash, this->orderDetails);

    qDebug() << "New Order Status: " << ret << " Total cash: " << totalCash;

    if ( ret ) {
        clearShoppingCart();
    }
}

void MainWindow::clearShoppingCart()
{
    this->orderDetails.clear();
    emit orderDetailUpdated(this->orderDetails);
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
