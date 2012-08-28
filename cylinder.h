#ifndef CYLINDER_H
#define CYLINDER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

class Cylinder : public QGraphicsItem
{

public:
    Cylinder();
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget);

private:
    QPainterPath *piston;
    QLine *dottedLine;

signals:
    
public slots:
    
};

#endif
