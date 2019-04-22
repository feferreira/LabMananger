#ifndef COMPONENTVIEW_H
#define COMPONENTVIEW_H

#include <QWidget>

namespace Ui {
class ComponentVIew;
}

class ComponentView : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentView(QWidget *parent = nullptr);
    ~ComponentView();

private slots:

private:
    Ui::ComponentVIew *ui;
};

#endif // COMPONENTVIEW_H
