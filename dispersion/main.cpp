#include <iostream>
#include"dispersion.h"
#include"libreria.h"
using namespace std;

int main()
{
    libreria libreri;
    libro libr;
    string temp;
    int op;

    do {
        cout<<"1. guardarlibro"<<endl;
        cout<<"2. buscar"<<endl;
        cout<<"3. eliminar"<<endl;
        cin>>op;

        cin.ignore();
        switch (op) {
        case 1:
            cout<<"titulo"<<endl;
            cin>>temp;
            libr.setTitulo(temp);

            cout<<"autor"<<endl;
            cin>>temp;
            libr.setAutor(temp);

            cout<<"año"<<endl;
            cin>>temp;
            libr.setYear(temp);

            cout<<"editorial"<<endl;
            cin>>temp;
            libr.setEditorial(temp);

            libreri.guardar(libr);
            break;
        case 2:
                cout<<"titulo"<<endl;
                getline(cin,temp);
                libr.setTitulo(temp);

                cout<<"año"<<endl;
                getline(cin,temp);
                libr.setYear(temp);
                libreri.buscar(libr);
                break;
        default:
            break;
        }
    } while (op!=0);


    return 0;
}

