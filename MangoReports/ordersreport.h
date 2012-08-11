#ifndef ORDERSREPORT_H
#define ORDERSREPORT_H

#include "MangoReports_global.h"
#include "../MangoModel/order.h"
#include "../MangoService/order.h"
#include "report.h"

class MANGOREPORTSSHARED_EXPORT OrdersReport: public Report
{
public:
    OrdersReport(const QDateTime& from, const QDateTime& to);

    virtual QString getHTML();
    virtual QString getReportTemplateName();

private:
    QString getTableData();
};

#endif // ORDERSREPORT_H
