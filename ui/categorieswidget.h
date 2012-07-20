#ifndef CATEGORIESWIDGET_H
#define CATEGORIESWIDGET_H

#include <QWidget>

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;

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
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout ;
    QHBoxLayout* containerLayout;
    QVBoxLayout* subContainerLayout;

    void removeCategories();

private slots:
    void setCurrentCategory(int id);

signals:
    void selectCategory(int id);
};

#endif // CATEGORIESWIDGET_H
