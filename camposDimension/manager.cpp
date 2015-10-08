#include "manager.h"

Manager::Manager()
{
}

void Manager::escribir(Libro libro)
{
    fstream archivo("/home/cebox/librosCampos.txt",
                    ios::out | ios::app );

    if (archivo.is_open())
    {
        int tam;

        tam = libro.getTitulo().length();

        archivo.write( (char *)&tam, sizeof(tam) ); // encabezado
        archivo.write( libro.getTitulo().c_str(), tam); //datos

        tam = libro.getAutor().length();
        archivo.write( (char *)&tam, sizeof(tam) ); // encabezado
        archivo.write( libro.getAutor().c_str(), tam); //datos

        tam = libro.getYear().length();
        archivo.write( (char *)&tam, sizeof(tam) ); // encabezado
        archivo.write( libro.getYear().c_str(), tam); //datos

        tam = libro.getEditorial().length();
        archivo.write( (char *)&tam, sizeof(tam) ); // encabezado
        archivo.write( libro.getEditorial().c_str(), tam); //datos

    }


    archivo.close();
}

void Manager::mostrar()
{
    fstream archivo("/home/cebox/librosCampos.txt",
                    ios::in);

    if ( archivo.is_open() )
    {
        int tam;
        char *ti;
        char *au;
        char *ye;
        char *ed;

        while( !archivo.eof() )
        {
            archivo.read( (char *)&tam, sizeof(tam) ); //leo dimension
            if ( archivo.eof() ) break;
            ti = new char[tam+1];                      // arreglo dinamico
            archivo.read( ti, tam );                  // leo campo
            ti[tam] = '\0';

            archivo.read( (char *)&tam, sizeof(tam) );
            au = new char[tam+1];
            archivo.read( au, tam);
            au[tam] = '\0';

            archivo.read( (char *)&tam, sizeof(tam) );
            ye = new char[tam+1];
            archivo.read( ye, tam );
            ye[tam] = '\0';

            archivo.read( (char *)&tam, sizeof(tam) );
            ed = new char[tam+1];
            archivo.read( ed, tam );
            ed[tam] = '\0';

            cout << "Titulo:     " << ti << endl;
            cout << "Autor:      " << au << endl;
            cout << "Año:        " << ye << endl;
            cout << "Editorial:  " << ed << endl << endl;

            delete ti;
            delete au;
            delete ye;
            delete ed;

        }

    }




}
