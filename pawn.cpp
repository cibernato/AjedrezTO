#include "pawn.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
#include "core.h"
extern Core *core;
Pawn::Pawn(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    //se inicializa poniendo su imagen
    setImage();
    firstMove = true;
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Pawn::setImage()
{
    if(side == Blancas)
        setPixmap(QPixmap(":/img/img/pawn_w.png"));
    else
        setPixmap(QPixmap(":/img/img/pawn_b.png"));
}

/*Se encarga de como se mueve la pieza*/

void Pawn::move()
{
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    if(this->getSide() == Blancas)  {
        if(col > 0 && row > 0 && core->collection[row-1][col-1]->getChessPieceColor() == Negras) {
            location.append(core->collection[row-1][col-1]);
            CellSetup(location.last());
        }
        if(col < 7 && row > 0 && core->collection[row-1][col+1]->getChessPieceColor() == Negras) {
            location.append(core->collection[row-1][col+1]);
            CellSetup(location.last());
        }
        if(row>0 && (!core->collection[row-1][col]->getHasChessPiece())) {
            location.append(core->collection[row-1][col]);
            CellSetup(location.last());
            if(firstMove && !core->collection[row-2][col]->getHasChessPiece()){
                location.append(core->collection[row-2][col]);
                CellSetup(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && core->collection[row+1][col-1]->getChessPieceColor() == Blancas) {//left
            location.append(core->collection[row+1][col-1]);
            CellSetup(location.last());
        }
        if(col < 7 && row <  7 && core->collection[row+1][col+1]->getChessPieceColor() == Blancas) {//right
            location.append(core->collection[row+1][col+1]);
            CellSetup(location.last());
        }
        if(row<7 && (!core->collection[row+1][col]->getHasChessPiece())) {
            location.append(core->collection[row+1][col]);
            CellSetup(location.last());
            if(firstMove && !core->collection[row+2][col]->getHasChessPiece()){
                location.append(core->collection[row+2][col]);
                CellSetup(location.last());
            }

        }

    }

}


