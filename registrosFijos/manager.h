#ifndef MANAGER_H
#define MANAGER_H

#include "librofijo.h"
#include <iostream>
#include <list>
using namespace std;

class Manager
{
public:
    Manager();

    void escribir(LibroFijo &libro);
    void leer();
    void buscar(string titulo);
    list<LibroFijo> buscar2(string titulo);
    void imprimir(LibroFijo &libro);
    void eliminar(string titulo);
    void eliminar2(string titulo);

};

#endif // MANAGER_H
