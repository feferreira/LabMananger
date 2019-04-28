#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "componentview.h"
#include "supplierview.h"
#include <QLabel>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createChildWidgets();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validUser(QString user)
{
    this->show();
    ui->statusBar->addWidget(new QLabel(QString(tr("Logado como: %1").arg(user))));
}



void MainWindow::createChildWidgets()
{
    widgetsViews.at(static_cast<int>(widgetId::SUPPLIER_VIEW)) = new SupplierView(this->ui->widgetView);
    widgetsViews.at(static_cast<int>(widgetId::PART_VIEW)) = new ComponentView(this->ui->widgetView);
    hideAllChildWidgets();
}

void MainWindow::hideAllChildWidgets()
{
    for(auto i : widgetsViews){
        i->hide();
    }
}

void MainWindow::hideLastChildWidget()
{
    if(currentWidget != widgetId::NULL_WIDGET){
        widgetsViews.at(static_cast<unsigned long>(currentWidget))->hide();
    }
}

void MainWindow::showChildWidget(MainWindow::widgetId id)
{
    hideLastChildWidget();
    widgetsViews.at(static_cast<unsigned long>(id))->show();
    currentWidget = id;
}

void MainWindow::on_actionRegisterSupplier_triggered()
{
    showChildWidget(widgetId::SUPPLIER_VIEW);
}

void MainWindow::on_actionRegisterPart_triggered()
{
    showChildWidget(widgetId::PART_VIEW);
}

void MainWindow::on_actionExit_triggered()
{
    if(QMessageBox::question(this,"Sair","Deseja sair?","não","sim")){
        QApplication::quit();
    }
}
