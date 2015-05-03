#include "manager.h"
#include <fstream>

Manager::Manager()
{
}

void Manager::escribir(LibroFijo &libro)
{
    fstream archivo("librosFijos.txt",
                    ios::out | ios::app | ios::binary );

    if ( archivo.is_open() )
    {
        archivo.write( (char *)&libro, sizeof(libro) );
    }

    archivo.close();
}

void Manager::leer()
{
    fstream archivo("librosFijos.txt",
                    ios::in | ios::binary );

    if ( archivo.is_open() )
    {
        while( !archivo.eof() )
        {
            LibroFijo libro;
            archivo.read( (char *)&libro, sizeof(libro) );
            if ( archivo.eof() ) break;

            cout << "Titulo:    " << libro.titulo << endl;
            cout << "Autor:     " << libro.autor << endl;
            cout << "Año:       " << libro.year << endl;
            cout << "Editorial: " << libro.editorial << endl << endl;
        }
    }
}

void Manager::buscar(string titulo)
{
    fstream archivo("librosFijos.txt",
                    ios::in | ios::binary );

    if ( archivo.is_open() )
    {
        while( !archivo.eof() )
        {
            LibroFijo libro;
            archivo.read( (char *)&libro, sizeof(libro) );
            if ( archivo.eof() ) break;

            if (libro.titulo == titulo)
            {
                cout << "Titulo:    " << libro.titulo << endl;
                cout << "Autor:     " << libro.autor << endl;
                cout << "Año:       " << libro.year << endl;
                cout << "Editorial: " << libro.editorial << endl << endl;
            }
        }
    }
}

list<LibroFijo> Manager::buscar2(string titulo)
{
    list<LibroFijo> libros;

    fstream archivo("librosFijos.txt",
                    ios::in | ios::binary );

    if ( archivo.is_open() )
    {
        while( !archivo.eof() )
        {
            LibroFijo libro;
            archivo.read( (char *)&libro, sizeof(libro) );
            if ( archivo.eof() ) break;

            if (libro.titulo == titulo)
            {
                libros.push_back(libro);
            }
        }
    }

    return libros;
}

void Manager::imprimir(LibroFijo &libro)
{
    cout << "Titulo:    " << libro.titulo << endl;
    cout << "Autor:     " << libro.autor << endl;
    cout << "Año:       " << libro.year << endl;
    cout << "Editorial: " << libro.editorial << endl << endl;
}

void Manager::eliminar(string titulo)
{
    fstream archivo("librosFijos.txt",
                    ios::in | ios::binary );

    fstream temp("temporal.txt", ios::out | ios::binary);

    if (archivo.is_open())
    {
        while( !archivo.eof() )
        {
            LibroFijo libro;
            archivo.read( (char *)&libro, sizeof(libro) );
            if ( archivo.eof() ) break;

            if (libro.titulo != titulo)
            {
                temp.write( (char *)&libro, sizeof(libro) );

            }
        }

        archivo.close();
        temp.close();

        remove("librosFijos.txt");
        rename("temporal.txt", "librosFijos.txt");
    }
}

void Manager::eliminar2(string titulo)
{
    fstream archivo("librosFijos.txt",
                    ios::in | ios::out | ios::binary );

    //fstream archivo("librosFijos.txt")

    if (archivo.is_open())
    {
        long double pos;

        while( !archivo.eof() )
        {
            pos = archivo.tellp();
            LibroFijo libro;

            archivo.read( (char *)&libro, sizeof(libro) );
            if ( archivo.eof() ) break;
            if ( libro.titulo == titulo )
            {
                archivo.seekp(pos, ios_base::beg);
                archivo.put('*');
                break;
            }
        }
    }

    archivo.close();

}
