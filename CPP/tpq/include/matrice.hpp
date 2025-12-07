#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <fstream>

template<class C>
class Matrice{

    private:
    int n;
    C** val;

    public:

    Matrice(int n);
    Matrice();
    void affiche();
    void init(C d);
    Matrice operator+(const Matrice&);
    Matrice& operator=(const Matrice& mat);
    Matrice operator*(const Matrice&);
    Matrice(const Matrice& mat);
    ~Matrice();
    C Determinant();
    Matrice<C> Pivot();
    void read(std::ifstream& fichiervecteur, int n);

};

#endif // MATRICE_HPP
