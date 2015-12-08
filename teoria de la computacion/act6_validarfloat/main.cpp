#include <QCoreApplication>
#include<QTextStream>
#include<QRegExp>
#include<QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream flujo(stdin);

    QString palabra;

    QRegExp reguar_exp("(-|\\+){0,1}[0-9]*\\.{0,1}[0-9]*");

    while (1)
    {

        qDebug("ingresa un numero");
        palabra=flujo.readLine();

        if (reguar_exp.exactMatch(palabra))
        {
            qDebug("numero valido");
        }
        else {
            qDebug("eso no se puede");
        }

    }
    return a.exec();
}
