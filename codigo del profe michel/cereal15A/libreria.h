#ifndef LIBRERIA_H
#define LIBRERIA_H


#include <cereal/types/vector.hpp>
#include "libro.h"


class Libreria
{
public:
    Libreria();
    ~Libreria();

    void guardar(Libro &libro)
    {
        libros.push_back(libro);
    }

    void mostrar()
    {
        for( unsigned int i = 0; i < libros.size(); i++ )
        {
            Libro l = libros[i];
            cout << l.getTitulo() + " " + l.getAutor() +  " " +
                    l.getYear()   + " " + l.getEditorial() << endl;
        }
    }

private:
    vector<Libro> libros;
};

#endif // LIBRERIA_H
