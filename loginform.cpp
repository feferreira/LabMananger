#include "loginform.h"
#include "ui_loginform.h"

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

void LoginForm::on_loginButton_clicked()
{
    emit validateUser(this->ui->userInput->text(),this->ui->passInput->text());
}
