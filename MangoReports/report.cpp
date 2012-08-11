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

QString Report::replaceHeader(const QString& content) {
    QString TITLE = "Mango Talaat";
    QString COMPANY_NAME_EN = "Mango Talaat";
    QString OWNER_NAME = "Mohmmaed Allhowh";
    QString COMPANY_ADDRESS = "Riyadh, KSA";
    QString COMPANY_MOBILE = "0656444654";
    QString COMPANY_EMAIL = "test@gmail.com";

    QString reportCode = content.replace("%TITLE%", TITLE).replace("%COMPANY_NAME%",COMPANY_NAME_EN)
            .replace("%OWNER_NAME%", OWNER_NAME).replace("%COMPANY_ADDRESS%", COMPANY_ADDRESS)
            .replace("%COMPANY_MOBILE%", COMPANY_MOBILE).replace("%COMPANY_EMAIL%", COMPANY_EMAIL)
            .replace("%FROM_DATE%", this->m_from.toString()).replace("%TO_DATE%", this->m_to.toString())
            .replace("%DATE%", QDateTime::currentDateTime().toString());

    return reportCode;
}
