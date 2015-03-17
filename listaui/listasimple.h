#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include<nodo.h>
#include<string>
using namespace std;

class listasimple
{
public:

    nodo *h;
    int tam;

    listasimple();

    void inicializar();

    void insertar(string dato);
    void insertar(int posic);

    void eliminar();

    void mostrar();

};

#endif // LISTASIMPLE_H
