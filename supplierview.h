#ifndef SUPPLIERVIEW_H
#define SUPPLIERVIEW_H

#include <QWidget>

class SqlQuery;

namespace Ui {
class SupplierView;
}

class SupplierView : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierView(QWidget *parent = nullptr);
    ~SupplierView();

private slots:

    void on_pushButtonSave_clicked();

private:
    SqlQuery *query{nullptr};
    Ui::SupplierView *ui;
};

#endif // SUPPLIERVIEW_H
