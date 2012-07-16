#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowSize();
    this->addWidgets();
    this->addButtons();
    this->addStatusBar();
    this->addSignals();
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
    this->setWindowState(Qt::WindowMaximized); // WindowFullScreen
    //this->setStyleSheet("MainWindow {background-image: url(:/images/dialog.png);}");
    this->setMaximumSize(QSize(this->width(), this->height()));
}

void MainWindow::addWidgets() {
    this->categoriesWidget = new CategoriesWidget;
    this->itemsWidget = new ItemsWidget;
    this->sizeWidget = new SizeWidget;

    this->stackedWidget =new QStackedWidget(this);
    this->stackedWidget->addWidget(this->categoriesWidget);
    this->stackedWidget->addWidget(this->itemsWidget);
    this->stackedWidget->addWidget(this->sizeWidget);

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

void MainWindow::addSignals(){
    connect(this->categoriesWidget, SIGNAL(selectCategory(int)), this, SLOT(selectCategorySlot(int)));
    connect(this->itemsWidget, SIGNAL(selectItem(int)), this, SLOT(selectItemSlot(int)));
}

void MainWindow::selectCategorySlot(int id) {
    qDebug() << "The Selected Category Id: " << id;
    this->itemsWidget->addWidgets(id);
    this->stackedWidget->setCurrentIndex(1);
}

void MainWindow::selectItemSlot(int id) {
    qDebug() << "The Selected Item Id: " << id;
    this->stackedWidget->setCurrentIndex(2);
}

