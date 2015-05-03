#ifndef MANAGER_H
#define MANAGER_H
#include "libro.h"

#include <fstream>
#include <iostream>

using namespace std;

class Manager
{
public:
    Manager();

    void escribir(Libro libro);
    void mostrar();
};

#endif // MANAGER_H
