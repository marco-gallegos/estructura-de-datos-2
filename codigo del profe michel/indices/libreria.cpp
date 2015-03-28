#include "libreria.h"
#include <fstream>
#include <cstdlib>
#include <list>

Libreria::Libreria()
{
    fstream index("/Users/michel/indice15A.txt", ios::in);

    if (index.is_open())
    {
        string key;
        string valor;
        while( !index.eof() )
        {
            getline(index, key, '|');

            if(index.eof()) break;
            getline(index, valor);

            indice[key] = atol(valor.c_str());
        }
    }

    fstream sec("/Users/michel/editorial.txt", ios::in);

    if ( sec.is_open() )
    {
        string llaveSecundaria;
        string llavePrimaria;

        while( !sec.eof() )
        {
            getline(sec, llaveSecundaria, '|');

            if ( sec.eof() ) break;

            getline(sec, llavePrimaria);

            sencundario.insert(
                        pair<string, string>(llaveSecundaria, llavePrimaria));

        }
    }
}

Libreria::~Libreria()
{
    fstream index("/Users/michel/indice15A.txt", ios::out);

    if (index.is_open())
    {
        for(map<string, long>::iterator i = indice.begin();
            i != indice.end(); i++)
        {
            index << i->first << "|" << i->second << endl;
        }
    }

    index.close();

    fstream sec("/Users/michel/editorial.txt", ios::out);

    if ( sec.is_open() )
    {
        for (multimap<string, string>::iterator i = sencundario.begin();
             i != sencundario.end(); i++)
            sec << (*i).first << "|" << (*i).second << endl;
    }

    sec.close();
}

void Libreria::guardar(Libro &libro)
{
    fstream archivo("/Users/michel/indiceDatos.txt", ios::out | ios::app);

    if (archivo.is_open())
    {
        archivo.seekp(0, ios_base::end);
        long valor = archivo.tellp();
        indice[ libro.getLlave() ] = valor;
        sencundario.insert(
                    pair<string, string>(libro.getEditorial(), libro.getLlave()));

        archivo << libro.getTitulo()     << "|"
                << libro.getAutor()      << "|"
                << libro.getYear()       << "|"
                << libro.getEditorial()  << "|"
                << libro.getEdicion() << endl;
    }

    archivo.close();
}

void Libreria::mostrarIndice()
{
    for(map<string, long>::iterator i = indice.begin();
        i != indice.end(); i++)
    {
        cout << i->first << "->" << i->second << endl;
    }
}

void Libreria::mostrarDatos()
{
    fstream archivo("/Users/michel/indiceDatos.txt",
                    ios::in);

    if (archivo.is_open())
    {
        long pos;
        for(map<string, long>::iterator i = indice.begin();
            i != indice.end(); i++)
        {
            //cout << i->first << "->" << i->second << endl;
            pos = i->second;

            archivo.seekg(pos, ios_base::beg);
            string temp;

            getline(archivo, temp);
            cout << temp << endl;
        }
    }
}

void Libreria::buscar(string key)
{
    map<string, long>::iterator i = indice.find(key);

    if ( i != indice.end() )
    {
        fstream archivo("/Users/michel/indiceDatos.txt",
                        ios::in);

        if (archivo.is_open())
        {
            long pos = i->second;

            archivo.seekg(pos, ios_base::beg);
            string temp;

            getline(archivo, temp);
            cout << temp << endl;
        }

    }
    else
        cout << "No existe" << endl;
}

void Libreria::borrar(string key)
{
     map<string, long>::iterator i = indice.find(key);

     if ( i != indice.end() )
     {
         indice.erase(i);
     }
}

void Libreria::crearIndiceSecundario()
{
    fstream archivo("/Users/michel/indiceDatos.txt", ios::in);
    sencundario.clear();

    if (archivo.is_open())
    {
        for (map<string, long>::iterator i = indice.begin();
             i != indice.end(); i++)
        {
            string llavePrimari = (*i).first;
            long pos = (*i).second;

            archivo.seekg(pos, ios::beg);

            string temp;

            getline(archivo, temp, '|');
            getline(archivo, temp, '|');
            getline(archivo, temp, '|');
            getline(archivo, temp, '|');

            sencundario.insert( pair<string, string>(temp, llavePrimari));
        }
    }
}

void Libreria::mostrarIndiceSecundario()
{
    for (multimap<string, string>::iterator i = sencundario.begin();
         i != sencundario.end(); i++)
        cout << (*i).first << " " << (*i).second << endl;
}

void Libreria::buscarEditorial(string &editorial)
{
    fstream archivo("/Users/michel/indiceDatos.txt", ios::in);

    if (archivo.is_open())
    {

        list<string> llavesPrimarias;
        for (multimap<string, string>::iterator i = sencundario.equal_range(editorial).first;
             i != sencundario.equal_range(editorial).second; i++)
        {
            llavesPrimarias.push_back((*i).second);
        }

        for (list<string>::iterator i = llavesPrimarias.begin();
             i != llavesPrimarias.end(); i++)
        {
            buscar( *i );
        }

    }
}

