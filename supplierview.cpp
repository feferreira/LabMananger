#include "supplierview.h"
#include "ui_supplierview.h"
#include "sqlquery.h"
#include <QSqlTableModel>
#include <QVariant>
#include <QMessageBox>

SupplierView::SupplierView(QWidget *parent) :
    QWidget(parent),
    query(new SqlQuery(this)),
    ui(new Ui::SupplierView)
{
    ui->setupUi(this);
}

SupplierView::~SupplierView()
{
    delete ui;
}


void SupplierView::on_pushButtonSave_clicked()
{
    SUPPLIER_MODEL model{
        this->ui->lineEditName->text(),
                this->ui->lineEditWebsite->text(),
                this->ui->lineEditAddress->text(),
                this->ui->lineEditPhone->text(),
                this->ui->lineEditEmail->text()
    };
    if(query->insertSupplier(model)){
        QMessageBox::information(this,"Sucesso","Fornecedor\nCadastrado.");
    }
    else {
        QMessageBox::warning(this,"Falha","Falha ao cadastrar.");
    }

}
