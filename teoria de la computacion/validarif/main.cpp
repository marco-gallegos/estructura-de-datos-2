#include <QCoreApplication>
#include<QRegExp>
#include<QDebug>
#include<QTextStream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream stream(stdin);
    QString ifclausure;

    QString identificador="(!?[a-zA-Z_][a-zA-Z_0-9]*|\\d+)";
    QString operador_identificador = "\\s*(=|==|!=|<=|>=|<|>)\\s*"+identificador;
    QString and_or_comparador;

    QRegExp er("^\\s*if\\s*\\(\\s*"+identificador+"("+operador_identificador+")?\\)\\s*");
    while (1)
    {
        qDebug()<<"ingresa una sentencia valida if";
        ifclausure= stream.readLine();

        if (er.exactMatch(ifclausure))
        {
            qDebug()<<"if correcto";
        }
        else {
            qDebug()<<"if invalido";
        }
    }
    return a.exec();
}
