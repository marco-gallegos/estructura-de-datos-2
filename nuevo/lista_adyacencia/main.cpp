/*
214520198
marco antonio gallegos loaeza

diego gonzalez gonzalez

Estructuras de datos 2 D09
Guerrero Segura1 Miguel Angel
*/


#include <iostream>
#include<list>

using namespace std;

string buscar2(list<char> lst[],char actual,char destino,string ruta)
{
    if(actual==destino)
    {
        ruta.push_back(actual);
        return ruta;
    }
    ruta.push_back(actual);
    int tam=int(actual)-97;
    if(tam>=8)
        return"";
    if((lst[tam].empty()))
        return "";

    list<char>::iterator it = lst[tam].begin();
    while (it != lst[tam].end())
    {
        string actuales=buscar2(lst,*it,destino,ruta);
        if(actuales!="")
            return actuales;
        it++;
    }
    tam++;
    //return ruta;
    return "";
}


int main()
{
    list<char> ady_list[8];

    ady_list[0].push_back('b');
    ady_list[0].push_back('c');
    ady_list[0].push_back('d');

    ady_list[2].push_back('d');


    ady_list[4].push_back('g');


    //ady_list[].push_back('');

    list<char>::iterator a;
    list<char>::iterator b;
    list<char>::iterator c;
    list<char>::iterator d;
    list<char>::iterator f;
    list<char>::iterator g;

    string src;



    char x,y;
    cout<<"origen  : ";
    cin>>x;
    cout<<"destino : ";
    cin>>y;

    src = buscar2(ady_list,x,y,"") ;

    if(src=="")
        cout<<"no hay";
    else
        if(src == "a" || src.size() > 1)
            cout<<src;
        else
            cout<<"no hay";

    cout << "Hello World!" << endl;
    return 0;
}




