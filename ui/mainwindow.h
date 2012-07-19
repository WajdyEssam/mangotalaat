#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"
#include "itempropertiesdialog.h"

class HeaderWidget;
class OrderWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum WidgetPage {
        CategoryPage = 0,
        ItemPage = 1,
        SizePage = 2
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSignalMapper *signalMapper;
    HeaderWidget *headerWidget;
    OrderWidget* orderWidget;
    QStackedWidget *stackedWidget;

    CategoriesWidget* categoriesWidget;
    ItemsWidget* itemsWidget;
    SizeWidget* sizeWidget;

    QLabel *versionLabel;
    QLabel *helpLabel;

private:
    void setWindowSize();
    void createWidgetPages();
    void createDockWidgets();
    void createStatusBar();
    void establishConnections();

    void createHeaderDockWidget();
    void createOrderDockWidget();

    void setCurrentPage(WidgetPage page);

private slots:
    void ShowHomePage();

public slots:
    void selectCategorySlot(int categoryId);
    void selectItemSlot(int itemId);
    void selectItemDetialSlot(int itemDetialId);
};

#endif // MAINWINDOW_H
