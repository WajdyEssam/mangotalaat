#include "ordersdetailsreport.h"

#include "../MangoModel/orderdetail.h"
#include "../MangoModel/order.h"
#include "../MangoService/orderdetail.h"
#include "../MangoService/order.h"
#include "../MangoService/helper.h"

#include <QDebug>

OrdersDetailsReport::OrdersDetailsReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString OrdersDetailsReport::getHTML()
{
    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%DETAIL_REPORT_TYPE%", "تقرير بتفاصيل الطلبات");
    orignalHTML = orignalHTML.replace("%DETAIL_TABLE%", getOrdersDetailsTable());

    return orignalHTML;
}

QString OrdersDetailsReport::getReportTemplateName()
{
    return ":/reports/OrdersDetailsReport.html";
}

QString OrdersDetailsReport::getOrdersDetailsTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr class=\"table_header\"><th>رقم العملية</th><th>رقم الطلب</th><th>اسم الصنف</th><th>الكمية</th>"
            "<th>المكونات</th><th>الاضافات</th><th>السكر</th><th>الاجمالي</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Order> orders = Services::Order::getAll();
    foreach(Model::Order order, orders) {
        QList<Model::OrderDetail> details = Services::OrderDetail::getByOrderId(order.id());
        foreach(Model::OrderDetail detail, details) {
            QString tableRaw = QString(
                "<tr valign=\"top\"> "
                "<td align=\"center\"><font size=\"2\">%1</font></td> "
                "<td align=\"center\"><font size=\"2\">%2</font></td> "
                "<td align=\"center\"><font size=\"2\">%3</font></td> "
                "<td align=\"center\"><font size=\"2\">%4</font></td> "
                "<td align=\"center\"><font size=\"2\">%5</font></td> "
                "<td align=\"center\"><font size=\"2\">%6</font></td> "
                "<td align=\"center\"><font size=\"2\">%7</font></td> "
                "<td align=\"center\"><font size=\"2\">%8</font></td> "
                "</tr>"
            ).arg( QString::number(detail.id()),
                   QString::number(detail.order().id()),
                   detail.itemDetail().item().arabicName(),
                   QString::number(detail.qunatity()),
                   Services::Helper::fromComponentsToText(detail.components()),
                   Services::Helper::fromAdditionalsToText(detail.additionals()),
                   QString::number(detail.sugar()),
                   QString::number(detail.cash())
                   );

            htmlTableResult += tableRaw ;
        }
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}
