#include "supplierview.h"
#include "ui_supplierview.h"
#include "sqlquery.h"
#include <QSqlTableModel>
#include <QVariant>

SupplierView::SupplierView(QWidget *parent) :
    QWidget(parent),
    query(new SqlQuery(this)),
    ui(new Ui::SupplierView)
{
    ui->setupUi(this);
    ui->supplierTable->setModel(query->getSupplierModel());
}

SupplierView::~SupplierView()
{
    delete ui;
}

void SupplierView::on_supplierTable_doubleClicked(const QModelIndex &index)
{
    ui->lineEditName->setText(ui->supplierTable->model()->data(index).toString());
}
