
#include <QApplication>
#include "core.h"
Core* core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //llama al nucleo de la aplicacion o juego
    core = new Core();
    core->show();
    core->start();
    return a.exec();
}
