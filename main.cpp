#include "mainwindow.h"
#include <QApplication>
#include "loginform.h"
#include "loginvalidator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm loginForm;
    LoginValidator loginValidator;
    QObject::connect(&loginForm, &LoginForm::validateUser, &loginValidator, &LoginValidator::validateUser);
    loginForm.show();
    return a.exec();
}
