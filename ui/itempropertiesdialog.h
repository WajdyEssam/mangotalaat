#ifndef ITEMPROPERTIESDIALOG_H
#define ITEMPROPERTIESDIALOG_H

#include <QDialog>
#include "model/order.h"

namespace Ui {
    class ItemPropertiesDialog;
}

class ItemPropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemPropertiesDialog(Model::Order aOrder, bool newOrder, QWidget *parent = 0);
    ~ItemPropertiesDialog();

public :
    bool isCancelled() const { return isCancel; }
    Model::Order getOrder() const { return this->modifiedOrder; }

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ItemPropertiesDialog *ui;

private:
    bool isCancel;
    bool isNewOrder;
    Model::Order order;
    Model::Order modifiedOrder;

private:
    void fillDefualtComponentsAndAdditionalsForThisOrder();
    void fillModifiedComponentsAndAdditionalsForThisOrder();
    void fillAllComponentsAndAdditionalsFromStore();
    void fillCurrentItemDescription();

    QString getSugar();
    QStringList getNewAdditionalList();
    QStringList getNewComponentList();
};

#endif // ITEMPROPERTIESDIALOG_H
