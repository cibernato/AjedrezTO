#include "cell.h"
#include <QtGui>


Cell::Cell()
{
}

Cell::Cell(QBrush* pincel):
    pincel{pincel}
{
}

void Cell::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    double height = this->height();
    double width = this->width();
    painter.setBrush(*pincel);
    QPen pen;
    pen.setStyle(Qt::NoPen);
    painter.setPen(pen);
    painter.drawRect(0, 0, width, height);
    layout = new QGridLayout();

    img->setFixedWidth(this->width());
    img->setFixedHeight(this->height());
    layout->addWidget(img);
    this->setLayout(layout);
    //img->show();
}

Cell::Cell(QBrush* pincel, QLabel* img):
    pincel{pincel},img{img}
{
}
