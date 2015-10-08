#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<fstream>
using namespace std;

/*
214520198
marco antonio gallegos loaeza

diego gonzalez gonzalez

Estructuras de datos 2 D09
Guerrero Segura Miguel Angel
*/

void leer_qfd()
{

}



void guardar()
{
    string nom,direccion,ciudad,estado,cp,profession;
    string arch;
    cin.ignore();
    cout<<"nombre de el archivo : "<<endl;getline(cin,arch);
    arch="/home/cebox/"+arch;
    cout<<"nombre      : ";getline(cin,nom);
    cout<<"direccion   : ";getline(cin,direccion);
    cout<<"ciudad      : ";getline(cin,ciudad);
    cout<<"estado      : ";getline(cin,estado);
    cout<<"codigo post : ";getline(cin,cp);
    cout<<"giro        : ";getline(cin,profession);


    fstream file;
    file.open(arch.c_str(), ios::app | ios::out);

    if(!file.is_open())
    {
        cout<<"no se puede almacenar"<<endl;
        return;
    }

    file<<nom<<"|"
          <<direccion<<"|"
            <<ciudad<<"|"
              <<estado<<"|"
                <<cp<<"|"
               <<profession<<endl;



    file.close();

}

void leer()
{
    string nom_arch;
    //si se le da una ruta especifica ahi lo guardara si no
    //solo se creara en la carpeta del proyecto
    cout<<"nombre de el archivo  : ";cin>>nom_arch;


    //nom_arch="/home/cebox/"+nom_arch;

    fstream file;
    file.open(nom_arch.c_str(),ios::in);

    if(!file.is_open())
    {
        cout<<"no se puede abrir"<<endl;
        return;
    }
    string nom,direccion,ciudad,estado,cp,profession;

    while(!file.eof())
    {
        string temp;
        getline(file,temp,'|');
        cout<<temp<<endl;
        getline(file,temp,'|');
        cout<<temp<<endl;
        getline(file,temp,'|');
        cout<<temp<<endl;
        getline(file,temp,'|');
        cout<<temp<<endl;
        getline(file,temp,'|');
        cout<<temp<<endl;
        getline(file,temp);
        cout<<temp<<endl;
    }



}


#endif // MANAGER_H
