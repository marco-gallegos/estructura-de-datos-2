#include <QCoreApplication>
#include<iostream>

using namespace std;

// automata finito determinista que reconoce ceros y unos pares.
int tipoSimbolo(char c); //funcion para regresar el tipo de simbolo
int main()
{
    //QCoreApplication a(argc, argv);
    int matriz [][3]={//matriz de transiciones
        {2,1,4},//q0
        {3,0,4},//q1
        {0,3,4},//q2
        {1,2,4},//q3
        {4,4,4}//q4
    };

    int estado;
    string cadena;
    while (1) {


    cout<<"AFD para reconocer palabras de la forma {w|w tiene cantidad par de 0's y 1's'}"<<endl;
    cout<<"ingresa la palabra    -> ";
    getline(cin,cadena);

    estado =0;

    for (unsigned int i = 0; i < cadena.length(); ++i) {
        estado = matriz[estado][tipoSimbolo(cadena.at(i))];
        if(estado == 4)
        {
            break;
        }
    }

    if(estado == 0)
    {
        cout<<"la cadena es valida"<<endl<<endl;
    }
    else
    {
        cout<<"la cadena es invalida"<<endl<<endl;
    }
    }

    return 1;//a.exec();
}

int tipoSimbolo(char c)
{
    if(c == '0')
    {
        return 0;
    }
    else if(c == '1')
    {
        return 1;
    }
    else
    {
        return 4;
    }
}

