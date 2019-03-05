#include "loginform.h"
#include "ui_loginform.h"
#include <QKeyEvent>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);


}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_exitButton_clicked()
{
    QApplication::quit();
}

void LoginForm::userIsValid(bool isValid)
{
    if(isValid){
        this->close();
    }
    else {
        this->ui->passInput->clear();
        this->ui->userInput->clear();
        this->ui->loginReply->setText("Dados incorretos.");
    }
}

void LoginForm::on_loginButton_clicked()
{
    emit signalValidateUser(this->ui->userInput->text(),this->ui->passInput->text());
}

void LoginForm::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_loginButton_clicked();
    }
}
