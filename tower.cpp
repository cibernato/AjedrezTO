#include "tower.h"
#include "core.h"

extern Core *core;

Tower::Tower(QString team, QGraphicsItem *parent) : ChessPiece(team, parent) {

    setImage();
}


void Tower::setImage() {
    if (side == Blancas)
        setPixmap(QPixmap(":/img/img/tower_w.png"));
    else
        setPixmap(QPixmap(":/img/img/tower_b.png"));
}

void Tower::move() {
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();


    for (int i = row - 1, j = col; i >= 0; i--) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last()))
                break;
        }
    }


    for (int i = row + 1, j = col; i <= 7; i++) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last())) {
                break;
            }
        }
    }


    for (int i = row, j = col - 1; j >= 0; j--) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last()))
                break;
        }
    }


    for (int i = row, j = col + 1; j <= 7; j++) {
        if (core->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(core->collection[i][j]);
            if (CellSetup(location.last()))
                break;
        }

    }
}


