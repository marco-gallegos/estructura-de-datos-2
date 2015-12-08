/*
214520198
marco antonio gallegos loaeza

diego gonzalez gonzalez

Estructuras de datos 2 D09
Guerrero Segura Miguel Angel
*/


#include <QCoreApplication>
#include<iostream>
#include<manager.h>

using namespace std;



//int main(int argc, char *argv[])
int main()
{
    //QCoreApplication a(argc, argv);

    while (1)
    {
        cout<<"1 = guardar"<<endl;
        cout<<"2 = leer"<<endl;
        int opc;
        cin>>opc;

        switch (opc) {
        case 1:
            guardar();
            break;
        case 2:
            leer();
            break;
        default:
            cout<<"opcion no valida";
            break;
        }

    }
    return 1;//a.exec();
}
