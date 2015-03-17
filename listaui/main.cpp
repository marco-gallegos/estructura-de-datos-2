#include "listaui.h"
#include <QApplication>
#include<listasimple.h>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    listaui w;
    w.show();
    return a.exec();
}
