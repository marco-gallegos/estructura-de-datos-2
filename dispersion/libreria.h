#ifndef LIBRERIA_H
#define LIBRERIA_H
#include"libro.h"
#include"dispersion.h"

class libreria
{
public:
    libreria();

    void guardar(libro &libr);
    void buscar(libro &libr);
};

#endif // LIBRERIA_H
