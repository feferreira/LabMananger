#include "mainwindow.h"
#include <QApplication>
#include "loginform.h"
#include "loginvalidator.h"
#include "centralizewidget.h"
#include "dbwizard.h"
#include "mysqlhelper.h"
#include "dbconfig.h"
#include <QScreen>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DbConfig dbConfig("127.0.0.1","laboratorio","fernando","concre");
    MysqlHelper mysqlHelper(dbConfig);

    LoginForm loginForm;
    LoginValidator loginValidator;
    MainWindow mainWindow;
    {
        CentralizeWidget centralizeWidget;
        loginForm.setGeometry(centralizeWidget(a.screens().first()->geometry(),loginForm.geometry()));
        mainWindow.setGeometry(centralizeWidget(a.screens().first()->geometry(),mainWindow.geometry()));
    }
    QObject::connect(&loginForm, &LoginForm::signalValidateUser, &loginValidator, &LoginValidator::slotValidateUser);
    QObject::connect(&loginValidator, &LoginValidator::userValidated, &loginForm, &LoginForm::userIsValid);
    QObject::connect(&loginValidator, &LoginValidator::userValid, &mainWindow, &MainWindow::validUser);

    loginForm.show();
    return a.exec();
}
