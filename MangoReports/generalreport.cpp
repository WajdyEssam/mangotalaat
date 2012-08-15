#include "generalreport.h"

#include "../MangoModel/event.h"
#include "../MangoService/event.h"
#include "../MangoModel/orderdetail.h"
#include "../MangoModel/order.h"
#include "../MangoService/orderdetail.h"
#include "../MangoService/order.h"
#include "../MangoService/helper.h"
#include <QDebug>

GeneralReport::GeneralReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString GeneralReport::getHTML()
{
    this->totalCash = 0;

    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%LOGIN_REPORT_TYPE%", "تقرير عن عمليات الدخول");
    orignalHTML = orignalHTML.replace("%LOGIN_TABLE%", getLogginTable());

    orignalHTML = orignalHTML.replace("%ORDER_REPORT_TYPE%", "تقرير عن الطلبات");
    orignalHTML = orignalHTML.replace("%ORDER_TABLE%", getOrdersTable());

    orignalHTML = orignalHTML.replace("%DETAIL_REPORT_TYPE%", "تقرير بتفاصيل الطلبات");
    orignalHTML = orignalHTML.replace("%DETAIL_TABLE%", getOrdersDetailsTable());

    QString cashString = "<b> الإجمالي هو " + QString::number(this->totalCash) + " </b>";
    orignalHTML = orignalHTML.replace("%SUMMARY%", cashString);

    return orignalHTML;
}

QString GeneralReport::getReportTemplateName()
{
    return ":/reports/GeneralReport.html";
}

QString GeneralReport::getLogginTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
           "<tr class=\"table_header\"><th>رقم العملية</th><th>اسم المستخدم</th><th>تاريخ العملية</th><th>نوع العملية</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Event> events = Services::Event::getBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Event event, events) {
        Model::Event::EventTypes type = event.eventType();
        QString eventType = type == Model::Event::Login ? "تسجيل دخول" : " خروج";

        QString tableRaw = QString(
            "<tr valign=\"top\"> "
            "<td align=\"center\"><font size=\"2\">%1</font></td> "
            "<td align=\"center\"><font size=\"2\">%2</font></td> "
            "<td align=\"center\"><font size=\"2\">%3</font></td> "
            "<td align=\"center\"><font size=\"2\">%4</font></td> "
            "</tr>"
        ).arg( QString::number(event.id()), event.user().userName(), event.createdDateTime().toString("dd/MM/yyyy h:m:s ap"), eventType);

        htmlTableResult += tableRaw ;
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}

QString GeneralReport::getOrdersDetailsTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr class=\"table_header\"><th>رقم العملية</th><th>رقم الطلب</th><th>اسم الصنف</th><th>الكمية</th>"
            "<th>المكونات</th><th>الاضافات</th><th>السكر</th><th>الاجمالي</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Order> orders = Services::Order::getOrdersBetweenDateTime(this->m_from, this->m_to);
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

QString GeneralReport::getOrdersTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr class=\"table_header\"><th>رقم العملية</th><th>وقت العملية</th><th>نوع العملية</th><th>المبلغ</th>"
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
