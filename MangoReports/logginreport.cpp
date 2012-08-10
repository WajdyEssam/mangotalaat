#include "logginreport.h"

LogginReport::LogginReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString LogginReport::getHTML()
{

}

QString LogginReport::getReportTemplateName()
{
    return ":/reports/LogginReport.html";
}
