#include "sqlquery.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QVariant>
#include <QDebug>

QSqlTableModel *SqlQuery::getSupplierModel()
{
    model = new QSqlTableModel(this);
    model->setTable("Fornecedor");
    model->select();
    return model;
}

SqlQuery::SqlQuery(QObject *parent): QObject(parent)
{

}

QString SqlQuery::selectLoginPassword(QString Login)
{
    QSqlQuery query;
    query.prepare("SELECT Password FROM User WHERE Login = :Login");
    query.bindValue(":Login",Login);
    query.exec();
    return query.first() ? query.value(0).toString() : QString();
}

