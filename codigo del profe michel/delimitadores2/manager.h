#ifndef MANAGER_H
#define MANAGER_H

#include "libro.h"
#include <fstream>

using namespace std;

class Manager
{
public:
    Manager();

    void guardarLibro(Libro &libro);
    void leer();
    void mostrar(Libro &libro);
    Libro buscar(string &nombre);
    void eliminar(string &nombre);
};

#endif // MANAGER_H
