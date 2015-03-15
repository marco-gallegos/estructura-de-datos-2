#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
    Libro l;
    Manager m;
    string temp;
    int op;

    do{

        cout << "1. Guardar Libro"  << endl;
        cout << "2. Mostrar Libros" << endl;
        cout << "3. Buscar"         << endl;
        cout << "4. Eliminar"       << endl;
        cin >> op;
        cin.ignore();
        switch (op) {
        case 1:
            cout << "Titulo del Libro: " << endl;
            getline(cin, temp);
            l.setTitulo(temp);

            cout << "Autor: " << endl;
            getline(cin, temp);
            l.setAutor(temp);

            cout << "Año: " << endl;
            getline(cin, temp);
            l.setYear(temp);

            cout << "Editorial: " << endl;
            getline(cin, temp);
            l.setEditorial(temp);

            m.guardarLibro(l);
            break;

        case 2:
            m.leer();

            break;

        case 3:
            cout << "Titulo del Libro a Buscar: " << endl;
            getline(cin, temp);

            l = m.buscar(temp);

            if ( !l.getTitulo().empty() )
                m.mostrar(l);
            else cout << "No existe el Libro" << endl;
            break;

        case 4:
            cout << "Titulo del Libro a eliminar: " << endl;
            getline(cin, temp);

            m.eliminar(temp);
            break;
        default:
            break;
        }

    }while( op != 0 );


    return 0;
}

