#include<fstream>

#include "libreria.h"


libreria::libreria()
{
}

void libreria::guardar(libro &libr)
{
    fstream archivo("dispersion.txt", ios::in | ios::out);

    if(!archivo.is_open())
    {
        archivo.open("dispersion.txt",ios::out);

        dispersion dis;
        int direccion=dis.simple(libr.getLlave());

        archivo.seekp(direccion*50, ios_base::beg);

        archivo << libr.getTitulo() <<"|"
                   <<libr.getAutor()<<"|"
                     <<libr.getYear()<<"|"
                       <<libr.getEditorial()<<"|";
    }
    else
    {
        dispersion dis;
        int direccion=dis.simple(libr.getLlave());

        archivo.seekp(direccion*50, ios_base::beg);

        archivo << libr.getTitulo() <<"|"
                   <<libr.getAutor()<<"|"
                     <<libr.getYear()<<"|"
                       <<libr.getEditorial()<<"|";
    }

    archivo.close();
}

void libreria::buscar(libro &libr)
{
    fstream archivo("dispersion.txt", ios::in | ios::out);

    if(archivo.is_open())
    {
        dispersion dis;
        int direccion =dis.simple(libr.getLlave());

        archivo.seekg(direccion*50,ios_base::beg);
        char c[1];

        archivo.read(c,1);
        if(archivo.eof())
            cout<<"no existe el archivo"<<endl;
        else
        {
            if(c[0]==0)
                cout<<"no existe el libro";
            else
            {
                char datos[51];
                string registro;

                archivo.seekg(direccion*50,ios_base::beg);
                archivo.read(datos,49);
                datos[50]='\0';


                registro = datos;
                cout<<registro<<endl;
            }
        }
    }
}
