#include "sqlquery.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

SqlQuery::SqlQuery(QObject *parent): QObject(parent)
{

}

QString SqlQuery::selectLoginPassword(QString Login)
{
    QString retValue;
    qDebug() << "Validating" << Login << "in database";
    QSqlQuery query;
    query.prepare("SELECT Password FROM user WHERE Login = :Login");
    query.bindValue(":Login",Login);
    query.exec();
    if (query.first()) {
        retValue = query.value(0).toString();
        qDebug() << "Found! Password ->" << query.value(0).toString();
    }
    else{
        qDebug() << "Not Found!";
    }
    return retValue;
}
