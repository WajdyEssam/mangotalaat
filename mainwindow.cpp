#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include <vector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    // get all categories
//    Mango::DatabaseManager databaseManager;
//    std::vector<Mango::Category> categories = databaseManager.getCategories();
//    for(std::vector<Mango::Category>::iterator p = categories.begin();
//            p != categories.end(); ++p ) {
//        qDebug() << p->getId() << " : " << QString::fromStdString(p->getEnglishName());
//    }

//    // get all items in categories
//    int categoryId = 3;
//    std::vector<Mango::Item> items = databaseManager.getItemsInCategory(categoryId);
//    for(std::vector<Mango::Item>::iterator p = items.begin(); p != items.end(); ++p ) {
//        qDebug() << p->getId() << " : " << QString::fromStdString(p->getEnglishName()) << " " << p->getPrice();
//    }

//    // get item information
//    Mango::Item item = databaseManager.getItemDetails(15);
//    qDebug() << endl << item.getId() << " " << QString::fromStdString(item.getEnglishName()) << " " << item.getPrice();

    this->setWindowSize();
    this->addWidgets();
    this->addButtons();
    this->addStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWindowSize() {
    QRect screenRect = QApplication::desktop()->screenGeometry(QApplication::desktop()->primaryScreen());
    QRect windowRect(0, 0, 800, 600);

    if (screenRect.width() < 800)
        windowRect.setWidth(screenRect.width());
    if (screenRect.height() < 600)
        windowRect.setHeight(screenRect.height());

    windowRect.moveCenter(screenRect.center());

    this->setGeometry(windowRect);
    this->setMinimumSize(80, 60);
    this->setFixedSize(this->size().width(), this->size().height());
    this->setStyleSheet("MainWindow {background-image: url(:/images/dialog.png);}");
    this->setMaximumSize(QSize(this->width(), this->height()));
}

void MainWindow::addWidgets() {
    this->categoriesWidget = new CategoriesWidget;

    this->stackedWidget =new QStackedWidget(this);
    this->stackedWidget->addWidget(this->categoriesWidget);
    this->setCentralWidget(this->stackedWidget);
}

void MainWindow::addButtons() {
    this->signalMapper = new QSignalMapper(this);

    QDockWidget *headerDockWidget = new QDockWidget(this);
    headerDockWidget->setObjectName("headerDockWidget");
    headerDockWidget->setFloating(false);
    headerDockWidget->setTitleBarWidget(new QWidget);
    headerDockWidget->setFixedWidth(220);
    headerDockWidget->setFixedHeight(490);

    this->headerWidget = new QWidget;
    headerDockWidget->setWidget(this->headerWidget);
    this->addDockWidget(Qt::LeftDockWidgetArea, headerDockWidget);

//    // buttons size
//    int x = 19;
//    int y = 160 ;
//    int height = 72 ;
//    int width = 175;
//    int spaceBetweenButtons = 5 ;

//    QPushButton *welcomeButton = new QPushButton(this);
//    welcomeButton->setText("Registeration");
//    welcomeButton->setCheckable(true);
//    welcomeButton->setChecked(true);
//    welcomeButton->setGeometry(x,y,width,height);
//    welcomeButton->setObjectName("0_toolButton");
//    welcomeButton->setToolTip("Main Application");
//    welcomeButton->setStatusTip("QuickAuth");
//    connect(welcomeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
//    this->signalMapper->setMapping(welcomeButton, Welcome);

//    y += height + spaceBetweenButtons;

//    QPushButton *manageUsersButton = new QPushButton(this);
//    manageUsersButton->setText("Manage Users");
//    manageUsersButton->setCheckable(true);
//    manageUsersButton->setGeometry(x,y,width,height);
//    manageUsersButton->setObjectName("2_toolButton");
//    manageUsersButton->setToolTip("Manage Users");
//    manageUsersButton->setStatusTip("View and Delete Users");
//    connect(manageUsersButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
//    this->signalMapper->setMapping(manageUsersButton, Manage_User);

//    y += height + spaceBetweenButtons;

//    QPushButton *manageServiceButton = new QPushButton(this);
//    manageServiceButton->setText("Manage Service");
//    manageServiceButton->setGeometry(x,y,width,height);
//    manageServiceButton->setCheckable(true);
//    manageServiceButton->setObjectName("3_toolButton");
//    manageServiceButton->setToolTip("Manage the Camera");
//    manageServiceButton->setStatusTip("Start or Release the Camera");
//    connect(manageServiceButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
//    this->signalMapper->setMapping(manageServiceButton, Manage_Service);

//    connect(this->signalMapper, SIGNAL(mapped(int)), this, SLOT(setCurrentWindow(int)));
}

void MainWindow::addStatusBar() {
    this->versionLabel = new QLabel(this);
    this->statusBar()->showMessage("");
    this->statusBar()->addPermanentWidget(new QLabel("Mango Talaat - 2012"));
    this->statusBar()->addPermanentWidget(versionLabel);

    this->helpLabel = new QLabel(this);
    this->helpLabel->setOpenExternalLinks(true);
    this->helpLabel->setText(tr("Version 1.1"));
    this->statusBar()->addPermanentWidget(helpLabel);
}

void MainWindow::setCurrentWindow(int id){
    QString buttonName = QString::number(id) + "_toolButton";
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton* button,buttons) {
        if (button->objectName() == buttonName)
            button->setChecked(true);
        else
            button->setChecked(false);
    }

    this->stackedWidget->setCurrentIndex(id);
}

