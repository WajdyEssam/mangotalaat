#ifndef ITEMPROPERTIESDIALOG_H
#define ITEMPROPERTIESDIALOG_H

#include <QDialog>
#include "model/orderdetail.h"

namespace Ui {
    class ItemPropertiesDialog;
}

class ItemPropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemPropertiesDialog(Model::OrderDetail aOrderDetail, bool newOrder, QWidget *parent = 0);
    ~ItemPropertiesDialog();

public :
    bool isCancelled() const { return isCancel; }
    Model::OrderDetail getOrder() const { return this->modifiedOrderDetail; }

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ItemPropertiesDialog *ui;

private:
    bool isCancel;
    bool isNewOrder;
    Model::OrderDetail orderDetail;
    Model::OrderDetail modifiedOrderDetail;

private:
    void fillDefualtComponentsAndAdditionalsForThisOrder();
    void fillModifiedComponentsAndAdditionalsForThisOrder();
    void fillAllComponentsAndAdditionalsFromStore();
    void fillCurrentItemDescriptionAndQuantity();

    QStringList getNewAdditionalList();
    QStringList getNewComponentList();
};

#endif // ITEMPROPERTIESDIALOG_H
