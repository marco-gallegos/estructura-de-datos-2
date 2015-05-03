#ifndef ADMIN_H
#define ADMIN_H
#include"imagen.h"

using namespace std;

class admin
{
public:
    admin();

    void escribir(imagen img);
    void leer();

    void eliminar(string nom);

    void buscar(string f);
};

#endif // ADMIN_H
