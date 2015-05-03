#include "libreria.h"
#include <fstream>

Libreria::Libreria()
{

}

Libreria::~Libreria()
{

}

void Libreria::guardar(Libro &libro)
{
    fstream archivo("/Users/michel/dispersion15A.txt",
                    ios::out | ios::in );

    if ( !archivo.is_open() )
    {
        archivo.open("/Users/michel/dispersion15A.txt", ios::out);

        Dispersion dis;
        int direccion = dis.simple(libro.getLlave());
        cout << direccion << endl;

        archivo.seekp( direccion*50, ios_base::beg );

        archivo << libro.getTitulo() << "|"
                << libro.getAutor()  << "|"
                << libro.getYear()   << "|"
                << libro.getEditorial() << "|";
    }

    else{
        Dispersion dis;
        int direccion = dis.simple(libro.getLlave());
        cout << direccion << endl;

        archivo.seekp( direccion*50, ios_base::beg );

        archivo << libro.getTitulo() << "|"
                << libro.getAutor()  << "|"
                << libro.getYear()   << "|"
                << libro.getEditorial() << "|";
    }

    archivo.close();

}

void Libreria::buscar(Libro &libro)
{
    fstream archivo("/Users/michel/dispersion15A.txt",
                    ios::out | ios::in );

    if ( archivo.is_open() )
    {
        Dispersion dis;
        int direccion = dis.simple( libro.getLlave() );

        archivo.seekg( direccion*50, ios_base::beg );

        char c[1];

        archivo.read( c, 1);

        if ( archivo.eof() )
            cout << "No existe Libro";

        else if ( c[0] == 0  || c[0] == '*')
            cout << "No existe Libro";
        else
        {
            char datos[51];
            string registro;
            archivo.seekg( direccion*50, ios_base::beg );
            archivo.read( datos, 50 );
            datos[50] = '\0';

            registro = datos;

            cout << registro << endl;
        }

    }
}

void Libreria::eliminar(Libro &libro)
{
    fstream archivo("/Users/michel/dispersion15A.txt",
                    ios::out | ios::in );

    if ( archivo.is_open() )
    {
        Dispersion dis;
        int direccion = dis.simple( libro.getLlave() );

        archivo.seekg( direccion*50, ios_base::beg );

        char c[1];

        archivo.read( c, 1);

        if ( archivo.eof() )
            cout << "No existe Libro";

        else if ( c[0] == 0 || c[0] == '*' )
            cout << "No existe Libro";
        else
        {
            string temp;
            Libro l;
            archivo.seekg( direccion*50, ios_base::beg );
            getline( archivo, temp, '|');
            l.setTitulo(temp);

            getline( archivo, temp, '|'); // autor
            getline( archivo, temp, '|'); // year

            l.setYear(temp);

            //cout << l.getTitulo() << " " << l.getYear() << endl;

            if ( libro.getTitulo() == l.getTitulo() &&
                 libro.getYear()   == l.getYear() )
            {
                archivo.seekg( direccion*50, ios_base::beg );
                archivo << "*";
                cout << "Eliminado";
            }


        }

    }
}

