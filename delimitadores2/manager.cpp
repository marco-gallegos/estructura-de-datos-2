#include "manager.h"

Manager::Manager()
{
}

void Manager::guardarLibro(Libro &libro)
{
    fstream archivo("/home/cebox/libros.txt",
                    ios::app | ios::out);

    if ( archivo.is_open() )
    {
        archivo << libro.getTitulo() << "|"
                << libro.getAutor()  << "|"
                << libro.getYear()   << "|"
                << libro.getEditorial() << "\n";//endl;
    }

    archivo.close();
}

void Manager::leer()
{
    fstream archivo("/home/cebox/libros.txt", ios::in);

    if ( archivo.is_open() )
    {
        Libro l;

        while( !archivo.eof() )
        {
            string temp;
            getline(archivo, temp, '|');
            if ( archivo.eof() )
                break;
            l.setTitulo(temp);

            getline(archivo, temp, '|');
            l.setAutor(temp);

            getline(archivo, temp, '|');
            l.setYear(temp);

            getline(archivo, temp);
            l.setEditorial(temp);

            mostrar(l);
        }
    }
}

void Manager::mostrar(Libro &libro)
{
    cout << "Titulo:    " << libro.getTitulo() << endl
         << "Autor:     " << libro.getAutor()  << endl
         << "Año:       " << libro.getYear()   << endl
         << "Editorial: " << libro.getEditorial() << endl << endl;

}

Libro Manager::buscar(string &nombre)
{
    Libro libro;
    fstream archivo("/home/cebox/libros.txt", ios::in);
    if ( archivo.is_open() )
    {

        Libro l;
        while( !archivo.eof() )
        {
            string temp;
            getline(archivo, temp, '|');
            if ( archivo.eof() )
                break;
            l.setTitulo(temp);

            getline(archivo, temp, '|');
            l.setAutor(temp);

            getline(archivo, temp, '|');
            l.setYear(temp);

            getline(archivo, temp);
            l.setEditorial(temp);

            if ( nombre == l.getTitulo() )
            {
                libro = l;
                break;
            }
        }
    }

    return libro;

}

void Manager::eliminar(string &nombre)
{
    fstream archivo("/home/cebox/libros.txt", ios::in);
    fstream temporal("/home/cebox/temp.txt", ios::out);

    if ( archivo.is_open() )
    {
        Libro l;
        while( !archivo.eof() )
        {
            string temp;
            getline(archivo, temp, '|');
            if ( archivo.eof() )
                break;
            l.setTitulo(temp);

            getline(archivo, temp, '|');
            l.setAutor(temp);

            getline(archivo, temp, '|');
            l.setYear(temp);

            getline(archivo, temp);
            l.setEditorial(temp);

            if (l.getTitulo() != nombre)
            {
                temporal << l.getTitulo() << "|"
                     << l.getAutor()  << "|"
                     << l.getYear()   << "|"
                     << l.getEditorial() << endl;
            }

        }


    }
    archivo.close();
    temporal.close();

    remove("/home/cebox/libros.txt"); // elimino
    rename("/home/cebox/temp.txt", "/home/cebox/libros.txt"); // cambio nombre
}
