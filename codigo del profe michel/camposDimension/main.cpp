#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
    Libro l;
    Manager m;
    string temp;
    int op;

    do {
        cout << "1. Guardar Libro" << endl;
        cout << "2. Mostrar"       << endl;

        cin >> op;
        cin.ignore();
        switch (op) {
        case 1:
            cout << "Titulo: " << endl;
            getline(cin, temp);
            l.setTitulo(temp);

            cout << "Autor: " << endl;
            getline(cin, temp);
            l.setAutor(temp);

            cout << "Año: "  << endl;
            getline(cin, temp);
            l.setYear(temp);

            cout << "Editorial" << endl;
            getline(cin, temp);
            l.setEditorial(temp);

            m.escribir(l);

            break;

        case 2:
            m.mostrar();
            break;
        default:
            break;
        }
    } while (op!=0);
    return 0;
}

