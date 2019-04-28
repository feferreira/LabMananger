#ifndef CENTRALIZEWIDGET_H
#define CENTRALIZEWIDGET_H
#include <QRect>

class CentralizeWidget
{
public:
    QRect operator() (QRect screen, const QRect &widget);
};

#endif // CENTRALIZEWIDGET_H
