#include "loginform.h"
#include "ui_loginform.h"
#include <QKeyEvent>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    this->ui->loginReply->setStyleSheet("QLabel{color:red;}");

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
        //this->close();
    }
    else {
        this->ui->passInput->clear();
        this->ui->userInput->clear();
        this->ui->loginReply->setStyleSheet("QLabel{color:red;}");
        this->ui->loginReply->setText("Dados incorretos.");
    }
}

void LoginForm::on_loginButton_clicked()
{
    if(ui->userInput->text().isEmpty()){
        ui->userInput->setStyleSheet(ui->userInput->styleSheet()+"background-color:#ff989a;");
        this->ui->loginReply->setText("Campo obrigatório");
    }
    if(ui->passInput->text().isEmpty()){
        ui->passInput->setStyleSheet(ui->passInput->styleSheet()+"background-color:#ff989a;");
        this->ui->loginReply->setText("Campo obrigatório");
    }
    else{
        this->ui->loginReply->setStyleSheet("QLabel{color:green;}");
        this->ui->loginReply->setText("Conectando...");
        emit signalValidateUser(this->ui->userInput->text(),this->ui->passInput->text());
    }
}

void LoginForm::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_loginButton_clicked();
    }
}

void LoginForm::on_userInput_textEdited(const QString &arg1)
{
    ui->userInput->setStyleSheet(ui->userInput->styleSheet()+"background-color:white;");
    ui->passInput->setStyleSheet(ui->passInput->styleSheet()+"background-color:white;");
}
