#ifndef ITEMSWIDGET_H
#define ITEMSWIDGET_H

#include <QWidget>

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;

class ItemsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemsWidget(QWidget *parent = 0);
    ~ItemsWidget();

    void createItems(int categoryId);

signals:
    void selectItem(int id);

private:
    enum {
        NumButtons = 100 , ButtonsPerLine = 6
    };

    QSignalMapper *signalMapper;
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout;
    QHBoxLayout* containerLayout;
    QVBoxLayout* subContainerLayout;

    void removeItems();
};

#endif // ITEMSWIDGET_H
