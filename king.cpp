#include "king.h"
#include "pawn.h"
#include "core.h"

extern Core *core;

King::King(QString team, QGraphicsItem *parent) : ChessPiece(team, parent) {

    setImage();
}

void King::setImage() {
    if (side == Blancas)
        setPixmap(QPixmap(":/img/img/king_w.png"));
    else
        setPixmap(QPixmap(":/img/img/king_b.png"));
}


void King::move() {

    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();

    if (col > 0 && row > 0 && !(core->collection[row - 1][col - 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row - 1][col - 1]);
        core->collection[row - 1][col - 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (col < 7 && row > 0 && !(core->collection[row - 1][col + 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row - 1][col + 1]);
        core->collection[row - 1][col + 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (row > 0 && !(core->collection[row - 1][col]->getChessPieceColor() == team)) {
        location.append(core->collection[row - 1][col]);
        core->collection[row - 1][col]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (row < 7 && !(core->collection[row + 1][col]->getChessPieceColor() == team)) {
        location.append(core->collection[row + 1][col]);
        core->collection[row + 1][col]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (col > 0 && !(core->collection[row][col - 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row][col - 1]);
        core->collection[row][col - 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (col < 7 && !(core->collection[row][col + 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row][col + 1]);
        core->collection[row][col + 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (col > 0 && row < 7 && !(core->collection[row + 1][col - 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row + 1][col - 1]);
        core->collection[row + 1][col - 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }
    if (col < 7 && row < 7 && !(core->collection[row + 1][col + 1]->getChessPieceColor() == team)) {
        location.append(core->collection[row + 1][col + 1]);
        core->collection[row + 1][col + 1]->setColor(Qt::darkRed);
        if (location.last()->getHasChessPiece()) {
            location.last()->setColor(Qt::red);
        }
    }


    findUnSafeLocation();

}

void King::findUnSafeLocation() {
    QList<ChessPiece *> pList = core->piecesInGame;
    for (size_t i = 0, n = pList.size(); i < n; i++) {

        if (pList[i]->getSide() != this->getSide()) {
            QList<ChessCell *> bList = pList[i]->moveLocation();

            for (size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]);
                if (c)
                    continue;
                for (size_t k = 0, n = location.size(); k < n; k++) {
                    if (bList[j] == location[k]) {
                        location[k]->setColor(Qt::blue);
                    }
                }
            }
        }
    }
}
