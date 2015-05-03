#include <iostream>
#include "libro.h"
#include <fstream>
using namespace std;

int main()
{
    Libro libro;

  /*  libro.setTitulo("Programacion");
    libro.setAutor("Joyanes");
    libro.setYear("2010");
    libro.setEditorial("Alfaomega");
*/
 //   cin >> libro;
 //   ofstream archivo("/Users/michel/ser.txt");
    ifstream archivo("/Users/michel/ser.txt");
    archivo >> libro;
    archivo.close();

    cout << libro;

    return 0;
}

