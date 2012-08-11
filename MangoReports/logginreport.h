#ifndef LOGGINREPORT_H
#define LOGGINREPORT_H

#include "MangoReports_global.h"
#include "report.h"

class MANGOREPORTSSHARED_EXPORT LogginReport: public Report
{
public:
    LogginReport(const QDateTime& from, const QDateTime& to);

    virtual QString getHTML();
    virtual QString getReportTemplateName();

private:
    QString getLogginTable();
};

#endif // LOGGINREPORT_H
