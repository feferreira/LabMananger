#include "centralizewidget.h"


QRect CentralizeWidget::operator()(QRect screen, const QRect &widget)
{
    QRect center;
    center.setX((screen.width()/2) - widget.width()/2);
    center.setY((screen.height()/2) - widget.height()/2);
    center.setHeight(widget.height());
    center.setWidth(widget.width());
    return center;
}
