#include "logginreport.h"

#include "../MangoModel/event.h"
#include "../MangoService/event.h"
#include <QDebug>

LogginReport::LogginReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString LogginReport::getHTML()
{
    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%LOGIN_REPORT_TYPE%", "تقرير عن عمليات الدخول والخروج");
    orignalHTML = orignalHTML.replace("%LOGIN_TABLE%", getLogginTable());

    return orignalHTML;
}

QString LogginReport::getReportTemplateName()
{
    return ":/reports/LogginReport.html";
}

QString LogginReport::getLogginTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
           "<tr class=\"table_header\"><th>رقم العملية</th><th>اسم المستخدم</th><th>تاريخ العملية</th><th>نوع العملية</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    int loginCount = 0;
    int logoutCount = 0;

    QList<Model::Event> events = Services::Event::getBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Event event, events) {
        Model::Event::EventTypes type = event.eventType();
        QString eventType = type == Model::Event::Login ? "تسجيل دخول" : " خروج";

        if ( type == Model::Event::Login )
            loginCount++;
        else
            logoutCount++;

        QString tableRaw = QString(
            "<tr valign=\"top\"> "
            "<td align=\"center\"><font size=\"2\">%1</font></td> "
            "<td align=\"center\"><font size=\"2\">%2</font></td> "
            "<td align=\"center\"><font size=\"2\">%3</font></td> "
            "<td align=\"center\"><font size=\"2\">%4</font></td> "
            "</tr>"
        ).arg( QString::number(event.id()), event.user().userName(),
               event.createdDateTime().toString("dd/MM/yyyy h:m:s ap"), eventType);

        htmlTableResult += tableRaw ;
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}
