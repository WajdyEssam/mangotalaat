#include "mainwindow.h"
#include "headerwidget.h"
#include "orderwidget.h"
#include "SlidingStackedWidget.h"
#include "aboutdialog.h"
#include "invoiceveiwerwidget.h"
#include "returnorderdialog.h"
#include "selectperiddialog.h"
#include "employeedialog.h"

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

MainWindow::MainWindow(int id, QMainWindow* parentWindow, QWidget *parent) :
    QMainWindow(parent)
{
    m_parentWindow = parentWindow;
    this->m_userId = id;

    this->setWindowSize();
    this->createDockWidgets();
    this->createWidgetPages();
    this->disableButtonsForNotAuthenticatedUser();
    this->createStatusBar();
    this->establishConnections();
    this->addLoginEvent();
    this->setWindowTitle("مانجو طلعت");
}

MainWindow::~MainWindow()
{
}

void MainWindow::setWindowSize()
{
    this->setWindowState(Qt::WindowFullScreen); // WindowFullScreen
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
    connect(this->headerWidget, SIGNAL(addUserActionClicked()), SLOT(addUserClicked()));
    connect(this->headerWidget, SIGNAL(updateUserActionClicked()), SLOT(updateUserClicked()));
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

    orderWidget = new OrderWidget(m_userId);
    orderDockWidget->setWidget(orderWidget);
    this->addDockWidget(Qt::RightDockWidgetArea, orderDockWidget);

    connect(orderWidget, SIGNAL(orderItemClick(Model::OrderDetail)), SLOT(orderItemClicked(Model::OrderDetail)));
    connect(orderWidget, SIGNAL(showHomePage()), SLOT(showHomePage()));
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

void MainWindow::addUserClicked()
{
    EmployeeDialog dialog(EmployeeDialog::Add);
    dialog.exec();
}

void MainWindow::updateUserClicked()
{
    EmployeeDialog dialog(EmployeeDialog::Update);
    dialog.exec();
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

        this->orderWidget->updateQMLCart();
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::exit()
{
    if ( logout() ) {
        this->hide();
        this->deleteLater();
        this->m_parentWindow->show();
        this->m_parentWindow->setWindowState(Qt::WindowFullScreen);
    }
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

void MainWindow::orderItemClicked(Model::OrderDetail orderDetail)
{
    this->propertyWidget->setOrder(orderDetail, true);
    this->setCurrentPage(PropertyPage);
    Services::Helper::runSoundFile(Services::Helper::transitionSoundFile);
    headerWidget->enableBackButton(false);
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

    connect(this->propertyWidget, SIGNAL(addItem(Model::OrderDetail)), this->orderWidget, SLOT(addItemToCart(Model::OrderDetail)));
    connect(this->propertyWidget, SIGNAL(updateItem(Model::OrderDetail)), this->orderWidget, SLOT(updateItemInCart(Model::OrderDetail)));
    connect(this->propertyWidget, SIGNAL(removeItem(Model::OrderDetail)), this->orderWidget, SLOT(removeItemFromCart(Model::OrderDetail)));
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
