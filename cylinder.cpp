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
    painter->drawLine(-90, -120, -85, -120);
    painter->drawLine(-90, 120, 40, 120 );
    painter->drawLine(40, 120, 40, -120);
    painter->drawLine(40, -120, 35, -120);

    painter->setBrush(QColor(0, 0, 0));

    piston = new QPainterPath;
    piston->moveTo(-90, 0);
    piston->lineTo(40, 0);
    piston->moveTo(-25, 0);
    piston->lineTo(-25, -300);
    piston->moveTo(80, -60);
    piston->lineTo(80, 60);
    piston->moveTo(75, -10);
    piston->lineTo(85, 10);
    piston->lineTo(75, 10);
    piston->lineTo(85, -10);
    piston->lineTo(75, -10);

    painter->drawPath(*piston);
    painter->setPen(Qt::DotLine);

    dottedLine = new QLine(40, 0, 120, 0);
    painter->drawLine(*dottedLine);

    QPoint vPoint(-145, 0);
    QPoint wPoint(100, -150);
    QPoint tPoint(-10, 135);
    QPoint xPoint(90, -5);
    QPoint yPoint(90, 15);
    QPoint qPoint(100, 150);

//Qt::TextWordWrap,
    painter->drawText(vPoint, "v");
    painter->drawText(wPoint, "w");
    painter->drawText(tPoint, "t");
    painter->drawText(xPoint, "x");
    painter->drawText(yPoint, "y");
    painter->drawText(qPoint, "q");
}
