#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"
#include "SlidingStackedWidget.h"

#include <vector>
#include <QDebug>

#include "../../MangoModel/event.h"
#include "../../MangoModel/itemdetail.h"
#include "../../MangoService/order.h"
#include "../../MangoService/event.h"
#include "../../MangoService/checkout.h"
#include "../../MangoService/itemdetail.h"
#include "../../MangoService/orderdetail.h"

MainWindow::MainWindow(int userId, QWidget *parent) :
    QMainWindow(parent)
{
    m_userId = userId;

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

    orderWidget = new OrderWidget;
    orderDockWidget->setWidget(orderWidget);
    this->addDockWidget(Qt::LeftDockWidgetArea, orderDockWidget);

    connect(this, SIGNAL(orderDetailUpdated(QList<Model::OrderDetail>)), orderWidget, SLOT(updateOrderDetails(QList<Model::OrderDetail>)));
    connect(orderWidget, SIGNAL(orderItemClick(QString)), SLOT(orderItemClicked(QString)));
    connect(orderWidget, SIGNAL(applyClicked()), SLOT(applyOrderClickedSlot()));
    connect(orderWidget, SIGNAL(cancelClicked()), SLOT(cancelOrderClickedSlot()));
}

void MainWindow::addLoginEvent()
{
    Model::Event event;
    event.setUser(Model::User(m_userId));
    event.setCreatedDateTime(QDateTime::currentDateTime());
    event.setEventType(Model::Event::Login);

    Services::Event::add(event);
}

void MainWindow::AddLogoutEvent() {
    Model::Event event;
    event.setUser(Model::User(m_userId));
    event.setCreatedDateTime(QDateTime::currentDateTime());
    event.setEventType(Model::Event::Logout);

    Services::Event::add(event);
}

void MainWindow::ShowHomePage()
{
    this->setCurrentPage(CategoryPage);
}

void MainWindow::reportClickedSlot()
{
    // show reports
    // event logging table, order table, cancel table, summary table
//    Database::DatabaseManager database;
//    QList<QDateTime> times = database.getCheckoutTimes();

//    QList<Login> logins = database.getLoginReport(times.first(), QDateTime::currentDateTime());

//    foreach(Login login, logins) {
//        qDebug() << login.getId() << " , " << login.getUser().userName() << " , " << login.getEventTime() <<  " , "
//                 << login.getEventType();
//    }

//    QList<Order> orderReports = database.getOrderReport(times.first(), QDateTime::currentDateTime());
//    foreach(Order order, orderReports) {
//        qDebug() << order.id() << " , " << order.cash() << " , " << order.createdDateTime() ;
//    }

    // from points to points
    // from last point to current time
}

void MainWindow::systemClickedSlot()
{
    Services::Checkout::closeTodayOrders();
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
        if ( order.orderIndexId() == indexId )
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
    connect(this->propertyWidget, SIGNAL(updateItem(Model::OrderDetail)), this, SLOT(updateItemInCart(Model::OrderDetail)));
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
    Model::OrderDetail orderDetail = Services::OrderDetail::getEmptyOrderDetail(itemDetialId);
    this->propertyWidget->setOrder(orderDetail, false);
    this->setCurrentPage(PropertyPage);
}


void MainWindow::addItemToCart(Model::OrderDetail order)
{
    this->orderDetails.append(order);
    this->setCurrentPage(CategoryPage);
    emit orderDetailUpdated(this->orderDetails);
}

void MainWindow::updateItemInCart(Model::OrderDetail oldOrder)
{
    for(int i=0; i<this->orderDetails.size(); i++) {
        Model::OrderDetail order = this->orderDetails.at(i);
        if ( order.orderIndexId() == oldOrder.orderIndexId() ) {
            this->orderDetails.removeAt(i);
            break;
        }
    }

    this->orderDetails.append(oldOrder);
    this->setCurrentPage(CategoryPage);
    emit orderDetailUpdated(this->orderDetails);
}

void MainWindow::removeItemFromCart(Model::OrderDetail oldOrder)
{
    for(int i=0; i<this->orderDetails.size(); i++) {
        Model::OrderDetail order = this->orderDetails.at(i);

        if ( order.orderIndexId() == oldOrder.orderIndexId() ) {
            this->orderDetails.removeAt(i);
            break;
        }
    }

    this->setCurrentPage(CategoryPage);
    emit orderDetailUpdated(this->orderDetails);
}


void MainWindow::computeTotalCash()
{
    this->discount = 0;

    if ( this->orderDetails.isEmpty() )
        return;

    int cash = 0;

    foreach(Model::OrderDetail order, this->orderDetails) {
        cash += order.cash();
    }

    int totalCash = cash - this->discount;
    QDateTime now = QDateTime::currentDateTime();

    Model::Order order(0, now, Model::OrderType::CASH, cash, discount, totalCash, 0);
    bool ret = Services::Order::add(order, this->orderDetails);

    if ( ret ) {
        qDebug() << "New Order Status: " << ret << " Total cash: " << totalCash;
        printReceipt();
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

void MainWindow::printReceipt() {
    if ( this->orderDetails.empty())
        return;

    QString printApplicationPath = "ThermalPrinterTestApp.exe";
    QString outputFilename = "Data.txt";

    // write order detials to file
    int totalCash = 0;
    foreach(Model::OrderDetail order, this->orderDetails) {
        totalCash += order.cash();
    }

    QString cash = QString::number(totalCash);
    QString discount = "0.0";

    QFile file(outputFilename);

    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);

        QString firstLine = cash + " @ " + discount;
        stream << firstLine << endl;

        foreach(Model::OrderDetail order, this->orderDetails) {
            QString quantity = QString::number(order.qunatity());
            QString size = order.itemDetail().size().englishName().at(0).toUpper();
            QString itemName = order.itemDetail().item().englishName();
            QString description = "testing";
            QString price = QString::number(order.cash());

            QString itemLine = QString("%1 @ %2 @ %3 @ %4 @ %5").arg(quantity).arg(size).arg(itemName).arg(description).arg(price);
            stream << itemLine << endl;
        }

        file.close();

        QStringList arg;
        arg << outputFilename;
        QProcess *process = new QProcess(this);
        process->start(printApplicationPath, arg);
    }
}
