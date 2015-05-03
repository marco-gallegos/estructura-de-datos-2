#include "admin.h"
#include<iostream>
#include<fstream>


using namespace std;

admin::admin()
{
}

void admin::escribir(imagen img)
{
    fstream archivo("xd",ios::out | ios::app | ios::binary);

    if(archivo.is_open())
    {
        int tam;
        tam=img.gethora().length();
        archivo.write((char *)&tam,sizeof(tam));
        archivo.write(img.gethora().c_str() , tam);

        cout<<"tamaño hora"<<tam<<"******"<<endl;

        tam= img.getfecha().length();

        cout<<"tamaño fecha"<<tam<<"******"<<endl;
        archivo.write((char *)&tam , sizeof(tam) );
        archivo.write(img.getfecha().c_str(),tam);

        cout<<img.getfecha()<<"*******"<<endl;

        tam=img.getresolucion().length();
        archivo.write((char *)&tam,sizeof(tam));
        archivo.write(img.getresolucion().c_str(),tam);

        tam=img.getid_camara().length();
        archivo.write((char *)&tam,sizeof(tam));
        archivo.write(img.getid_camara().c_str(),tam);

        tam=img.gettipo().length();
        archivo.write((char *)&tam,sizeof(tam));
        archivo.write(img.gettipo().c_str(),tam);
    }

    archivo.close();
}

void admin::buscar(string f)
{
    char* hora;
    char* fecha;
    char* resolucion;
    char* idcamara;
    char* tipo;


    fstream archivo("xd", ios::in | ios::binary);
    if (archivo.is_open())
    {
        while (!archivo.eof())
        {
            int tam;
            archivo.read((char*)&tam,sizeof(tam));
            if(archivo.eof())break;

            hora=new char[tam+1];
            archivo.read(hora,tam);
            hora[tam]='\0';

            archivo.read((char*)&tam,sizeof(tam));
            fecha=new char[tam+1];
            archivo.read(fecha,tam);
            fecha[tam]='\0';


            string fechastr;
            for(int i=0;i<tam;i++)
            {
                fechastr=fechastr+fecha[i];
            }


            archivo.read((char*)&tam,sizeof(tam));
            resolucion=new char[tam+1];
            archivo.read(resolucion,tam);
            resolucion[tam]='\0';

            archivo.read( (char*)&tam ,sizeof(tam));
            idcamara=new char[tam+1];
            archivo.read(idcamara,tam);
            idcamara[tam]='\0';


            archivo.read((char*)&tam,sizeof(tam));
            tipo=new char[tam+1];
            archivo.read(tipo,tam);
            tipo[tam]='\0';

            if(fechastr==f)
            {
                cout<<hora<<endl
                   <<fecha<<endl
                  << resolucion<<endl
                  << idcamara <<endl
                  <<tipo<<endl;
            }
            else
            {
                cout<<"no shi encuentra"<<endl;
            }

            delete hora;
            delete fecha;
            delete resolucion;
            delete idcamara;
            delete tipo;

        }
    }
    archivo.close();
}
