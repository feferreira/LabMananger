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

bool SqlQuery::insertComponent(COMPONENT_MODEL &component, unsigned int id)
{
    if(!id){
    query.prepare("INSERT INTO laboratorio.Componente "
                  "(Descricao, IdTipoComponente, Localizacao, Quantidade, Preco, PartNumberMFR, PartNumberSupplier, IdFornecedor, QrCode)"
                  "VALUES(:desc, (SELECT IdTipoComponente FROM TipoComponente WHERE Tipo=:type), :local, :quant, :price, :pnMFR, :pnSupplier, "
                  "(SELECT IdFornecedor FROM Fornecedor WHERE Nome=:supplier), NULL)");
    }
    query.bindValue(":desc", component.description);
    query.bindValue(":type", component.type);
    query.bindValue(":local", component.localization.toStdString().c_str());
    query.bindValue(":quant", component.quantity);
    query.bindValue(":price", component.price);
    query.bindValue(":pnMFR", component.partNumberMFR);
    query.bindValue(":pnSupplier", component.partNumberSupplier);
    query.bindValue(":supplier", component.supplier);
    return query.exec();
}

QStringList SqlQuery::getSuppliersNames()
{
    QStringList suppliers;
    query.prepare("SELECT Nome FROM Fornecedor");
    if(query.exec()){
        while(query.next()){
            suppliers.append(query.value(0).toString());
        }
    }
    return suppliers;
}

QStringList SqlQuery::getTypeNames()
{
    QStringList types;
    query.prepare("SELECT Tipo FROM TipoComponente");
    if(query.exec()){
        while(query.next()){
            types.append(query.value(0).toString());
        }
    }
    return types;
}

