#include "imagen.h"


imagen::imagen()
{
}

void imagen::mostrar()
{
    cout<<"hora         :"<<hora<<endl
        <<"fecha        :"<<fecha<<endl
        <<"resolucion   :"<<resolucion<<endl
        <<"id camara    :"<<id_camara<<endl
        <<"tipo         :"<<tipo<<endl;
}

string imagen::gethora() const
{
    return hora;
}

void imagen::sethora(const string &value)
{
hora=value;
}

string imagen::getfecha() const
{
    return fecha;
}
void imagen::setfecha(const string &value)
{
    fecha=value;
}

string imagen::getresolucion()const
{
    return resolucion;
}
void imagen::setresolucion(const string &value)
{
    resolucion=value;
}

string imagen::getid_camara()const
{
    return id_camara;
}

void imagen::setid_camara(const string &value)
{
    id_camara=value;
}

string imagen::gettipo()const
{
    return tipo;
}

void imagen::settipo(const string &value)
{
    tipo=value;
}
