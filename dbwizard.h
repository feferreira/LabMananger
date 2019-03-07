#ifndef DBWIZARD_H
#define DBWIZARD_H

#include <QWidget>

namespace Ui {
class dbWizard;
}

class dbWizard : public QWidget
{
    Q_OBJECT

public:
    explicit dbWizard(QWidget *parent = nullptr);
    ~dbWizard();

private:
    Ui::dbWizard *ui;
};

#endif // DBWIZARD_H
