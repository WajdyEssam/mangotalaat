#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"
#include "SlidingStackedWidget.h"
#include "aboutdialog.h"
#include "invoiceveiwerwidget.h"
#include "returnorderdialog.h"
#include "selectperiddialog.h"
#include "discountdialog.h"

#include <vector>
#include <QDebug>
#include <QLocale>
#include <QTranslator>

#include "../../MangoModel/event.h"
#include "../../MangoModel/itemdetail.h"
#include "../../MangoService/order.h"
#include "../../MangoService/event.h"
#include "../../MangoService/checkout.h"
#include "../../MangoService/itemdetail.h"
#include "../../MangoService/orderdetail.h"
#include "../../MangoService/helper.h"
#include "../../MangoReports/report.h"
#include "../../MangoReports/logginreport.h"
#include "../../MangoReports/ordersdetailsreport.h"
#include "../../MangoReports/ordersreport.h"
#include "../../MangoReports/generalreport.h"

#include "../mangoapp.h"
#include "../language.h"

MainWindow::MainWindow(int userId, QWidget *parent) :
    QMainWindow(parent)
{
    m_userId = userId;

    this->setWindowSize();
    this->createDockWidgets();
    this->createWidgetPages();
    this->createStatusBar();
    this->establishConnections();
    this->addLoginEvent();
    this->disableButtonsForNotAuthenticatedUser();
    this->setWindowTitle("مانجو طلعت");
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
    connect(this->headerWidget, SIGNAL(backClicked()), SLOT(showPreviousPage()));
    connect(this->headerWidget, SIGNAL(homeClicked()), SLOT(showHomePage()));
    connect(this->headerWidget, SIGNAL(todayLogginReportActionClicked()), SLOT(todayLogginReportClickedSlot()));
    connect(this->headerWidget, SIGNAL(todayOrdersReportActionClicked()), SLOT(todayOrdersReportClickedSlot()));
    connect(this->headerWidget, SIGNAL(todayOrdersDetailsReportActionClicked()), SLOT(todayOrdersDetailsReportClickedSlot()));
    connect(this->headerWidget, SIGNAL(generalReportActionClicked()), SLOT(generalReportClickedSlot()));
    connect(this->headerWidget, SIGNAL(closeSystemActionClicked()), SLOT(checkoutSystemClickedSlot()));
    connect(this->headerWidget, SIGNAL(aboutSystemActionClicked()), SLOT(aboutSystemClickedSlot()));
    connect(this->headerWidget, SIGNAL(returnOrderSystemActionClicked()), SLOT(returnOrderSystemClickedSlot()));
    connect(this->headerWidget, SIGNAL(arabicLocaleClicked()), SLOT(arabicLocaleClicked()));
    connect(this->headerWidget, SIGNAL(englishLocaleClicked()), SLOT(englishLocaleClicked()));

    connect(this->headerWidget, SIGNAL(logoutClicked()), SLOT(exit()));

    QDockWidget *headerDockWidget = new QDockWidget(this);
    headerDockWidget->setObjectName("headerDockWidget");
    headerDockWidget->setFloating(false);
    headerDockWidget->setTitleBarWidget(new QWidget);

    headerDockWidget->setWidget(this->headerWidget);
    this->addDockWidget(Qt::TopDockWidgetArea, headerDockWidget);
}

void MainWindow::createOrderDockWidget()
{
    orderDockWidget = new QDockWidget(this);
    orderDockWidget->setObjectName("OrderDockWidget");
    orderDockWidget->setFloating(false);
    orderDockWidget->setTitleBarWidget(new QWidget);

    orderWidget = new OrderWidget;
    orderDockWidget->setWidget(orderWidget);
    this->addDockWidget(Qt::RightDockWidgetArea, orderDockWidget);

    connect(this, SIGNAL(orderDetailUpdated(QList<Model::OrderDetail>)), orderWidget, SLOT(updateOrderDetails(QList<Model::OrderDetail>)));
    connect(orderWidget, SIGNAL(orderItemClick(QString)), SLOT(orderItemClicked(QString)));
    connect(orderWidget, SIGNAL(applyClicked()), SLOT(applyOrderClickedSlot()));
    connect(orderWidget, SIGNAL(cancelClicked()), SLOT(cancelOrderClickedSlot()));
    connect(orderWidget, SIGNAL(applyDiscountClicked()), SLOT(applyDiscountOrderClickedSlot()));
}

