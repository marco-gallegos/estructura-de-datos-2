#ifndef EEPROM_H
#define EEPROM_H
#include<iostream>
#include<fstream>

using namespace std;

class eeprom
{
   string temp;
public:
    eeprom();
    void guardar(string s);
    void buscar(string s);
};

#endif // EEPROM_H
