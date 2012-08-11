#ifndef ORDERSDETAILSREPORT_H
#define ORDERSDETAILSREPORT_H

#include "MangoReports_global.h"
#include "report.h"

class MANGOREPORTSSHARED_EXPORT OrdersDetailsReport: public Report
{
public:
    OrdersDetailsReport(const QDateTime& from, const QDateTime& to);

    virtual QString getHTML();
    virtual QString getReportTemplateName();

private:
    QString getTableData();
};

#endif // ORDERSDETAILSREPORT_H
