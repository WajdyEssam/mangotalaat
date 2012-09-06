#include "generalreport.h"

#include "../MangoModel/event.h"
#include "../MangoService/event.h"
#include "../MangoModel/orderdetail.h"
#include "../MangoModel/order.h"
#include "../MangoService/orderdetail.h"
#include "../MangoService/order.h"
#include "../MangoService/helper.h"
#include "../MangoService/user.h"
#include "../MangoModel/user.h"
#include <QDebug>

GeneralReport::GeneralReport(const QDateTime& from, const QDateTime& to)
    :Report(from, to)
{
}

QString GeneralReport::getHTML()
{
    this->totalCash = 0;

    QString orignalHTML = getTemplateFileContent();
    orignalHTML = orignalHTML.replace("%LOGIN_REPORT_TYPE%", "تقرير عن عمليات الدخول للنظام");
    orignalHTML = orignalHTML.replace("%LOGIN_TABLE%", getLogginTable());

    orignalHTML = orignalHTML.replace("%GLASS_REPORT_TYPE%", "تقرير عن عدد الكاسات");
    orignalHTML = orignalHTML.replace("%GLASS_TABLE%", getGlassTable());

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

QString GeneralReport::getGlassTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
           "<tr class=\"table_header\"><th>عدد الكاسات</th><th>النوع</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QMap<QString, int> summations;

    QList<Model::Order> orders = Services::Order::getOrdersBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Order order, orders) {
        QList<Model::OrderDetail> details = Services::OrderDetail::getByOrderId(order.id());
        foreach(Model::OrderDetail detail, details) {
            int category = detail.itemDetail().item().category().id();

            if ( isCountableGlass(category)) {
                QString size = detail.itemDetail().size().arabicName();
                if ( summations.contains(size) ) {
                    int count = summations.value(size) + detail.qunatity();
                    summations.insert(size, count);
                }
                else {
                    summations.insert(size, 1);
                }
            }
        }
    }

    QMapIterator<QString, int> i(summations);
    while (i.hasNext()) {
        i.next();

        QString size = i.key();
        int count = i.value();

        QString tableRaw = QString(
            "<tr valign=\"top\"> "
            "<td align=\"center\"><font size=\"2\">%1</font></td> "
            "<td align=\"center\"><font size=\"2\">%2</font></td> "
            "</tr>"
            ).arg(QString::number(count), size);
        htmlTableResult += tableRaw ;
    }

    htmlTableResult += tableEnd;

    return htmlTableResult;
}

bool GeneralReport::isCountableGlass(int categoryId)
{
    if ( categoryId == 1 ||
         categoryId == 2 ||
         categoryId == 4 ||
         categoryId == 5 ||
         categoryId == 8 )
        return true;

    return false;
}

QString GeneralReport::getLogginTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
           "<tr class=\"table_header\"><th>رقم العملية</th><th>اسم الموظف</th><th>تاريخ العملية</th><th>نوع العملية</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Event> events = Services::Event::getBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Event event, events) {
        Model::Event::EventTypes type = event.eventType();
        QString eventType = type == Model::Event::Login ? "دخول" : " خروج";

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
            "<tr class=\"table_header\"><th>رقم تسلسلي</th><th>رقم الطلب</th><th>النوع</th><th>اسم الصنف</th><th>الكمية</th>"
            "<th>الحجم</th><th>المكونات</th><th>الاضافات</th><th>السكر</th><th>الاجمالي</th></tr>";
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
                "<td align=\"center\"><font size=\"2\">%9</font></td> "
                "<td align=\"center\"><font size=\"2\">%10</font></td> "
                "</tr>"
                ).arg(QString::number(detail.id()),
                   QString::number(detail.order().id()),
                   detail.itemDetail().item().category().arabicName(),
                   detail.itemDetail().item().arabicName(),
                   QString::number(detail.qunatity()),
                   detail.itemDetail().size().arabicName(),
                   Services::Helper::fromComponentsToText(detail.components()),
                   Services::Helper::fromAdditionalsToText(detail.additionals()),
                   detail.sugar().arabicName()).arg(QString::number(detail.cash()));
            htmlTableResult += tableRaw ;
        }
    }

    htmlTableResult += tableEnd;
    return htmlTableResult;
}

QString GeneralReport::getOrdersTable()
{
    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
            "<tr class=\"table_header\"><th>رقم الطلب</th><th>وقت الطلب</th><th>اسم الموظف</th><th>نوع الطلب</th><th>المبلغ</th>"
            "<th>الخصم</th><th>الاجمالي</th><th>ملاحظات</th></tr>";
    QString tableEnd =  "</tbody></table>";

    QString htmlTableResult = tableBegin;

    QList<Model::Order> orders = Services::Order::getOrdersBetweenDateTime(this->m_from, this->m_to);
    foreach(Model::Order order, orders) {
        QString note = order.isCancelled() ? "ملغى": " ";

        if ( !order.isCancelled() )
            totalCash += order.totalCash();

        QString username = Services::User::getById(order.userID()).userName();

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
        ).arg( QString::number(order.id()),
               order.createdDateTime().toString("dd/MM/yyyy h:m:s ap"),
               username,
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
