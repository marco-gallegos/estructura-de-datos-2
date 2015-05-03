#ifndef LIBRO_H
#define LIBRO_H

#include <cereal/types/string.hpp>
#include <cereal/access.hpp>



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

    template <class Archive>
    void save(Archive &ar)const
    {
        ar( titulo, autor, year, editorial );
    }

    template <class Archive>
    void load(Archive &ar)
    {
        ar( titulo, autor, year, editorial );
    }

    friend class cereal::access;
};

#endif // LIBRO_H
