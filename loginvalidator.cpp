#include "loginvalidator.h"
#include "sqlquery.h"
#include <QCryptographicHash>
#include <QByteArray>
#include <QDebug>
#include <iostream>
LoginValidator::LoginValidator(QObject *parent) : QObject(parent)
{

}

void LoginValidator::slotValidateUser(QString user, QString pass)
{
    QString passHash = QString(QCryptographicHash::hash((pass.toStdString().c_str()),QCryptographicHash::Sha256).toHex());
    qDebug() << "passHash ->" << passHash;
    SqlQuery* query = new SqlQuery(this);
    QString storedPassword(query->selectLoginPassword(user.toLower()));
    if(storedPassword != QString()){
        if(storedPassword == passHash){
            emit userValid(user);
            emit userValidated(true);
        }
        else {
            emit userValidated(false);
        }
    }
    else {
        emit userValidated(false);
    }
}
