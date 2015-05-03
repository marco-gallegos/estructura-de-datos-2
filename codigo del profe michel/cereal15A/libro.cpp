#include "libro.h"

Libro::Libro()
{

}

Libro::~Libro()
{

}
string Libro::getTitulo() const
{
    return titulo;
}

void Libro::setTitulo(const string &value)
{
    titulo = value;
}
string Libro::getAutor() const
{
    return autor;
}

void Libro::setAutor(const string &value)
{
    autor = value;
}
string Libro::getYear() const
{
    return year;
}

void Libro::setYear(const string &value)
{
    year = value;
}
string Libro::getEditorial() const
{
    return editorial;
}

void Libro::setEditorial(const string &value)
{
    editorial = value;
}





