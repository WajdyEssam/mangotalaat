#ifndef CATEGORIESWIDGET_H
#define CATEGORIESWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>

class CategoriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoriesWidget(QWidget *parent = 0);
    ~CategoriesWidget();

private:
    void createCategories();


private:
    enum {
        NumButtons = 8 , ButtonsPerLine = 4
    };

    QSignalMapper *signalMapper;
    QPushButton *buttons[NumButtons];
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout ;

    void removeCategories();

private slots:
    void setCurrentCategory(int id);

signals:
    void selectCategory(int id);
};

#endif // CATEGORIESWIDGET_H
