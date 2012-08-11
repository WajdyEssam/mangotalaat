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
    QString getTableData();
};

#endif // GENERALREPORT_H
