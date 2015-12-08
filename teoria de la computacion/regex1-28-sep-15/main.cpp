#include <QCoreApplication>
#include<QRegExp>
#include<QFile>
#include<QTextStream>
#include<QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile direcciones("calles.txt");

    QTextStream in(&direcciones);
    QString cadena;


    if (!direcciones.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error al abrir el archivo";
    }
    else
    {
        QRegExp er("^(calle|avenida|boulevard)\\s[A-Z][\\w\\s]*\\|#\\d{4}\\|col\\s[\\w\\s]*\\|\\d{5}$");
        while(!in.atEnd())
        {
            cadena = in.readLine();
            if (er.exactMatch(cadena))
            {
                qDebug()<<er.cap(0);
            }
        }
    }

    return a.exec();
}
