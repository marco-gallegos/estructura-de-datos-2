#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<fstream>

using namespace std;

void guardar()
{
    string nom,direccion,ciudad,estado,cp,profession;
    string arch;
    cout<<"nombre de el archivo : "<<endl;cin>>arch;
    arch="/home/cebox/"+arch;
    cout<<"nombre      : ";cin>>nom;
    cout<<"direccion   : ";cin>>direccion;
    cout<<"ciudad      : ";cin>>ciudad;
    cout<<"estado      : ";cin>>estado;
    cout<<"codigo post : ";cin>>cp;
    cout<<"giro        : ";cin>>profession;


    fstream file(arch,ios::app|ios::out);
}

#endif // MANAGER_H
