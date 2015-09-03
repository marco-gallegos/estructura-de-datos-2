/*
214520198
marco antonio gallegos loaeza
Estructuras de datos 2 D09
Guerrero Segura1 Miguel Angel
*/


#include <iostream>

using namespace std;

string buscar(string recorridos, char actual, char final, string ruta);
int arreglo[8][8]={{1,1,1,1,0,0,0,0},
                   {1,0,0,0,0,0,0,0},
                   {1,0,0,1,0,1,0,0},
                   {1,0,1,0,0,0,0,0},
                   {0,0,0,0,0,0,1,0},
                   {0,0,1,0,0,0,0,0},
                   {0,0,0,0,1,0,0,0},
                   {0,0,0,0,0,0,0,0}};
int main()
{
    string a;
    char i,f;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cout<<arreglo[i][j]<< " ";
        }
        cout<<endl;
    }

    do{
        cout<<"Punto de inicio? [a - h] "<<endl;
        cin>>i;
        cout<<"Punto de destino? [a - h] "<<endl;
        cin>>f;
        string a=buscar("",i,f,"");

        if(a=="") cout<<"No existe ruta"<<endl;
        else cout<<"La ruta es "<<a<<endl;

        cout<<endl<<"Realizar otra busqueda?[y]"<<endl;
        cin>>i;

    }while(i=='y');


    }

string buscar(string recorridos, char actual, char final, string ruta)
{
    recorridos.push_back(actual);
    if(actual==final)
    {
        if(ruta=="" || ruta.length() > recorridos.length()) ruta=recorridos;
    }
    else
    {
        for(int x=0;x<8;x++)
            {
            if(arreglo[(int(actual)-97)][x]==1)
            {

                //cout<<"int(actual-97) = "<<int(actual-97)<<"   valor de actual = "<<actual<<endl;

                if(recorridos.find_first_of(char(x+97),0)==string::npos)
                {


                   // cout<<" char(x+97) = "<<char(x+97)<<endl;
                  //  cout<<"ruta = "<<ruta<<endl;


                    ruta=buscar(recorridos,char(x+97),final,ruta);
                }
            }
        }
    }
    return ruta;
}
