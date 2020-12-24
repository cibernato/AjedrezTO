#ifndef CORE_H
#define CORE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>
#include "chesspiece.h"
#include <QTime>
#include "constants.h"
#include <QTimer>
#include <QLabel>
#include <QElapsedTimer>
#include <QPushButton>
#include <QVBoxLayout>

class Core : public QGraphicsView {
Q_OBJECT
public:
    Core(QWidget *parent = 0);

    void showBoard();

    void placeInDeadPlace(ChessPiece *piece);

    void aggregateToScene(QGraphicsItem *item);

    void deleteToScene(QGraphicsItem *item);

    ChessPiece *pieceToMove;

    QString getTurn() const;

    void setTurn(QString value);

    void changeTurn();


    ChessCell *collection[8][8];
    QGraphicsTextItem *check;
    QList<ChessPiece *> piecesInGame;

    void displayDeadWhite();

    void displayDeadBlack();


    void gameOver();


public
    slots:

    void start();

    void callReset();

private:

    QGraphicsScene *chessScene;
    QList<ChessPiece *> whiteDead;
    QList<ChessPiece *> blackDead;
    QGraphicsRectItem *deadHolder;
    QString turn;
    Board *chess;
    QList<QGraphicsItem *> listG;
    QGraphicsTextItem *frameTurn;

};

#endif
