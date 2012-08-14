#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"
#include "propertywidget.h"

#include "../../MangoModel/orderdetail.h"

class HeaderWidget;
class OrderWidget;
class SlidingStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum WidgetPage {
        CategoryPage = 0,
        ItemPage = 1,
        SizePage = 2,
        PropertyPage = 3
    };

    explicit MainWindow(int aUserId, QWidget *parent = 0);
    ~MainWindow();

signals:
    void orderDetailUpdated(QList<Model::OrderDetail> orderDetails);


private slots:
    void showPreviousPage();
    void showHomePage();
    void orderItemClicked(QString orderIndexId);
    void todayLogginReportClickedSlot();
    void todayOrdersReportClickedSlot();
    void todayOrdersDetailsReportClickedSlot();
    void generalReportClickedSlot();
    void closeSystemClickedSlot();
    void aboutSystemClickedSlot();
    void logoutClickedSlot();
    void applyOrderClickedSlot();
    void cancelOrderClickedSlot();
    void selectCategorySlot(int categoryId);
    void selectItemSlot(int itemId);
    void selectItemDetialSlot(int itemDetialId);
    //void updateItemDetialSlot(Model::OrderDetail order);
    void addItemToCart(Model::OrderDetail);
    void updateItemInCart(Model::OrderDetail);
    void removeItemFromCart(Model::OrderDetail);
    void printReceipt();

private:
    QSignalMapper *signalMapper;
    HeaderWidget *headerWidget;
    OrderWidget* orderWidget;
    SlidingStackedWidget *stackedWidget;

    CategoriesWidget* categoriesWidget;
    ItemsWidget* itemsWidget;
    SizeWidget* sizeWidget;
    PropertyWidget* propertyWidget;

    QLabel *versionLabel;
    QLabel *helpLabel;

    QList<Model::OrderDetail> orderDetails;
    int discount ;
    int m_userId;
    Model::OrderDetail getOrderByIndexId(QString indexId);

    void setWindowSize();
    void createWidgetPages();
    void createDockWidgets();
    void createStatusBar();
    void establishConnections();
    void createHeaderDockWidget();
    void createOrderDockWidget();
    void setCurrentPage(WidgetPage page);
    void addLoginEvent();
    void AddLogoutEvent();
    //void updateOrder(Model::OrderDetail oldOrder, Model::OrderDetail newOrder);
    void computeTotalCash();
    void computeFree();
    void computeCupon();
    void setDiscount();
    void clearShoppingCart();
};

#endif // MAINWINDOW_H
