#include "tower.h"

Tower::Tower()
{
 setImage();
}

void Tower::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/tower_w.png"));
    else
        setPixmap(QPixmap(":/img/img/tower_b.png"));
}
