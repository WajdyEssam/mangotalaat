#include "report.h"

Report::Report(const QDateTime& from, const QDateTime& to)
{
    this->m_from = from;
    this->m_to = to;
}

QString Report::getTemplateFileContent()
{
    QFile *reportFile = new QFile(getReportTemplateName());

    if ( ! reportFile->open(QIODevice::ReadOnly | QIODevice::Text) ) {
        return "Error";
    }

    QString htmlContent = reportFile->readAll();
    return htmlContent;
}
