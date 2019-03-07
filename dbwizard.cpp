#include "dbwizard.h"
#include "ui_dbwizard.h"

dbWizard::dbWizard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbWizard)
{
    ui->setupUi(this);
}

dbWizard::~dbWizard()
{
    delete ui;
}
