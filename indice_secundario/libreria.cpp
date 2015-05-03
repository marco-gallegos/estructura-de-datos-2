#include "libreria.h"
#include<map>
#include<fstream>
#include<list>

using namespace std;
libreria::libreria()
{


}

libreria::~libreria()
{
    fstream index();
    index.close();

    fstream sec("posmemato.txt",ios::out);
    if(sec.is_open())
    {
        for(multimap<string, string>::iterator i= secundario.begin()
            i!= secundario.end(),i++)
            sec<<(*i).first<<"|"<<(*i).second<<endl;
    }
    sec.close();
}

void libreria::crearindicesecundario()
{
    fstream archivo("posmemato.txt",ios::in);
    if(archivo.is_open())
    {
        for(map<string,long>::iterator i=indice.begin();i!=indice.end();i++)
        {
            string llaveprimaria = (*i).first;
            long pos=(*i).second;
            string temp;

            archivo.seekg(pos,ios::beg);

            getline(archivo,temp,'|');
            getline(archivo,temp,'|');
            getline(archivo,temp,'|');
            getline(archivo,temp,'|');

            secundario.insert(pair<string,string(temp,llaveprimaria));
        }
    }
}

void libreria::mostrareditorial(string &editorial)
{
    fstream archivo("posmemato.txt",ios::in);
    if(archivo.is_open())
    {
        list<string> llavesprimarias;
        for(multimap<string,string>::iterator i=secundario.equal_range(editorial).first;
            i!=secundario.equal_range(editorial).second;i++)
        {
            llavesprimarias.push_back((*i).first);
        }

    }
}
