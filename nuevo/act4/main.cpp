#include <QCoreApplication>
#include<fstream>
#include<pelicula.h>
#include<iostream>

using namespace std;

/*
214520198
marco antonio gallegos loaeza

diego gonzalez gonzalez

Estructuras de datos 2 D09
Guerrero Segura Miguel Angel
*/



void guardar_cmp(string nom, pelicula peli);
void mostrar_cmp(string nom);




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    pelicula aux;
    string x;
    string s;
    cout<<"que archivo sera utilizado    ->   ";getline(cin,s);
    while(1)
    {
        int opc;
        cout<<endl;
        cout<<"1 guardar \n2 ver\nopc -> ";cin>>opc;cin.ignore();
        cout<<endl;

        switch (opc) {
        case 1:

            cout<<"nombre         -> ";
            getline(cin,x);
            aux.setName(x);
            cout<<"protagonistas  -> ";
            getline(cin,x);
            aux.setProtagonistas(x);
            cout<<"director       -> ";
            getline(cin,x);
            aux.setDirector(x);
            cout<<"estudio        -> ";
            getline(cin,x);
            aux.setEstudio(x);
            cout<<"genero         -> ";
            getline(cin,x);
            aux.setGenero(x);
            cout<<"año            -> ";
            getline(cin,x);
            aux.setAnio_estre(x);
            cout<<"premios        -> ";
            getline(cin,x);
            aux.setPremios(x);
            cout<<"calificacion   -> ";
            getline(cin,x);
            aux.setCalif(x);
            //cout<<"archivo   ";cin>>s;cin.ignore();
            guardar_cmp(s,aux);


            break;

        case 2:
            //cout<<"archivo ";getline(cin,s);
            mostrar_cmp(s);

            break;
        default:
            break;
        }


    }


    return a.exec();
}




void guardar_cmp(string nom, pelicula peli)
{
    fstream arch(nom.c_str(),ios::out|ios::app);
    if(!arch.is_open())
    {
        cout<<"no se puede crear archivo";
        return;
    }
    //string regis= peli.getName()+"|"+peli.getProtagonistas()+"|"+peli.getDirector()+"|"+peli.getEstudio()+"|"+peli.getGenero()+"|"+peli.getAnio_estre()+"|"+peli.getPremios()+"|"+peli.getCalif();
    int tam=peli.getName().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getName().c_str(),tam);

    tam=peli.getProtagonistas().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getProtagonistas().c_str(),tam);

    tam=peli.getDirector().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getDirector().c_str(),tam);

    tam=peli.getEstudio().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getEstudio().c_str(),tam);

    tam=peli.getGenero().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getGenero().c_str(),tam);

    tam=peli.getAnio_estre().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getAnio_estre().c_str(),tam);

    tam=peli.getPremios().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getPremios().c_str(),tam);

    tam=peli.getCalif().length();
    arch.write((char *)&tam,sizeof(tam));
    arch.write(peli.getCalif().c_str(),tam);

    arch.close();
}

void mostrar_cmp(string nom)
{
    fstream arch(nom.c_str(),ios::in);
    if(!arch.is_open())
    {
        cout<<"no se puede abrir archivo";
        return;
    }
    int tam;

    while (!arch.eof())
    {
        arch.read((char *)&tam,sizeof(tam));
        if(arch.eof())  break;

        char * prot,*dire,*est,*gen,*anio,*prem,*calif;

        char * nom=new char[tam+1];
        arch.read(nom,tam);
        nom[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        prot=new char[tam+1];
        arch.read(prot,tam);
        prot[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        dire=new char[tam+1];
        arch.read(dire,tam);
        dire[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        est=new char[tam+1];
        arch.read(est,tam);
        est[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        gen=new char[tam+1];
        arch.read(gen,tam);
        gen[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        anio=new char[tam+1];
        arch.read(anio,tam);
        anio[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        prem=new char[tam+1];
        arch.read(prem,tam);
        prem[tam]='\0';

        arch.read((char *)&tam,sizeof(tam));
        calif=new char[tam+1];
        arch.read(calif,tam);
        calif[tam]='\0';

        cout<<"nombre             :   "<<nom<<endl;
        cout<<"protagonistas      :   "<<prot<<endl;
        cout<<"director           :   "<<dire<<endl;
        cout<<"estudio            :   "<<est<<endl;
        cout<<"genero             :   "<<gen<<endl;
        cout<<"año de estreno     :   "<<anio<<endl;
        cout<<"premios            :   "<<prem<<endl;
        cout<<"calificacion       :   "<<calif<<endl;


        delete nom;
        delete prot;
        delete dire;
        delete est;
        delete gen;
        delete anio;
        delete prem;
        delete calif;
    }
    arch.close();
}
