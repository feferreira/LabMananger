#include "componentview.h"
#include "ui_componentview.h"
#include <sqlquery.h>
#include <QDebug>
#include "labmanagertypes.h"

ComponentView::ComponentView(QWidget *parent) :
    QWidget(parent),
    sqlQuery(new SqlQuery(this)),
    ui(new Ui::ComponentVIew)
{
    ui->setupUi(this);
    ui->comboBoxSupplier->addItems(sqlQuery->getSuppliersNames());
    ui->comboBoxType->addItems(sqlQuery->getTypeNames());
}

ComponentView::~ComponentView()
{
    delete ui;
}

void ComponentView::on_pushButtonSave_clicked()
{
    COMPONENT_MODEL model;
    model.description = ui->lineEditDescription->text();
    model.type = ui->comboBoxType->currentText();
    model.supplier = ui->comboBoxSupplier->currentText();
    model.partNumberMFR = ui->lineEditPartNumberMfn->text();
    model.partNumberSupplier = ui->lineEditPartNumberSupplier->text();
    model.price = ui->doubleSpinBoxPrice->value();
    model.quantity = ui->spinBoxQuantity->value();
    //model.localization = ui->lineEditPartLocalization->text();
    model.localization = QString();
    sqlQuery->insertComponent(model);

}
