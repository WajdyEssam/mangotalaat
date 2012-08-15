#ifndef REPORT_H
#define REPORT_H

#include "MangoReports_global.h"

#include <QDateTime>
#include <QFile>
#include <QString>

class MANGOREPORTSSHARED_EXPORT Report {
public:
    Report(const QDateTime& from, const QDateTime& to);
    QString getTemplateFileContent();

    virtual QString getHTML() = 0;
    virtual QString getReportTemplateName() = 0;

private:
    QString replaceHeader(QString& content);

protected:
    QDateTime m_from, m_to;
};

#endif // REPORT_H
