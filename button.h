#ifndef BUTTON_H
#define BUTTON_H

#include <memory>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class Button : public QObject, public QGraphicsRectItem {
Q_OBJECT
public:
    Button(QString nombre, QGraphicsItem *parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *evento);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *evento);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *evento);

signals:

    void clicked();

private:
    QGraphicsTextItem *texto;
};

#endif
