#ifndef PELICULA_H
#define PELICULA_H
#include<iostream>
using namespace std;
class pelicula
{

    string name,protagonistas,director,estudio,genero,anio_estre,premios,calif;

public:
    pelicula();
    string getProtagonistas() const;
    void setProtagonistas(const string &value);
    string getCalif() const;
    void setCalif(const string &value);
    string getPremios() const;
    void setPremios(const string &value);
    string getAnio_estre() const;
    void setAnio_estre(const string &value);
    string getGenero() const;
    void setGenero(const string &value);
    string getEstudio() const;
    void setEstudio(const string &value);
    string getDirector() const;
    void setDirector(const string &value);
    string getName() const;
    void setName(const string &value);
};

#endif // PELICULA_H
