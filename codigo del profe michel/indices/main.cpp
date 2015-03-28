#include <iostream>
#include "libreria.h"

using namespace std;

int main()
{
    Libreria libreria;
    Libro libro;
    string temp;
    string key;
    int op;

    do{
        cout << "1. Guardar" << endl;
        cout << "2. Mostrar Indice" << endl;
        cout << "3. Mostrar Datos" << endl;
        cout << "4. Buscar" << endl;
        cout << "5. Eliminar" << endl;
        cout << "6. Crear Indice Secundario" << endl;
        cout << "7. Mostrar Indice Secundario" << endl;
        cout << "8. Buscar Editorial" << endl;
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1:
            cout << "Titulo:    ";
            getline(cin, temp);
            libro.setTitulo(temp);

            cout << "Autor:     ";
            getline(cin, temp);
            libro.setAutor(temp);

            cout << "Año:       ";
            getline(cin, temp);
            libro.setYear(temp);

            cout << "Editorial: ";
            getline(cin, temp);
            libro.setEditorial(temp);

            cout << "Edicion:   ";
            getline(cin, temp);
            libro.setEdicion(temp);

            libreria.guardar(libro);
            break;

        case 2:
            libreria.mostrarIndice();
            break;

        case 3:
            libreria.mostrarDatos();
            break;

        case 4:
            cout << "Titulo: ";
            getline(cin, temp);
            key += temp;

            cout << "Autor: ";
            getline(cin, temp);
            key += temp;

            cout << "Edicion: ";
            getline(cin, temp);
            key += temp;

            libreria.buscar(key);
            break;

        case 5:
            key.clear();
            cout << "Titulo: ";
            getline(cin, temp);
            key += temp;

            cout << "Autor: ";
            getline(cin, temp);
            key += temp;

            cout << "Edicion: ";
            getline(cin, temp);
            key += temp;

            libreria.borrar(key);
            break;

        case 6:
            libreria.crearIndiceSecundario();
            break;

        case 7:
            libreria.mostrarIndiceSecundario();
            break;

        case 8:
            cout << "Editorial: ";
            getline(cin, temp);
            libreria.buscarEditorial(temp);
            break;
        default:
            break;
        }
    }while( op != 0 );

    return 0;
}

