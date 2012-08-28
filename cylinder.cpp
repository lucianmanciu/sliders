#include "cylinder.h"

Cylinder::Cylinder()
{
}

QRectF Cylinder::boundingRect() const
{
    qreal penWidth = 3;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void Cylinder::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
    painter->drawLine(-90, -120, -90, 120);
    painter->drawLine(-90, 120, 40, 120 );
    painter->drawLine(40, 120, 40, -120);
//    QPainterPath path;
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
