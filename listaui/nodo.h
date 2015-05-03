#ifndef NODO_H
#define NODO_H
#include<string>

using namespace std;

class nodo
{
public:
    nodo();
    nodo(string dato);
    string dato;
    nodo *sig;
};

#endif // NODO_H
