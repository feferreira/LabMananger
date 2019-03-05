#include "mainwindow.h"
#include <QApplication>
#include "loginform.h"
#include "loginvalidator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm loginForm;
    LoginValidator loginValidator;
    loginForm.show();
    return a.exec();
}
