#include "core.h"
#include "button.h"
#include <QPixmap>
#include "king.h"
#include <QDebug>
#include <QColor>
#include <iostream>
#include <QMessageBox>
#include <utility>


Core::Core(QWidget *parent) : QGraphicsView(parent) {
    chessScene = new QGraphicsScene();
    chessScene->setSceneRect(0, 0, 1166, 700);
    QMessageBox msbx;
    setFixedSize(1166, 700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(chessScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(186, 74, 0));
    setBackgroundBrush(brush);
    pieceToMove = nullptr;
    frameTurn = new QGraphicsTextItem();
    frameTurn->setPos(width() / 2 - 100, 10);
    frameTurn->setZValue(1);
    frameTurn->setDefaultTextColor(Qt::white);
    frameTurn->setFont(QFont("", 18));
    std::string turno = "Turno : ";
    turno.append(Blancas);
    frameTurn->setPlainText(*(new QString(turno.c_str())));

    check = new QGraphicsTextItem();
    check->setPos(1100 - 100, 500);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::black);
    check->setFont(QFont("", 15));
    check->setPlainText("Jaque Mate :(");
    check->setVisible(false);
    setTurn(Blancas);

}

void Core::showBoard() {
    chess = new Board();
    chess->initializeBoard(width() / 2 - 280, 90);
}

void Core::displayDeadWhite() {
    int SHIFT = 42;
    int j = 0;
    int k = 0;
    for (auto &i : whiteDead) {
        if (j == 4) {
            k++;
            j = 0;
        }
        i->setPos(1060 - 100 + SHIFT * j++, 50 + SHIFT * 1.2 * k);
    }
}

void Core::displayDeadBlack() {
    int SHIFT = 42;
    int j = 0;
    int k = 0;
    for (auto &i : blackDead) {
        if (j == 4) {
            k++;
            j = 0;
        }
        i->setPos(1060 - 100 + SHIFT * j++, 250 + SHIFT * 1.2 * k);
    }
}

void Core::placeInDeadPlace(ChessPiece *piece) {
    if (piece->getSide() == Blancas) {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if (g) {
            check->setPlainText("Black Won");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("Chess Winneer!!");
            Msgbox.setText("Black won!!");
            Msgbox.exec();
            gameOver();
        }
        displayDeadWhite();
    } else {
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if (g) {
            check->setPlainText("White Won");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("Chess Winneer!!");
            Msgbox.setText("White won!!");
            Msgbox.exec();
            gameOver();
        }
        displayDeadBlack();
    }
    piecesInGame.removeAll(piece);
}

void Core::aggregateToScene(QGraphicsItem *item) {
    chessScene->addItem(item);
}

void Core::deleteToScene(QGraphicsItem *item) {
    chessScene->removeItem(item);

}

QString Core::getTurn() const {
    return turn;
}

void Core::setTurn(QString value) {
    turn = std::move(value);
}

void Core::changeTurn() {
    if (getTurn() == Blancas)
        setTurn(Negras);
    else
        setTurn(Blancas);
    frameTurn->setPlainText("Turn : " + getTurn());
}

void Core::callReset() {
    gameOver();
}


void Core::start() {
    showBoard();
    for (auto &i : listG)
        deleteToScene(i);

    aggregateToScene(frameTurn);

    auto *whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(1100 - 100, 450);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setFont(QFont("", 14));
    whitePiece->setPlainText("Piezas negras");
    aggregateToScene(whitePiece);

    auto *blackPiece = new QGraphicsTextItem();
    blackPiece->setPos(1100 - 100, 10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::white);
    blackPiece->setFont(QFont("", 14));
    blackPiece->setPlainText("Piezas blancas");
    aggregateToScene(blackPiece);
    aggregateToScene(check);
    chess->addPieces();


    auto *lettersDER = new QGraphicsTextItem();
    lettersDER->setPos(990 - 100, 100);
    lettersDER->setZValue(1);
    lettersDER->setDefaultTextColor(Qt::white);
    lettersDER->setFont(QFont("", 23));
    lettersDER->setPlainText("8\n\n7\n\n6\n\n5\n\n4\n\n3\n\n2\n\n1");
    aggregateToScene(lettersDER);


    auto *lettersABA = new QGraphicsTextItem();
    lettersABA->setPos(420 - 100, 660);
    lettersABA->setZValue(1);
    lettersABA->setDefaultTextColor(Qt::white);
    lettersABA->setFont(QFont("", 25));
    lettersABA->setPlainText("A     B      C     D      E      F     G      H");
    aggregateToScene(lettersABA);


    auto *reset = new Button("Resetear");
    uint16_t sXPos = 70;
    uint16_t sYPos = 600;
    reset->setPos(sXPos, sYPos);
    connect(reset, SIGNAL(clicked()), this, SLOT(callReset()));
    aggregateToScene(reset);

}

void Core::gameOver() {
    check->setPlainText("CHECK, THERE IS A \n POSSIBLE \n CHECKMATE!!");
    check->setVisible(false);


    piecesInGame.clear();
    whiteDead.clear();
    blackDead.clear();
    chess->reset();
    setTurn(Blancas);
}


