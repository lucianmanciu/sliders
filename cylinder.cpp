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
//cylinder outline
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

    QLine dotLine(40, 0, 120, 0);
    painter->setPen(Qt::DotLine);
    painter->drawLine(dotLine);

//    path.addRect(20, 20, 60, 60);

//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);

//    painter->fillRect(0, 0, 100, 100, Qt::white);
//    painter->setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
//                        Qt::FlatCap, Qt::MiterJoin));
//    painter->setBrush(QColor(122, 163, 39));

//    painter->drawPath(path);
}
