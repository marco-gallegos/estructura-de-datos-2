#include <iostream>

#include <cereal/types/vector.hpp>

#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>
#include <fstream>
#include "libreria.h"

using namespace std;

void guardarXML( vector<int> &v )
{

    fstream archivo("cerealXML.xml", ios::out);

    cereal::XMLOutputArchive salida( archivo );

    salida << v;  //serealizamos vector
}

void guardarJSON( vector<int> &v )
{
    fstream archivo("cerealJSON.json", ios::out);

    cereal::JSONOutputArchive salida( archivo );

    salida << v;  //serealizamos vector
}

void recuperaXML()
{
    vector<int> arreglo;

    fstream archivo("/Users/michel/cerealXML.xml", ios::in);

    cereal::XMLInputArchive entrada( archivo );

    entrada >> arreglo; //deserealizamos

    for( unsigned int i = 0; i < arreglo.size(); i++ )
        cout << arreglo[i] << endl ;
}

void recuperaJSON()
{
    vector<int> arreglo;

    fstream archivo("/Users/michel/cerealJSON.json", ios::in);

    cereal::JSONInputArchive entrada( archivo );

    entrada >> arreglo;

    for( unsigned int i = 0; i < arreglo.size(); i++ )
        cout << arreglo[i] << endl ;
}

int main()
{
   /* vector<int> arreglo;

    arreglo.push_back(23);
    arreglo.push_back(3);
    arreglo.push_back(2);
    arreglo.push_back(1);
    arreglo.push_back(10);

    guardarXML(arreglo);
    guardarJSON(arreglo);
    */

    /*
    recuperaXML();
    recuperaJSON();
    */

    Libro libro;
    Libreria libreria;

    libro.setTitulo("Matematicas");
    libro.setAutor("Lopez");
    libro.setYear("2010");
    libro.setEditorial("Porrua");
/*
    fstream archivo("cerealLibro.json", ios::out);
    cereal::JSONOutputArchive salida( archivo );

    salida << libro; // serealizamos un libro
    */

    libreria.guardar(libro);
    libreria.mostrar();

    return 0;
}
