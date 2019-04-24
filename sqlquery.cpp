#include "sqlquery.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QVariant>
#include <QDebug>


SqlQuery::SqlQuery(QObject *parent): QObject(parent)
{

}

QString SqlQuery::selectLoginPassword(QString Login)
{
    query.prepare("SELECT Password FROM User WHERE Login = :Login");
    query.bindValue(":Login",Login);
    query.exec();
    return query.first() ? query.value(0).toString() : QString();
}

bool SqlQuery::insertSupplier(SUPPLIER_MODEL &supplier, unsigned int id)
{
    if(!id){
    query.prepare("INSERT INTO Fornecedor (Nome, Website, Telefone, Endereco, Email) "
                  "VALUES (:name, :site, :phone, :address, :email)");
    }
    query.bindValue(":name", supplier.name);
    query.bindValue(":site", supplier.website);
    query.bindValue(":phone", supplier.phone);
    query.bindValue(":address", supplier.address);
    query.bindValue(":email", supplier.email);
    return query.exec();
}

