#include "libro.h"

libro::libro()
{
}
string libro::getTitulo() const
{
    return titulo;
}

void libro::setTitulo(const string &value)
{
    titulo = value;
}
string libro::getAutor() const
{
    return autor;
}

void libro::setAutor(const string &value)
{
    autor = value;
}
string libro::getYear() const
{
    return year;
}

void libro::setYear(const string &value)
{
    year = value;
}
string libro::getEditorial() const
{
    return editorial;
}

void libro::setEditorial(const string &value)
{
    editorial = value;
}

string libro::getLlave() const
{
    return titulo+year;
}



