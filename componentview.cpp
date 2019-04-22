#include "componentview.h"
#include "ui_componentview.h"

ComponentView::ComponentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponentVIew)
{
    ui->setupUi(this);
}

ComponentView::~ComponentView()
{
    delete ui;
}
