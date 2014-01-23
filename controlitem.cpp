#include "controlitem.h"

#include <QPainter>

const int ControlItem::DEFAULT_SIZE = 5;

ControlItem::ControlItem() :
    ControlItem(0) {
}

ControlItem::ControlItem(QGraphicsItem *parent) :
    ControlItem(parent, DEFAULT_SIZE) {
}

ControlItem::ControlItem(QGraphicsItem *parent, int size) :
    QGraphicsItem(parent),
    size(size) {
}

QRectF ControlItem::boundingRect() const {
    int realSize = size + 2;
    return QRectF(-realSize, -realSize, 2*realSize, 2*realSize);
}

void ControlItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect(-size, -size, 2*size, 2*size);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen (Qt::gray, 2, Qt::SolidLine, Qt::RoundCap));
    painter->drawEllipse(rect);
}

int ControlItem::getSize() const {
    return size;
}

void ControlItem::setSize(int value) {
    size = value;
}

