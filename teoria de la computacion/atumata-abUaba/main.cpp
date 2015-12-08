#include <iostream>

using namespace std;

int tipoSimbolo(char c);

int main()
{
    int matriz [][3]={
        {1,4,4},
        {4,2,4},
        {3,4,4},
        {1,2,4},
        {4,4,4}
    };
    int estado;
    string cadena;
    cout<<"un AFD para reconocer (ab U aba)*"<<endl;
    cout<<"ingresa la palabra -> ";getline(cin,cadena);

    estado=0;
    for (unsigned int i = 0; i < cadena.length(); ++i)
    {
        estado= matriz[estado][tipoSimbolo(cadena.at(i))];
        if(estado==4)
            break;
    }

    if(estado==0||estado==2||estado==3)
    {
        cout<<"palabra valida "<<endl<<endl;
    }
    else
    {
        cout<<"cadena invalida "<<endl<<endl;
    }
    return 0;
}

int tipoSimbolo(char c)
{
    if(c=='a')
    {
        return 0;
    }
    else
        if(c=='b')
        {
            return 1;
        }
        else
        {
            return 2;
        }

}

