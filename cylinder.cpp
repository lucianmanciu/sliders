#include "cylinder.h"

Cylinder::Cylinder()
{
}

QRectF Cylinder::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void Cylinder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}
