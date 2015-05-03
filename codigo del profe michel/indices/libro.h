#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
using namespace std;

class Libro
{
public:
    Libro();
    ~Libro();

    string getTitulo() const;
    void setTitulo(const string &value);

    string getAutor() const;
    void setAutor(const string &value);

    string getYear() const;
    void setYear(const string &value);

    string getEditorial() const;
    void setEditorial(const string &value);

    string getEdicion() const;
    void setEdicion(const string &value);

    string getLlave();

private:
    string titulo;
    string autor;
    string year;
    string editorial;
    string edicion;
};

#endif // LIBRO_H
