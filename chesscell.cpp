#include "chesscell.h"
#include "core.h"
#include <memory>
#include <QDebug>
#include "king.h"
#include <QMessageBox>

extern Core *core;

ChessCell::ChessCell(QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    setRect(0, 0, 80, 80);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

ChessCell::~ChessCell() {
    delete this;
}

void ChessCell::setOriginalColor(QColor value) {
    originalColor = value;
    setColor(originalColor);
}

void ChessCell::checkForCheck() {
    int c = 0;
    int contrey = 0;
    QList<ChessPiece *> pList = core->piecesInGame;
    for (size_t i = 0, n = pList.size(); i < n; i++) {

        King *p = dynamic_cast<King *> (pList[i]);
        if (p) {
            contrey++;
            continue;
        }

        pList[i]->move();
        pList[i]->recolor();
        QList<ChessCell *> bList = pList[i]->moveLocation();
        for (size_t j = 0, n = bList.size(); j < n; j++) {
            King *p = dynamic_cast<King *> (bList[j]->currentPiece);
            if (p) {
                if (p->getSide() == pList[i]->getSide())
                    continue;
                bList[j]->setColor(Qt::blue);
                pList[i]->getCurrentCell()->setColor(Qt::darkRed);
                if (!core->check->isVisible())
                    core->check->setVisible(true);
                else {
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentCell()->resetOriginalColor();

                    if (QString::compare(core->getTurn(), Blancas)) {

                        core->check->setPlainText("Black Won");
                        core->check->setVisible(true);
                        QMessageBox Msgbox;
                        Msgbox.setWindowTitle("Chess Winneer!!");
                        Msgbox.setText("Black won!!");
                        Msgbox.exec();
                    } else if (QString::compare(core->getTurn(), Negras)) {
                        core->check->setPlainText("White Won");
                        core->check->setVisible(true);
                        QMessageBox Msgbox;
                        Msgbox.setWindowTitle("Chess Winneer!!");
                        Msgbox.setText("White won!!");
                        Msgbox.exec();
                    }
                    core->gameOver();

                }
                c++;

            }
        }
    }
    if (contrey == 1) {
        if (QString::compare(core->getTurn(), Blancas)) {
            core->check->setVisible(true);
            core->check->setPlainText("Black Won");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("Chess Winneer!!");
            Msgbox.setText("Black won!!");
            Msgbox.exec();
        } else if (QString::compare(core->getTurn(), Negras)) {
            core->check->setVisible(true);
            core->check->setPlainText("White Won");
            QMessageBox Msgbox;
            Msgbox.setWindowTitle("Chess Winneer!!");
            Msgbox.setText("White won!!");
            Msgbox.exec();
        }
        core->gameOver();
    }
    if (!c) {
        core->check->setVisible(false);
        for (size_t i = 0, n = pList.size(); i < n; i++)
            pList[i]->getCurrentCell()->resetOriginalColor();
    }
}

void ChessCell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (currentPiece == core->pieceToMove && currentPiece) {

        currentPiece->mousePressEvent(event);
        return;
    }

    if (core->pieceToMove) {
        if (this->getChessPieceColor() == core->pieceToMove->getSide())
            return;
        QList<ChessCell *> movLoc = core->pieceToMove->moveLocation();

        int check = 0;
        for (size_t i = 0, n = movLoc.size(); i < n; i++) {
            if (movLoc[i] == this) {
                check++;

            }
        }
        if (check == 0)
            return;
        core->pieceToMove->recolor();
        core->pieceToMove->firstMove = false;

        if (this->getHasChessPiece()) {
            this->currentPiece->setMoved(false);
            this->currentPiece->setCurrentCell(NULL);
            core->placeInDeadPlace(this->currentPiece);
        }
        core->pieceToMove->getCurrentCell()->setHasChessPiece(false);
        core->pieceToMove->getCurrentCell()->currentPiece = NULL;
        core->pieceToMove->getCurrentCell()->resetOriginalColor();
        placePiece(core->pieceToMove);

        core->pieceToMove = NULL;
        core->changeTurn();
        checkForCheck();
    } else if (this->getHasChessPiece()) {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessCell::setChessPieceColor(QString value) {
    chessPieceColor = value;
}

void ChessCell::setColor(QColor color) {
    brush.setColor(color);
    setBrush(color);
}

void ChessCell::placePiece(ChessPiece *piece) {
    piece->setPos(x() + 40 - piece->pixmap().width() / 2, y() + 40 - piece->pixmap().width() / 2);
    piece->setCurrentCell(this);
    setHasChessPiece(true, piece);
    currentPiece = piece;
}

void ChessCell::resetOriginalColor() {
    setColor(originalColor);
}

void ChessCell::setHasChessPiece(bool value, ChessPiece *piece) {
    hasChessPiece = value;
    if (value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}

bool ChessCell::getHasChessPiece() const {
    return hasChessPiece;
}

QString ChessCell::getChessPieceColor() const {
    return chessPieceColor;
}

