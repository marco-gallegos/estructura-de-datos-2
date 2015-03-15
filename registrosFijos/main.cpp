#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
    Manager m;
    LibroFijo libro;
    int op;


    do {
        cout << "1. Guardar Libro" << endl;
        cout << "2. Mostrar"       << endl;
        cout << "3. Buscar"        << endl;
        cout << "4. Eliminar"      << endl;
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1:
            cout << "Titulo:    " << endl;
            cin.getline(libro.titulo, sizeof(libro.titulo) );

            cout << "Autor:     " << endl;
            cin.getline(libro.autor, sizeof(libro.autor) );

            cout << "Año:       " << endl;
            cin >> libro.year;
            cin.ignore();

            cout << "Editorial: " << endl;
            cin.getline( libro.editorial, sizeof(libro.editorial) );

            m.escribir(libro);
            break;

        case 2:
            m.leer();
            break;

        case 3:
           {
            string titulo;
            list<LibroFijo> libros;
            cout << "Titulo a Buscar: ";
            getline(cin, titulo);
            libros = m.buscar2(titulo);

            for( list<LibroFijo>::iterator i = libros.begin();
                 i != libros.end(); i++)
            {
                m.imprimir(*i);
            }

            break;
        }

        case 4:
        {
            string titulo;
            cout << "Titulo a Eliminar: " ;
            getline(cin, titulo);
            m.eliminar2(titulo);

            break;
        }
        default:
            break;
        }
    } while (op!=0);

    return 0;
}

