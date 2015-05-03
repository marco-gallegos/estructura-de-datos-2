#include "libreria.h"
#include <cereal/archives/xml.hpp>
#include <fstream>

Libreria::Libreria()
{
    fstream archivo("librosXML.xml", ios::in);

    if ( archivo.is_open() )
    {
        cereal::XMLInputArchive entrada( archivo );

        entrada >> libros;
    }
}

Libreria::~Libreria()
{
    fstream archivo("librosXML.xml", ios::out);

    cereal::XMLOutputArchive salida( archivo );

    salida << libros;
}

