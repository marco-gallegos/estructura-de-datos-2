//#include <QCoreApplication>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    //QCoreApplication a(argc, argv);

    multimap<string,string> secundario;//indice secundario

    //insertamos llave primaria y secundaria

    secundario.insert(pair<string, string>("jalisco","juan12") );

    secundario.insert(pair<string, string>("jalisco","alondra15") );

    secundario.insert(pair<string, string>("nayarit","jose10"));

    secundario.insert(pair<string, string>("df","antonio01"));


    //mostramos el indici secundario
    for(multimap<string,string>::iterator i=secundario.begin();
        i!=secundario.end();i++)
        cout<<(*i).first<<" -> "<<(*i).second<<endl;
    cout<<endl;

    //mostramos la llaves secundarias en un rango
    for(multimap<string,string>::iterator i= secundario.equal_range("jalisco").first;
        i!= secundario.equal_range("jalisco").second;i++)
        cout<<(*i).first<<" -> "<<(*i).second<<endl;

    return 0;
}
