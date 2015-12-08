#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <windows.h>
#define archivoFisico "maraton.txt"
using namespace std;
struct datos{
    long numeroParticipante;
    char nombreAtleta[50];
    char direccionAtleta[50];
    char ciudadAtleta[50];
    char nacionalidadAtleta[50];
    char tiempoClasificacion[50];
};

class maraton{
    private:
        struct datos participantes;
        int contadorRegistros;
    public:
        void altaRegistro(long);
        void mostrarRegistro();
        void escribirRegistro(int &contadorRegistros);
        void leerRegistro(int);
        void leerContador();
        void crearArchivo();
        bool verificarCodigo(long);
};
bool maraton::verificarCodigo(long numeroParticipante){
    ifstream leer(archivoFisico, ios::binary);
    if(!leer.good()){
        cerr<<"\n\n no se pudo leer el archivo. \n\n";
    }else{
        int pos=4;
        while(!leer.eof()){
            leer.seekg(pos, ios::beg);
            if(leer.eof())break;
            leer.read((char *)&participantes, 100);
            if(numeroParticipante==participantes.numeroParticipante){
                return true;
            }
            pos+=100;
        }
        leer.close();
        return false;
    }
}
void maraton::mostrarRegistro(){
    cout<<"\n\n";
    cout<<"numero del participante: "<<participantes.numeroParticipante<<endl;
    cout<<"nombre del atleta:       "<<participantes.nombreAtleta<<endl;
    cout<<"direccion del atleta:    "<<participantes.direccionAtleta<<endl;
    cout<<"ciudad:                  "<<participantes.ciudadAtleta<<endl;
    cout<<"nacionalidad:            "<<participantes.nacionalidadAtleta<<endl;
    cout<<"tiempo de clasificacion: "<<participantes.tiempoClasificacion<<endl<<endl;
    cout<<"\n\n";
}
void maraton::altaRegistro(long numeroParticipante){
    cout<<"numero del participante:   ";
    participantes.numeroParticipante=numeroParticipante;
    cout<<participantes.numeroParticipante;
    cout<<"\nnombre del atleta:         ";
    cin.ignore();
    cin.getline(participantes.nombreAtleta,50);
    cout<<"direccion del atleta:      ";
    cin.getline(participantes.direccionAtleta,50);
    cout<<"ciudad:                    ";
    cin.getline(participantes.ciudadAtleta,50);
    cout<<"nacionalidad:              ";
    cin.getline(participantes.nacionalidadAtleta,50);
    cout<<"tiempo de clasificacion:   ";
    cin.getline(participantes.tiempoClasificacion,50);
    cout<<"\n\n";
    escribirRegistro(contadorRegistros);
}
void maraton::escribirRegistro(int &contadorRegistros){
    ifstream leerContador(archivoFisico,ios::in|ios::out|ios::binary);
    leerContador.seekg(0, ios::beg);
    leerContador.read((char *)&contadorRegistros, sizeof(int));
    leerContador.close();
    ofstream escribe(archivoFisico,ios::app|ios::in|ios::out|ios::binary);
    escribe.seekp((contadorRegistros*100)+sizeof(int), ios::beg);
    int pos=(contadorRegistros*100)+sizeof(int);
    escribe.write((char *)&participantes,100);
    escribe.close();
    contadorRegistros++;
    ofstream escribeContador(archivoFisico,ios::in|ios::out|ios::binary);
    escribeContador.seekp(0,ios::beg);
    escribeContador.write((char*)&contadorRegistros,sizeof(int));
    escribeContador.close();
}
void maraton::leerContador(){
    ifstream leer(archivoFisico, ios::in|ios::out|ios::binary);
    leer.read((char *)&contadorRegistros, sizeof(int));
    leer.close();
}
void maraton::crearArchivo(){
    ifstream leerContador(archivoFisico);
    ofstream escribirContador(archivoFisico, ios::in | ios::out | ios::binary | ios::app);
    if(!leerContador.good()){
        int contador=0;
        escribirContador.seekp(0,ios::beg);
        escribirContador.write((char *)&contador,sizeof(int));
    }
    escribirContador.close();
}
void maraton::leerRegistro(int NRR){
    if(/*NRR <= contadorRegistros-1 && */NRR >= 0){
        ifstream leer(archivoFisico, ios::binary);
        leer.seekg(NRR*sizeof(struct datos)+sizeof(int),ios::beg);
        int pos=NRR+sizeof(int);
        leer.read((char *)&participantes, 100);
        mostrarRegistro();
        char respuesta[20];
        cout<<"\n\n desea modificar el registro responda s/n ";
        cin.ignore();
        cin.getline(respuesta,20);
        if(respuesta[0]=='s'){
            long numeroParticipante;
            cout<<"\n\n ingresa el numero del atleta";
            cin>>numeroParticipante;
            if(verificarCodigo(numeroParticipante)){
                cerr<<"\n\n codigo ya existe. \n\n";
            }else{
                cout<<"\n\n";
                cout<<"\n numero de participante:       ";
                participantes.numeroParticipante=numeroParticipante;
                cout<<participantes.numeroParticipante;
                cout<<"\n ingresa el nombre del atleta: ";
                cin.ignore();
                cin.getline(participantes.nombreAtleta,50);
                cout<<"\ndireccion del atleta:          ";
                cin.getline(participantes.direccionAtleta,50);
                cout<<"\nciudad:                        ";
                cin.getline(participantes.ciudadAtleta,50);
                cout<<"\nnacionalidad:                  ";
                cin.getline(participantes.nacionalidadAtleta,50);
                cout<<"\ntiempo de clasificacion:       ";
                cin.getline(participantes.tiempoClasificacion,50);
                cout<<"\n\n";
                ofstream escribe(archivoFisico, ios::in|ios::out|ios::binary);
                escribe.seekp((NRR*100)+sizeof(int),ios::beg);
                escribe.write((char *)&participantes, 100);
                mostrarRegistro();
            }
        }//fin de if s
    }else{
        cerr<<"\n\n no sabes programar:";
    }
}
main()
{
    short opcion=0;
    //Creamos el objeto
    maraton Obj;
    Obj.crearArchivo();
    Obj.leerContador();
    do
    {
        cout<<" =================================================="<<endl;
        cout<<"                 maraton"<<endl;
        cout<<" =================================================="<<endl<<endl;
        cout<<"     1.- Alta"<<endl
            <<"     2.- Consulta por NRR."<<endl
            <<"     3.- Salir."<<endl
            <<"     opccion>> ";
        cin>>opcion;
        switch(opcion)
        {
            case 1:
                system ("cls");
                long codigo;
                cout<<"                 maraton captura"<<endl;
                cout<<" =================================================="<<endl<<endl;
                cout<<"\n\n     Ingresa el c\242digo del participante:       ";
                cin>>codigo;
                if(Obj.verificarCodigo(codigo))
                {
                    cerr<<"\n\n     C\242digo ya existe.\n\n";
                }
                else
                {
                    Obj.altaRegistro(codigo);
                }
                break;
            case 2:
                system ("cls");
                int NRR;
                cout<<"               maraton consultas NRR"<<endl;
                cout<<" =================================================="<<endl<<endl;
                cout<<"Ingresa el NRR del registro: ";
                cin>>NRR;
                Obj.leerRegistro(NRR);
                break;
            case 3:
                break;
            default:
                {
                system ("cls");
                cout<<"\n\n     jajajaja te equivocaste\n\n";
                }//Fin del default
        }//Fin del switch
    }while(opcion!=3);
    return 0;
}
