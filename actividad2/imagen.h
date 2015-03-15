#ifndef IMAGEN_H
#define IMAGEN_H

#include<iostream>
using namespace std;
class imagen
{
//private:
public:
    string hora;
    string fecha;
    string resolucion;
    string id_camara;
    string tipo;

//public:
    imagen();
    string gethora()const;
    string getfecha()const;
    string getresolucion()const;
    string getid_camara()const;
    string gettipo()const;
    void sethora(const string &value);
    void setfecha(const string &value);
    void setresolucion(const string &value);
    void setid_camara(const string &value);
    void settipo(const string &value);

    void mostrar();
};

#endif // IMAGEN_H
