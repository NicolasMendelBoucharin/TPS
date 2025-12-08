#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <fstream>
#include "vect.hpp"

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
    C DeterminantParPivot();
    Matrice<C> Pivot();
    void read(std::ifstream& fichiervecteur, int n);
    Vect<C> gauss(Vect<C>& B);
    Vect<C> solveLU(Vect<C>& B);
    Vect<C> produit_matrice_vecteur(Vect<C> B);
    C get(int i, int j) const;
    void set(int i, int j, C value);
    int size() const;
    Vect<C> descente_de_gradient(const Vect<C>& B, double tolerance);
};

#endif // MATRICE_HPP
