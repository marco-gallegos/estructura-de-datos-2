#include "listasimple.h"
#include<QDebug>
#include<string>
#include<nodo.h>

using namespace std;

void listasimple::inicializar()
{
    h=NULL;
    tam=0;
}


listasimple::listasimple()
{
    inicializar();
}

void listasimple::insertar(string dato)
{
    nodo *nuevo=new nodo(dato);
    nodo *aux=NULL;
    if(h==NULL)
    {
        h=nuevo;
        tam++;
    }
    else
    {
        aux=h;
        while(aux!=NULL)
        {
            aux=aux->sig;
        }
        aux=nuevo;
        tam++;
    }
}

//void listasimple::insertar(int posic)
