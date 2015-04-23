#include <iostream>

using namespace std;

string cifracesar(string texto)
{
    string cifrado;
    for(unsigned int i=0;i<texto.length();i++)
    {
        cifrado += texto.at(i)+3;
    }
    return cifrado;
}

string descifracesar(string texto)
{
    string descifrado;
    for(unsigned int i=0;i<texto.length();i++)
    {
        descifrado += texto.at(i)-3;
    }
    return descifrado;
}

string cifradoXOR(string texto, char llave)
{
    string cifrado;
    for(unsigned int i=0;i<texto.length();i++)
    {
        cifrado += texto[i] ^ llave;
    }
    return cifrado;
}

string descifradoXOR(string texto, char llave)
{
    string descifrado;
    for(unsigned int i=0;i<texto.length();i++)
    {
        descifrado += texto[i] ^ llave;
    }
    return descifrado;
}


int main()
{
    cout<<"texto cifrado    : "<<cifracesar("michel")<<endl;
    cout<<"texto descifrado :  "<<descifracesar( cifracesar("michel"))<<endl;
    cout<<endl;
    cout<<"cifrado XOR      : "<<cifradoXOR("michel",'@')<<endl;
    cout<<"descifrado XOR   : "<<descifradoXOR(cifradoXOR("michel",'@'),'@')<<endl;
    return 0;
}

