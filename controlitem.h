#ifndef CONTROLITEM_H
#define CONTROLITEM_H

#include <QGraphicsEllipseItem>

class ControlItem : public QGraphicsItem
{
public:
    static const int DEFAULT_SIZE;

    ControlItem();
    ControlItem(QGraphicsItem *parent);
    ControlItem(QGraphicsItem *parent, int size);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getSize() const;
    void setSize(int value);

private:
    int size;
};

#endif // CONTROLITEM_H
