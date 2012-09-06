#ifndef GENERALREPORT_H
#define GENERALREPORT_H

#include "MangoReports_global.h"
#include "report.h"

class MANGOREPORTSSHARED_EXPORT GeneralReport: public Report
{
public:
    GeneralReport(const QDateTime& from, const QDateTime& to);

    virtual QString getHTML();
    virtual QString getReportTemplateName();

private:
    QString getLogginTable();
    QString getOrdersDetailsTable();
    QString getOrdersTable();
    QString getGlassTable();
    bool isCountableGlass(int categoryId);

private:
    int totalCash;
    int totalDiscount;
};

#endif // GENERALREPORT_H
