#include <QCoreApplication>
#include<iostream>
#include<fstream>
#include<QDebug>

using namespace std;


class corredor
{
    public:
    char npp[4];
    char nombre[15],direcc[15],ciudad[10],nacionalidad[10],t_clasif[10];
    corredor()
    {
        for (int i = 0; i <15; ++i)
        {
            nombre[i]=direcc[i]=0;
        }
        for (int i = 0; i < 10; ++i)
        {
            ciudad[i]=nacionalidad[i]=t_clasif[10]=0;
        }
    }

    void setnom(string a)
    {
        for (int i = 0; i < 15; ++i)
        {
           nombre[i]=a[i];
        }
    }
    void setdir(string a)
    {
        for (int i = 0; i < 15; ++i)
        {
           direcc[i]=a[i];
        }
    }
    void setciu(string a)
    {
        for (int i = 0; i < 10; ++i)
        {
           ciudad[i]=a[i];
        }
    }
    void setnac(string a)
    {
        for (int i = 0; i < 10; ++i)
        {
           nacionalidad[i]=a[i];
        }
    }
    void sett_clas(string a)
    {
        for (int i = 0; i < 10; ++i)
        {
           t_clasif[i]=a[i];
        }
    }
};

void guardar(corredor run,string nom)
{
    fstream arch;

    int numreg=-1;
    arch.open(nom.c_str(),ios::out);


    cout<<numreg<<endl<<"*****";
    arch.close();

    if(numreg==-1)
    {
        arch.open(nom.c_str(),ios::in);

        arch<<0;

        arch.close();
    }
    else
    {
        numreg++;
        cout<<"num registros "<<numreg;
    }

    arch.open(nom.c_str(),ios::out);

    arch.write((char *)&run,sizeof(run));

    arch.close();
}


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    string filename;
    cout<<"archivo -> ";getline(cin,filename);

    corredor bitch;
    guardar(bitch,filename);

    while (1)
    {

        int opc=0;
        cout<<"que va a hacer     : "<<endl<<"1 - guardar\n2 - leer\n3 - cambiar archivo\n\t-> ";cin>>opc;

        switch (opc)
        {
        case 1:


            break;
        default:

            cout<<"invalido "<<endl;
            break;
        }
    }



return 1;
}

