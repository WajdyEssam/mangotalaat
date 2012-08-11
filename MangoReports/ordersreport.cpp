#include "ordersreport.h"

#include "../MangoModel/event.h"
#include "../MangoService/event.h"
#include <QDebug>

OrdersReport::OrdersReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString OrdersReport::getHTML()
{
    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%ORDER_REPORT_TYPE%", "Orders Report");
    orignalHTML = orignalHTML.replace("%ORDER_TABLE%", getTableData());

    return orignalHTML;
}

QString OrdersReport::getReportTemplateName()
{
    return ":/reports/OrdersReport.html";
}

QString OrdersReport::getTableData()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr><th>Id</th><th>Username</th><th>Date</th><th>Actions</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Event> events = Services::Event::getAll();
    foreach(Model::Event event, events) {
        Model::Event::EventTypes type = event.eventType();
        QString eventType = type == Model::Event::Login ? "Loggin" : " Logout";

        QString tableRaw = QString(
            "<tr valign=\"top\"> "
            "<td align=\"center\"><font size=\"2\">%1</font></td> "
            "<td align=\"center\"><font size=\"2\">%2</font></td> "
            "<td align=\"center\"><font size=\"2\">%3</font></td> "
            "<td align=\"center\"><font size=\"2\">%4</font></td> "
            "</tr>"
        ).arg( QString::number(event.id()), event.user().userName(), event.createdDateTime().toString(), eventType);

        htmlTableResult += tableRaw ;
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}
