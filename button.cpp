
#include "button.h"
#include <memory>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QColor>

Button::Button(QString nombre, QGraphicsItem *parent)
        : QGraphicsRectItem(parent) {
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(199, 0, 57));
    setBrush(brush);

    texto = new QGraphicsTextItem(nombre, this);
    int xPos = rect().width() / 2 - texto->boundingRect().width() / 2;
    int yPos = rect().height() / 2 - texto->boundingRect().height() / 2;
    texto->setPos(xPos, yPos);
    texto->setDefaultTextColor(Qt::white);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *evento) {
    if (evento)
            emit clicked();

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *evento) {
    if (evento) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(37, 65, 178));
        setBrush(brush);
    }
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *evento) {

    if (evento) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(23, 104, 172));
        setBrush(brush);
    }
}
