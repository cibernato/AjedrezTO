
#include "chesspiece.h"
#include "core.h"
#include <QDebug>
#include <memory>
#include "king.h"
#include <QColor>

extern Core *core;

ChessPiece::ChessPiece(QString team, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    side = team;
    Moved = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (this == core->pieceToMove) {
        core->pieceToMove->getCurrentCell()->resetOriginalColor();
        core->pieceToMove->recolor();
        core->pieceToMove = NULL;
        return;
    }
    if ((!getMoved()) || ((core->getTurn() != this->getSide()) && (!core->pieceToMove)))
        return;
    if (!core->pieceToMove) {

        core->pieceToMove = this;
        core->pieceToMove->getCurrentCell()->setColor(QColor(42, 157, 143));
        core->pieceToMove->move();
    } else if (this->getSide() != core->pieceToMove->getSide()) {
        this->getCurrentCell()->mousePressEvent(event);
    }


}

void ChessPiece::setCurrentCell(ChessCell *Cell) {

    currentCell = Cell;
}

ChessCell *ChessPiece::getCurrentCell() const {
    return currentCell;
}

QString ChessPiece::getSide() const {
    return side;
}

void ChessPiece::setSide(QString value) {
    side = value;
}

bool ChessPiece::getMoved() const {
    return Moved;
}

void ChessPiece::setMoved(bool value) {
    Moved = value;

}

QList<ChessCell *> ChessPiece::moveLocation() {
    return location;
}

void ChessPiece::recolor() {
    for (size_t i = 0, n = location.size(); i < n; i++) {
        location[i]->resetOriginalColor();
    }
}


bool ChessPiece::CellSetup(ChessCell *Cell) {
    if (Cell->getHasChessPiece()) {
        King *q = dynamic_cast<King *>(location.last()->currentPiece);
        if (q) {
            Cell->setColor(Qt::blue);
        } else
            Cell->setColor(Qt::red);
        return true;
    } else
        location.last()->setColor(Qt::darkRed);
    return false;
}



