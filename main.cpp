#include "mainwindow.h"
#include <QApplication>
#include "loginform.h"
#include "loginvalidator.h"
#include "dbwizard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm loginForm;
    LoginValidator loginValidator;
    MainWindow mainWindow;
    QObject::connect(&loginForm, &LoginForm::signalValidateUser, &loginValidator, &LoginValidator::slotValidateUser);
    QObject::connect(&loginValidator, &LoginValidator::userValidated, &loginForm, &LoginForm::userIsValid);
    QObject::connect(&loginValidator, &LoginValidator::userValid, &mainWindow, &MainWindow::validUser);
    loginForm.show();
    return a.exec();
}
