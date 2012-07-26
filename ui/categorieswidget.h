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

private:

    enum {
        NumButtons = 8 , ButtonsPerLine = 4
    };

    QSignalMapper *signalMapper;
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout ;
    QHBoxLayout* containerLayout;
    QVBoxLayout* subContainerLayout;

    void createCategories();
    void removeCategories();

signals:
    void selectCategory(int id);
};

#endif // CATEGORIESWIDGET_H
