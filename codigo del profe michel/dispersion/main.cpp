#include <iostream>
#include "libreria.h"

using namespace std;

int main()
{
    Libreria libreria;
    Libro libro;
    string temp;
    int op;

    do {
        cout << "1. Guardar libro" << endl;
        cout << "2. Buscar"        << endl;
        cout << "3. Eliminar"      << endl;
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1:
            cout << "Titulo: ";
            getline(cin, temp);
            libro.setTitulo(temp);

            cout << "Autor: ";
            getline(cin, temp);
            libro.setAutor(temp);

            cout << "Año:  ";
            getline(cin, temp);
            libro.setYear(temp);

            cout << "Editorial: ";
            getline(cin, temp);
            libro.setEditorial(temp);

            libreria.guardar(libro);
            break;

        case 2:
            cout << "Titulo: ";
            getline(cin, temp);
            libro.setTitulo(temp);

            cout << "Año:  ";
            getline(cin, temp);
            libro.setYear(temp);

            libreria.buscar(libro);
            break;

        case 3:
            cout << "Titulo: ";
            getline(cin, temp);
            libro.setTitulo(temp);

            cout << "Año:  ";
            getline(cin, temp);
            libro.setYear(temp);

            libreria.eliminar(libro);

            break;


        default:
            break;
        }

    } while (op!=0);
    cout << "Hello World!" << endl;
    return 0;
}

