#include "categorieswidget.h"
#include "ui_categorieswidget.h"

#include "mango.h"

CategoriesWidget::CategoriesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoriesWidget)
{
    ui->setupUi(this);
    this->addWidgets();
}

CategoriesWidget::~CategoriesWidget()
{
    delete ui;
}

void CategoriesWidget::addWidgets(){
    this->horizontalGroupBox = new QGroupBox(tr("Categories"));
    QGridLayout *layout = new QGridLayout;

    // get all categories
    Mango::DatabaseManager databaseManager;
    std::vector<Mango::Category> categories = databaseManager.getCategories();

    int i=0, col = 0, row = 1;
    for(std::vector<Mango::Category>::iterator p = categories.begin();
            p != categories.end(); ++p ) {

        buttons[i] = new QPushButton(QString::fromStdString(p->getEnglishName()));
        layout->addWidget(buttons[i], row, col);

        col++;

        if ( col % ButtonsPerLine == 0) {
            row++;
            col = 0;
        }
    }

    this->horizontalGroupBox->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBox);
    this->setLayout(mainLayout);

}
