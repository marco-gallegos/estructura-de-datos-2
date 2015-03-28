#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <fstream>
using namespace std;

class Libro
{
public:
    Libro();
    ~Libro();

    string getTitulo() const;
    void setTitulo(const string &value);

    string getAutor() const;
    void setAutor(const string &value);

    string getYear() const;
    void setYear(const string &value);

    string getEditorial() const;
    void setEditorial(const string &value);

private:
    string titulo;
    string autor;
    string year;
    string editorial;

    friend ofstream& operator <<(ofstream& of, Libro &l)
    {
        of << l.getTitulo() << "|"
           << l.getAutor()  << "|"
           << l.getYear()   << "|"
           << l.getEditorial()  << "|" << endl;

        return of;
    }

    friend ifstream& operator >>(ifstream& ifs, Libro &l)
    {
        string temp;

        getline( ifs, temp, '|');
        l.setTitulo(temp);

        getline( ifs, temp, '|');
        l.setAutor(temp);

        getline( ifs, temp, '|');
        l.setYear(temp);

        getline( ifs, temp);
        l.setEditorial(temp);

        return ifs;
    }

    friend ostream& operator <<(ostream& os, Libro &l)
    {
        os << "Titulo:    " << l.getTitulo() << endl
           << "Autor:     " << l.getAutor()  << endl
           << "Año:       " << l.getYear()   << endl
           << "Editorial: " << l.getEditorial() << endl << endl;

        return os;
    }

    friend istream& operator >>(istream& is, Libro &l)
    {
        string temp;

        cout << "Titulo: ";
        getline( is, temp );
        l.setTitulo(temp);

        cout << "Autor:  ";
        getline( is, temp );
        l.setAutor(temp);

        cout << "Año:    ";
        getline( is, temp );
        l.setYear(temp);

        cout << "Editorial: ";
        getline( is, temp );
        l.setEditorial(temp);

        return is;
    }
};

#endif // LIBRO_H
