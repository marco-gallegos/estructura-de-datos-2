#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "libro.h"
#include "dispersion.h"

class Libreria
{
public:
    Libreria();
    ~Libreria();

    void guardar(Libro &libro);
    void buscar(Libro &libro);
    void eliminar(Libro &libro);
};

#endif // LIBRERIA_H
