#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QVector>
#include "cell.h"
namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
    QVector<Cell*> cells;
};

#endif // BOARD_H
