#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>

#include "../../MangoModel/orderdetail.h"

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;
class QPushButton;
class QLineEdit;
class QLabel;
class QLCDNumber;

class PropertyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyWidget(QWidget *parent = 0);
    
signals:
    void addItem(Model::OrderDetail);
    void updateItem(Model::OrderDetail);
    void removeItem(Model::OrderDetail);

public slots:
    void setOrder(Model::OrderDetail orderDetail, bool isOpenedInEditMode);
    void setCurrentComponent(int);
    void setCurrentAdditional(int);
    void addItemClicked();
    void updateItemClicked();
    void removeItemClicked();
    void openKeypadDialog();
    void openSugarDialog();

private:
    enum {
        NumButtons = 8 , ButtonsPerLine = 6
    };

    QSignalMapper *componentSignalMapper;
    QSignalMapper *additionalSignalMapper;

    QGroupBox *orderGroupBox;
    QGroupBox *componentsGroupBox;
    QGroupBox *additionalsGroupBox;

    QVBoxLayout* orderDetailVBoxLayout;
    QVBoxLayout *orderControlVBoxLayout;
    QGridLayout *componentsGridLayout;
    QGridLayout *additionalsGridLayout;

    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* removeButton;

    QLabel* itemNameLabel;
    QLabel* itemComponentsLabel;
    QLabel* itemAdditionalsLabel;

    QLCDNumber* itemQuantityLCDNumber;
    QLCDNumber* itemPriceLCDNumber;
    QLCDNumber* itemSugarLCDNumber;
    QLCDNumber* totalPriceLCDNumber;

    Model::OrderDetail m_orderDetail;

    void updateItemPriceForSpecialCocktail();
    int getLargestComponentsPrice(QList<Model::Component>& components, Model::Size size);

    void initOrderDetailsUI();
    void initCommandButtonsUI();
    void initOrderControlUI();
    void initComponentsUI();
    void initAdditionalsUI();

    void uncheckComponentsButtons();
    void uncheckAdditionalsButtons();
    void clearItemDetailsLineEdit();

    void recheckComponentsButtons();
    void recheckAdditionalsButtons();
    void fillItemDetialsLineEdit();
    void calculateTotalPrice();

    void showEditButton();
    void showAddButton();

    QList<Model::Component> readActiveComponents();
    QList<Model::Additional> readActiveAdditionals();
    Model::Sugar readSugar();
    int readQunatity();

};

#endif // PROPERTYWIDGET_H
