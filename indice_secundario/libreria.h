#ifndef LIBRERIA_H
#define LIBRERIA_H
#include<map>
#include<iostream>
#include"libro.h"

using namespace std;
class libreria
{
public:
    libreria();

    map<string,long> indice;
    multimap<string,string> secundario;
    void crearindicesecundario();
    void guardar(libro &book);
    void mostrarindice();
    void mostrardatos();

    void mostrareditorial(string &editorial);
};



#endif // LIBRERIA_H
