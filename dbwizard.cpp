#include "dbwizard.h"
#include "ui_dbwizard.h"

DbWizard::DbWizard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbWizard)
{
    ui->setupUi(this);
}

DbWizard::~DbWizard()
{
    delete ui;
}

void DbWizard::on_exitButton_clicked()
{
    QApplication::quit();
}
