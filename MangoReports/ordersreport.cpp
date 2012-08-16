#include "ordersreport.h"

#include <QDebug>
#include <QString>

OrdersReport::OrdersReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString OrdersReport::getHTML()
{
    this->totalCash = 0;

    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%ORDER_REPORT_TYPE%", "تقرير عن الطلبات");
    orignalHTML = orignalHTML.replace("%ORDER_TABLE%", getOrdersTable());

    QString cashString = "<b>الإجمالي هو " + QString::number(this->totalCash) + " </b>";
    orignalHTML = orignalHTML.replace("%SUMMARY%", cashString);

    return orignalHTML;
}

QString OrdersReport::getReportTemplateName()
{
    return ":/reports/OrdersReport.html";
}

QString OrdersReport::getOrdersTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr class=\"table_header\"><th>رقم الطلب</th><th>وقت الطلب</th><th>نوع الطلب</th><th>المبلغ</th>"
            "<th>الخصم</th><th>الاجمالي</th><th>ملاحظات</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Order> orders = Services::Order::getOrdersBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Order order, orders) {
        QString note = order.isCancelled() ? "ملغى": " ";

        if ( !order.isCancelled() )
            totalCash += order.totalCash();

        QString tableRaw = QString(
            "<tr valign=\"top\"> "
            "<td align=\"center\"><font size=\"2\">%1</font></td> "
            "<td align=\"center\"><font size=\"2\">%2</font></td> "
            "<td align=\"center\"><font size=\"2\">%3</font></td> "
            "<td align=\"center\"><font size=\"2\">%4</font></td> "
            "<td align=\"center\"><font size=\"2\">%5</font></td> "
            "<td align=\"center\"><font size=\"2\">%6</font></td> "
            "<td align=\"center\"><font size=\"2\">%7</font></td> "
            "</tr>"
        ).arg( QString::number(order.id()),
               order.createdDateTime().toString("dd/MM/yyyy h:m:s ap"),
               order.orderType().arabicName(),
               QString::number(order.cash()),
               QString::number(order.discount()),
               QString::number(order.totalCash()),
               note);

        htmlTableResult += tableRaw ;
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}
