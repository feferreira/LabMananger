#include "loginvalidator.h"
#include "sqlquery.h"

LoginValidator::LoginValidator(QObject *parent) : QObject(parent)
{

}

void LoginValidator::slotValidateUser(QString user, QString pass)
{
    SqlQuery* query = new SqlQuery(this);
    QString storedPassword = query->selectLoginPassword(user);
    if(storedPassword != QString()){
        if(storedPassword == pass){
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
