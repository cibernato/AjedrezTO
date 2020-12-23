#include "queen.h"
#include "core.h"
extern Core *core;
Queen::Queen(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    //se inicializa poniendo su imagen
    setImage();
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Queen::setImage()
{
    if(side == Blancas)
        setPixmap(QPixmap(":/img/img/queen_w.png"));
    else
        setPixmap(QPixmap(":/img/img/queen_b.png"));
}

/*Se encarga de como se mueve la pieza*/

void Queen::move()
{

    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();
    //For up

     for(int i = row-1,j = col; i >= 0 ; i--) {
       if(core->collection[i][j]->getChessPieceColor() == team ) {
           break;
       }
       else
       {
           location.append(core->collection[i][j]);
           if(CellSetup(location.last()))
               break;
        }
    }

     //For Down

      for(int i = row+1,j = col; i <= 7 ; i++) {
        if(core->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(core->collection[i][j]);
            if(CellSetup(location.last())){
                break;
            }
        }
     }
      //For Right

       for(int i = row,j = col+1; j <= 7 ; j++)
       {
             if(core->collection[i][j]->getChessPieceColor() == team ) {
                 break;
             }
             else
             {
                 location.append(core->collection[i][j]);
                 if(CellSetup(location.last()))
                     break;
              }

      }
      //For left

       for(int i = row,j = col-1; j >= 0 ; j--) {
         if(core->collection[i][j]->getChessPieceColor() == team ) {
             break;
         }
         else
         {
             location.append(core->collection[i][j]);
             if(CellSetup(location.last()))
                break;
         }
        }
       //For upper right

        for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
          if(core->collection[i][j]->getChessPieceColor() == team ) {
              break;

          }
          else
          {
              location.append(core->collection[i][j]);
              if(CellSetup(location.last())){
                  break;
              }
          }
       }

        //For upper Left

         for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
           if(core->collection[i][j]->getChessPieceColor() == team ) {
               break;

           }
           else
           {
               location.append(core->collection[i][j]);
               if(CellSetup(location.last()) ){
                   break;
               }
           }
        }

          //For downward right

           for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
             if(core->collection[i][j]->getChessPieceColor() == team ) {
                 break;

             }
             else
             {
                 location.append(core->collection[i][j]);
                 if(CellSetup(location.last())){
                     break;
                 }
             }
          }

           //For downward left

            for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
              if(core->collection[i][j]->getChessPieceColor() == team ) {
                  break;

              }
              else
              {
                  location.append(core->collection[i][j]);
                  if(CellSetup(location.last())){
                      break;
                  }

              }
           }

}
