#include "cifrador.h"
#include<fstream>
cifrador::cifrador()
{

}

void cifrador::cifrar(char llave)
{

    fstream archivo("/home/cebox/noticia.txt",ios::out|ios::in|ios::app);
    fstream a_cifrado("/home/cebox/cifrado.txt",ios::in|ios::out|ios::app);

    if(archivo.is_open())
    {

        string s;
        getline(archivo,s);
        cout<<s;
    }

    archivo.close();
    a_cifrado.close();
}
