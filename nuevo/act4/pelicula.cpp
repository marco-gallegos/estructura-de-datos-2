#include "pelicula.h"


string pelicula::getProtagonistas() const
{
    return protagonistas;
}

void pelicula::setProtagonistas(const string &value)
{
    protagonistas = value;
}

string pelicula::getCalif() const
{
    return calif;
}

void pelicula::setCalif(const string &value)
{
    calif = value;
}

string pelicula::getPremios() const
{
    return premios;
}

void pelicula::setPremios(const string &value)
{
    premios = value;
}

string pelicula::getAnio_estre() const
{
    return anio_estre;
}

void pelicula::setAnio_estre(const string &value)
{
    anio_estre = value;
}

string pelicula::getGenero() const
{
    return genero;
}

void pelicula::setGenero(const string &value)
{
    genero = value;
}

string pelicula::getEstudio() const
{
    return estudio;
}

void pelicula::setEstudio(const string &value)
{
    estudio = value;
}

string pelicula::getDirector() const
{
    return director;
}

void pelicula::setDirector(const string &value)
{
    director = value;
}

string pelicula::getName() const
{
    return name;
}

void pelicula::setName(const string &value)
{
    name = value;
}
pelicula::pelicula()
{
}
