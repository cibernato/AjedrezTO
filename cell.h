#ifndef CELL_H
#define CELL_H
#pragma once
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Cell : public QWidget
{
public:
    Cell();
    Cell(QBrush*);
    Cell(QBrush*, QLabel*);

protected:
    void paintEvent(QPaintEvent *);
    QBrush* pincel;
    QLabel* img;
    QGridLayout *layout;
};

#endif // CELL_H
