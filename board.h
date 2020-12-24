#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsRectItem>
#include "chesspiece.h"

class Board {
public:
    Board();

    void initializeBoard(int x, int y);

    void addPieces();

    void initializeWhite();

    void initializeBlack();

    void reset();

private:
    QList<ChessPiece *> whitePieces;
    QList<ChessPiece *> blackPieces;
};

#endif
