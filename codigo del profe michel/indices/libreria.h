#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "libro.h"
#include <map>

class Libreria
{
public:
    Libreria();
    ~Libreria();

    void guardar(Libro &libro);
    void mostrarIndice();
    void mostrarDatos();
    void buscar(string key);
    void borrar(string key);

    void crearIndiceSecundario();
    void mostrarIndiceSecundario();
    void buscarEditorial(string &editorial);

private:
    map<string, long> indice;
    multimap<string, string> sencundario;
};

#endif // LIBRERIA_H
