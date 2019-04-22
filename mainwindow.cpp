#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "componentview.h"
#include "supplierview.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SupplierView *sup = new SupplierView;
    sup->show();
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



