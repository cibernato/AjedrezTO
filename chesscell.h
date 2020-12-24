#ifndef CHESSCELL_H
#define CHESSCELL_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "chesspiece.h"
#include <QGraphicsSceneMouseEvent>

class ChessPiece;

class ChessCell : public QGraphicsRectItem {
public:

    ChessCell(QGraphicsItem *parent = 0);

    ~ChessCell();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setColor(QColor color);

    void placePiece(ChessPiece *piece);

    void resetOriginalColor();

    void setOriginalColor(QColor value);

    bool getHasChessPiece() const;

    void setHasChessPiece(bool value, ChessPiece *piece = 0);

    void checkForCheck();

    QString getChessPieceColor() const;

    void setChessPieceColor(QString value);

    int rowLoc;
    int colLoc;

    ChessPiece *currentPiece;

private:
    QColor originalColor;
    bool hasChessPiece;
    QBrush brush;
    QString chessPieceColor;


};

#endif
