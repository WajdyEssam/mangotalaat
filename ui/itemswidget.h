#ifndef ITEMSWIDGET_H
#define ITEMSWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>

class ItemsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemsWidget(QWidget *parent = 0);
    ~ItemsWidget();

public:
    void createItems(int categoryId);

private:
    enum {
        NumButtons = 100 , ButtonsPerLine = 4
    };

    QSignalMapper *signalMapper;
    QPushButton *buttons[NumButtons];
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout;

    void removeItems();

private slots:
    void setCurrentItem(int id);

signals:
    void selectItem(int id);
};

#endif // ITEMSWIDGET_H
