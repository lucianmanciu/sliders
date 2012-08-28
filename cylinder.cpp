#include "cylinder.h"

Cylinder::Cylinder()
{
}

QRectF Cylinder::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-90 - penWidth / 2, -120 - penWidth / 2,
                  210 + penWidth, 240 + penWidth);
}

void Cylinder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(-90, -120, -90, 120);
    painter->drawLine(-90, 120, 40, 120 );
    painter->drawLine(40, 120, 40, -120);

    painter->setBrush(QColor(0, 0, 0));

    QPainterPath piston;
    piston.moveTo(-90, 0);
    piston.lineTo(40, 0);
    piston.moveTo(-25, 0);
    piston.lineTo(-25, -300);
    piston.moveTo(80, -60);
    piston.lineTo(80, 60);
    piston.moveTo(75, -10);
    piston.lineTo(85, 10);
    piston.lineTo(75, 10);
    piston.lineTo(85, -10);
    piston.lineTo(75, -10);

    painter->drawPath(piston);
    painter->setPen(Qt::DotLine);

    QLine dottedLine(40, 0, 120, 0);
    painter->drawLine(dottedLine);
}
