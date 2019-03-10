#ifndef DBWIZARD_H
#define DBWIZARD_H

#include <QWidget>

namespace Ui {
class dbWizard;
}

class DbWizard : public QWidget
{
    Q_OBJECT

public:
    explicit DbWizard(QWidget *parent = nullptr);
    ~DbWizard();

private:
    Ui::dbWizard *ui;
};

#endif // DBWIZARD_H
