#ifndef SQLQUERY_H
#define SQLQUERY_H
#include <QObject>
#include "labmanagertypes.h"
#include <QSqlQuery>

class SqlQuery : public QObject
{
    Q_OBJECT
    QSqlQuery query;
public:
    SqlQuery(QObject *parent = nullptr);
    QString selectLoginPassword(QString Login);
    bool insertSupplier(SUPPLIER_MODEL & supplier, unsigned int id = 0);
    bool insertComponent(COMPONENT_MODEL &component, unsigned int id = 0);
    QStringList getSuppliersNames();
    QStringList getTypeNames();
};

#endif // SQLQUERY_H
