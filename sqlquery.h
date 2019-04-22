#ifndef SQLQUERY_H
#define SQLQUERY_H
#include <QObject>
#include <QSqlQuery>

class QSqlTableModel;

class SqlQuery : public QObject
{
    Q_OBJECT
    QSqlTableModel *model{nullptr};
public:
    QSqlTableModel *getSupplierModel();
    SqlQuery(QObject *parent = nullptr);
    QString selectLoginPassword(QString Login);
};

#endif // SQLQUERY_H
