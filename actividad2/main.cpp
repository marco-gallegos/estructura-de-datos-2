#include <QCoreApplication>
#include"admin.h"
#include<iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc;
    string temp;

    imagen imgtemp;
    admin shotwell;
     do{
        cout<<"1. guardar img"<<endl
            <<"2. ver img's"<<endl;
        cin>>opc;
        cin.ignore();
        switch (opc)
        {
        case 1:
            cout<<"hora"<<endl;
            getline(cin,temp);
            imgtemp.sethora(temp);

            cout<<"fecha"<<endl;
            getline(cin,temp);
            imgtemp.setfecha(temp);

            cout<<"resolucion"<<endl;
            getline(cin,imgtemp.resolucion);

            cout<<"id camara"<<endl;
            getline(cin,imgtemp.id_camara);

            cout<<"tipo"<<endl;
            getline(cin,imgtemp.tipo);

            shotwell.escribir(imgtemp);
            break;
        case 2:
            cout<<"fecha";
            getline(cin,temp);

            shotwell.buscar(temp);

            break;
        default:

            break;
        }

    }while (opc!=0);



    return 0;
}