void MainWindow::disableButtonsForNotAuthenticatedUser()
{
    if ( this->m_userId == 1 ) {
        this->headerWidget->enableAdminButtons();
    }
    else {
        this->headerWidget->enableUserButtons();
    }
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

void MainWindow::showPreviousPage()
{
    if (stackedWidget->currentIndex() > 0)
    {
        this->setCurrentPage((WidgetPage)(stackedWidget->currentIndex() - 1));
    }
}

void MainWindow::showHomePage()
{
    this->setCurrentPage(CategoryPage);
}

void MainWindow::todayLogginReportClickedSlot()
{
    QDateTime from = Services::Checkout::getAll().last().createdDateTime();
    QDateTime to = QDateTime::currentDateTime();
    Report* report = new LogginReport(from, to);
    InvoiceVeiwerWidget *viewer = new InvoiceVeiwerWidget(report);
    viewer->show();
}

void MainWindow::todayOrdersDetailsReportClickedSlot()
{
    QDateTime from = Services::Checkout::getAll().last().createdDateTime();
    QDateTime to = QDateTime::currentDateTime();
    Report* report = new OrdersDetailsReport(from, to);
    InvoiceVeiwerWidget *viewer = new InvoiceVeiwerWidget(report);
    viewer->show();
}

void MainWindow::todayOrdersReportClickedSlot()
{
    QDateTime from = Services::Checkout::getAll().last().createdDateTime();
    QDateTime to = QDateTime::currentDateTime();
    Report* report = new OrdersReport(from, to);
    InvoiceVeiwerWidget *viewer = new InvoiceVeiwerWidget(report);
    viewer->show();
}

void MainWindow::generalReportClickedSlot()
{
    SelectPeridDialog dialog;
    dialog.exec();
    if ( dialog.isAccepted() ) {
        QDateTime from = dialog.from();
        QDateTime to = dialog.to();
        Report* report = new GeneralReport(from, to);
        InvoiceVeiwerWidget *viewer = new InvoiceVeiwerWidget(report);
        viewer->show();
    }
}

void MainWindow::returnOrderSystemClickedSlot()
{
    QDateTime from = Services::Checkout::getAll().last().createdDateTime();
    QDateTime to = QDateTime::currentDateTime();
    ReturnOrderDialog dialog(from, to);
    dialog.exec();
}

void MainWindow::checkoutSystemClickedSlot()
{
    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("Close Today Account"),
                                                                  tr("Are you sure you want to close today accounts?"),
                                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (button == QMessageBox::No)
        return;

    QDateTime from = Services::Checkout::getAll().last().createdDateTime();
    Services::Checkout::closeTodayOrders();
    QDateTime to = Services::Checkout::getAll().last().createdDateTime();

    // display general reports
    Report* report = new GeneralReport(from, to);
    InvoiceVeiwerWidget *viewer = new InvoiceVeiwerWidget(report);
    viewer->show();
}

void MainWindow::aboutSystemClickedSlot()
{
    AboutDialog *aboutDlg = new AboutDialog(this);
    aboutDlg->exec();
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if ( logout() )
        event->accept();
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {

        if (Settings::Language::getCurrentLanguage() == Settings::Language::Arabic)
            this->addDockWidget(Qt::RightDockWidgetArea, orderDockWidget);
        else
            this->addDockWidget(Qt::LeftDockWidgetArea, orderDockWidget);

        emit orderDetailUpdated(this->orderDetails);
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::exit()
{
    if ( logout() )
        qApp->quit();
}

bool MainWindow::logout()
{
    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("Exit from application"),
                                                                  tr("Are you sure you want to close the application"),
                                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (button == QMessageBox::No)
        return false;

    Services::Helper::runSoundFile(Services::Helper::logoutSoundFile);
    this->AddLogoutEvent();
    return true;
}

void MainWindow::applyOrderClickedSlot()
{
    if (this->orderDetails.count() < 1) {
        QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("Apply the order"),
                                                                  tr("Are you sure you want to apply the order and print the invoice?"),
                                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (button == QMessageBox::No)
        return;

    computeTotalCash(0, Model::OrderType::CASH);
}

void MainWindow::cancelOrderClickedSlot()
{
    if (this->orderDetails.count() < 1) {
            QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    QMessageBox::StandardButton button = QMessageBox::warning(this,
                                                              tr("Cancel the order"),
                                                              tr("Are you sure you want to cancel the order?"),
                                                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (button == QMessageBox::No)
        return;

    clearShoppingCart();
    setCurrentPage(CategoryPage);
}

void MainWindow::applyDiscountOrderClickedSlot()
{
    if (this->orderDetails.count() < 1) {
            QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    int discount = 0;
    int totalCashBeforeDiscount = this->orderWidget->totalCash();
    Model::OrderType::OrderTypes orderType = Model::OrderType::DISCOUNT_VALUE;

    DiscountDialog dlg(totalCashBeforeDiscount);
    if (dlg.exec() == QDialog::Accepted) {
        discount = dlg.discount();
        orderType = dlg.orderType();
        computeTotalCash(discount, orderType);
    }
}

void MainWindow::orderItemClicked(QString orderIndexId)
{
    Model::OrderDetail orderDetail = getOrderByIndexId(orderIndexId);
    this->propertyWidget->setOrder(orderDetail, true);
    this->setCurrentPage(PropertyPage);
    Services::Helper::runSoundFile(Services::Helper::transitionSoundFile);
    headerWidget->enableBackButton(false);
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
    if (page == CategoryPage)
        headerWidget->enableBackButton(false);
    else
        headerWidget->enableBackButton(true);

    this->stackedWidget->slideInIdx(page);
    this->updateGeometry();
}

void MainWindow::createStatusBar()
{
    this->versionLabel = new QLabel(this);
    this->statusBar()->showMessage("");
    this->statusBar()->addPermanentWidget(new QLabel(tr("Mango Talaat - 2012")));
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
    Services::Helper::runSoundFile(Services::Helper::transitionSoundFile);
}

void MainWindow::selectItemSlot(int itemId)
{
    this->sizeWidget->createItemSizes(itemId);
    this->setCurrentPage(SizePage);
    Services::Helper::runSoundFile(Services::Helper::transitionSoundFile);
}

void MainWindow::selectItemDetialSlot(int itemDetialId)
{
    Model::OrderDetail orderDetail = Services::OrderDetail::getEmptyOrderDetail(itemDetialId);
    this->propertyWidget->setOrder(orderDetail, false);
    this->setCurrentPage(PropertyPage);
    Services::Helper::runSoundFile(Services::Helper::transitionSoundFile);
}

void MainWindow::arabicLocaleClicked()
{
    Settings::Language::setCurrentLanguage(Settings::Language::Arabic);
    this->setCurrentPage(CategoryPage);
}

void MainWindow::englishLocaleClicked()
{
    Settings::Language::setCurrentLanguage(Settings::Language::English);
    this->setCurrentPage(CategoryPage);
}


void MainWindow::addItemToCart(Model::OrderDetail order)
{
    this->orderDetails.append(order);
    this->setCurrentPage(CategoryPage);
    Services::Helper::runSoundFile(Services::Helper::addingSoundFile);
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
    Services::Helper::runSoundFile(Services::Helper::addingSoundFile);
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
    Services::Helper::runSoundFile(Services::Helper::removeSoundFile);
    emit orderDetailUpdated(this->orderDetails);
}


void MainWindow::computeTotalCash(int discount, Model::OrderType::OrderTypes orderType)
{
    if ( this->orderDetails.isEmpty() )
        return;

    int totalCashBeforeDiscount = 0;

    foreach(Model::OrderDetail order, this->orderDetails) {
        totalCashBeforeDiscount += order.cash();
    }

    int totalCashAfterDiscount = totalCashBeforeDiscount - discount;

    Model::Order order(0, QDateTime::currentDateTime(), orderType, totalCashBeforeDiscount, discount, totalCashAfterDiscount, 0);

    bool ret = Services::Order::add(order, this->orderDetails);
    if ( ret ) {
        Services::Helper::runSoundFile(Services::Helper::checkoutSoundFile);
        printReceipt(discount);
        clearShoppingCart();
    }

    setCurrentPage(CategoryPage);
    QMessageBox::information(this, tr("Operation done successully"), tr("System is ready to accept new orders"), QMessageBox::Ok, QMessageBox::Ok);
}

void MainWindow::clearShoppingCart()
{
    this->orderDetails.clear();
    Services::Helper::runSoundFile(Services::Helper::clearSoundFile);
    emit orderDetailUpdated(this->orderDetails);
}


void MainWindow::printReceipt(int totalDiscount) {
    if ( this->orderDetails.empty())
        return;

    // file format
    // cash @ discount @ total
    // quantity @ size @ itemname @ sugar @ price @ component @ additional

    QString printApplicationPath = "ThermalPrinterTestApp.exe";
    QString outputFilename = "Data.txt";

    // write order detials to file
    int totalCashBeforeDiscount = 0;
    foreach(Model::OrderDetail order, this->orderDetails) {
        totalCashBeforeDiscount += order.cash();
    }

    QString cash = QString::number(totalCashBeforeDiscount);
    QString discount = QString::number(totalDiscount);
    QString total = QString::number(totalCashBeforeDiscount - totalDiscount);

    QFile file(outputFilename);

    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);

        QString firstLine = cash + " @ " + discount + " @ " + total;
        stream << firstLine << endl;

        foreach(Model::OrderDetail order, this->orderDetails) {
            QString quantity = QString::number(order.qunatity());
            QString size = order.itemDetail().size().englishName().at(0).toUpper();

            // handle GALLON size
            if ( order.itemDetail().size().id() == (int) Model::Size::GALLON_5L )
                size = "5L";
            else if (order.itemDetail().size().id() == (int) Model::Size::GALLON_1_HALF_L)
                size = "1.5L";
            else if ( order.itemDetail().size().id() == (int) Model::Size::GALLON_10L )
                size = "10L";

            // item name
            QString itemName = order.itemDetail().item().englishName();
            QString sugar = QString::number(order.sugar().id()-1);
            QString components = "#C:" + Services::Helper::fromComponentsToTextEn(order.components()) + "";
            QString additional = "#A:" + Services::Helper::fromAdditionalsToTextEn(order.additionals()) + "";
            QString price = QString::number(order.cash());

            QString itemLine = QString("%1 @ %2 @ %3 @ %4 @ %5 @ %6 @ %7")
                    .arg(quantity).arg(size).arg(itemName).arg(sugar).arg(price)
                    .arg(components).arg(additional);
            stream << itemLine << endl;
        }

        file.close();

        QStringList arg;
        arg << outputFilename;
        QProcess *process = new QProcess(this);
        process->start(printApplicationPath, arg);

        QThread::msleep(700);

        QProcess *process2 = new QProcess(this);
        process2->start(printApplicationPath, arg);
    }
}
