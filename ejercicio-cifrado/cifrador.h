#ifndef CIFRADOR_H
#define CIFRADOR_H
#include<iostream>
#include<fstream>
using namespace std;
class cifrador
{
public:
    cifrador();
    void cifrar(char llave);
    void descifrar(char llave);
    void mostrarcifrado();
    void mostraroriginal();
};

#endif // CIFRADOR_H
