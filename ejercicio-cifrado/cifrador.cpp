#include "cifrador.h"
#include<fstream>
cifrador::cifrador()
{

}

void cifrador::cifrar(char llave)
{
    fstream archivo("/home/cebox/noticia.txt");
    fstream cifrado("/home/cebox/n_noticia.txt",ios::app);
    if (archivo.is_open() && cifrado.is_open())
    {
        string s;
        int tam=0;
        while (!archivo.eof())
        {
            string txt;
            bool cesar=1;
            getline(archivo,s,',');
            tam+=s.length();
            if (tam>=100)
            {
                (cesar==1)? cesar=0:cesar=1;
                tam=0;
            }
            for (int posic = 0; posic < s.length(); ++posic)
            {
                if (cesar==1)
                {
                    txt+=s.at(posic)+int(llave);
                }
                else
                {
                    txt+=s[posic]^llave;
                }
            }
            if (archivo.eof())
            {
                cifrado<<txt;
            }
            else
            {
                cifrado<<txt<<',';
            }
        }
    }
    cifrado.close();
    archivo.close();
}

void cifrador::descifrar(char llave)
{
    fstream cifrado("/home/cebox/n_noticia.txt");
    fstream descifrado("/home/cebox/des_noticia.txt",ios::app);
    if (cifrado.is_open() && descifrado.is_open())
    {
        string cif;
        int tam=0;
        while (!cifrado.eof())
        {
            string descif;
            bool cesar=1;
            getline(cifrado,cif,',');
            tam+=cif.length();
            if (tam>=100)
            {
                (cesar==1)? cesar=0:cesar=1;
                tam=0;
            }
            for (int posic = 0; posic < cif.length(); ++posic)
            {
                if (cesar==1)
                {
                    descif+=cif.at(posic)-int(llave);
                }
                else
                {
                    descif+=cif[posic]^llave;
                }
            }
            if (cifrado.eof())
            {
                descifrado<<descif;
            }
            else
            {
                descifrado<<descif<<",";
            }
        }

    }
}
