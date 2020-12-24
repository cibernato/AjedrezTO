#include "horse.h"
#include "core.h"

extern Core *core;

Horse::Horse(QString team, QGraphicsItem *parent) : ChessPiece(team, parent) {
    setImage();
}

void Horse::setImage() {
    if (side == Blancas)
        setPixmap(QPixmap(":/img/img/horse_w.png"));
    else
        setPixmap(QPixmap(":/img/img/horse_b.png"));
}

void Horse::move() {
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    int i, j;
    QString team = this->getSide();

    i = row - 2;
    j = col - 1;
    if (i >= 0 && j >= 0 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row - 2;
    j = col + 1;
    if (i >= 0 && j <= 7 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row + 2;
    j = col - 1;
    if (i <= 7 && j >= 0 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row + 2;
    j = col + 1;
    if (i <= 7 && j <= 7 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row - 1;
    j = col - 2;
    if (i >= 0 && j >= 0 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row + 1;
    j = col - 2;
    if (i <= 7 && j >= 0 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row - 1;
    j = col + 2;
    if (i >= 0 && j <= 7 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    i = row + 1;
    j = col + 2;
    if (i <= 7 && j <= 7 && (core->collection[i][j]->getChessPieceColor() != team)) {
        location.append(core->collection[i][j]);
        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

}

