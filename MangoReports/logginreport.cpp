#include "logginreport.h"

LogginReport::LogginReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString LogginReport::getHTML()
{
    QString orignalHTML = getTemplateFileContent();
    originalHtml = orignalHTML.replace("%LOGIN_REPORT_TYPE%", "Loging Report");

    return orignalHTML;
}

QString LogginReport::getReportTemplateName()
{
    return ":/reports/LogginReport.html";
}
