#include "board.h"
#include "ui_board.h"
#include <QGridLayout>
Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QGridLayout *layout = new QGridLayout();
        layout->setSpacing(0);
        layout->setMargin(0);
        layout->setVerticalSpacing(0);
        layout->setHorizontalSpacing(0);
        layout->setContentsMargins(0, 0, 0, 0);
        QBrush* dark = new QBrush("#2F4858");
        QBrush* light = new QBrush("#DFE0DF");
        QBrush* pincel;



        for(int i=0; i<64; i++){
            if((i+i/8)%2==0){
                pincel = dark;
            }else{
                pincel = light;
            }
            QLabel* img = new QLabel();
            QPixmap qpix("://images/c_bk.svg");
            //qpix.load(QString("://images/c_bk.svg"));

            img -> setPixmap(qpix);
             //img->setMask(qpix.mask());
            img -> setScaledContents(true);
            Cell *sq = new Cell(pincel,img);
            cells.push_back(sq);
            layout->addWidget(sq, i/8, i%8);
        }
        this->setLayout(layout);


}

Board::~Board()
{
    delete ui;
}
