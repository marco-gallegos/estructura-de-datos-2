#include <QCoreApplication>
#include"cifrador.h"
int main(int argc, char *argv[])
{
    int b;
    //QCoreApplication a(argc, argv);

    cifrador c;
    c.cifrar('a');
    c.descifrar('a');
    return 0;
}
