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
    return replaceHeader(htmlContent);
}

QString Report::replaceHeader(QString& content) {
    QString TITLE = "Mango Talaat";
    QString COMPANY_NAME_EN = "Mango Talaat";
    QString COMPANY_MOBILE = "0593613994";
    QString COMPANY_EMAIL = "sales@mangotalaat.com";
    QString COMPANY_ADDRESS = "الرياض - المملكة العربية السعودية";
    QString COMPANY_LOCATION = "فرع حي الغدير";

    QString reportCode = content.replace("%TITLE%", TITLE).replace("%COMPANY_NAME_EN%",COMPANY_NAME_EN)
            .replace("%COMPANY_MOBILE%", COMPANY_MOBILE).replace("%COMPANY_EMAIL%", COMPANY_EMAIL)
            .replace("%COMPANY_ADDRESS%", COMPANY_ADDRESS).replace("%COMPANY_LOCATION%", COMPANY_LOCATION)
            .replace("%FROM_DATE%", this->m_from.toString("dd/MM/yyyy h:m:s ap")).replace("%TO_DATE%", this->m_to.toString("dd/MM/yyyy h:m:s ap"))
            .replace("%DATE%", QDateTime::currentDateTime().toString("dd/MM/yyyy h:m:s ap"));

    return reportCode;
}
