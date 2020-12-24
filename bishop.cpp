#include "bishop.h"

#include <QDebug>
#include "core.h"

extern Core *core;

Bishop::Bishop(QString team, QGraphicsItem *parent) : ChessPiece(team, parent) {
    setImage();
}

void Bishop::setImage() {
    if (side == Blancas)
        setPixmap(QPixmap(":/img/img/bishop_w.png"));
    else
        setPixmap(QPixmap(":/img/img/bishop_b.png"));
}

void Bishop::move() {
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;

        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last())) {
                break;
            }
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j <= 7; i--, j++) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;

        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last())) {
                break;
            }
        }
    }
    for (int i = row + 1, j = col + 1; i <= 7 && j <= 7; i++, j++) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last())) {
                break;
            }
        }
    }

    for (int i = row + 1, j = col - 1; i <= 7 && j >= 0; i++, j--) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last())) {
                break;
            }

        }
    }


}
