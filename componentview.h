#ifndef COMPONENTVIEW_H
#define COMPONENTVIEW_H

#include <QWidget>

class SqlQuery;

namespace Ui {
class ComponentVIew;
}

class ComponentView : public QWidget
{
    Q_OBJECT
    SqlQuery *sqlQuery{nullptr};
public:
    explicit ComponentView(QWidget *parent = nullptr);
    ~ComponentView();

private slots:

    void on_pushButtonSave_clicked();

private:
    Ui::ComponentVIew *ui;
};

#endif // COMPONENTVIEW_H
