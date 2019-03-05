#include "loginvalidator.h"

LoginValidator::LoginValidator(QObject *parent) : QObject(parent)
{

}

void LoginValidator::slotValidateUser(QString user, QString pass)
{
    if(user == "fernando" && pass == "123"){
        emit userValid(user);
        emit userValidated(true);
    }
    else {
        emit userValidated(false);
    }

}
