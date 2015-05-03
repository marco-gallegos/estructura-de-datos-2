#include "dispersion.h"

Dispersion::Dispersion()
{

}

Dispersion::~Dispersion()
{

}

int Dispersion::simple(string llave)
{
    int *ascci = new int[llave.length()];
    int acum = 0;

    for (int i = 0; i < llave.length(); i++ )
        ascci[i] = (int)llave.at(i);

    for (int i = 0; i < llave.length(); i++ )
         acum += ascci[i];

    return acum % 100;
}

