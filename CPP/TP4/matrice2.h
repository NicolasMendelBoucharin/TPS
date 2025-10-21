#include<iostream>
#include<cassert>
#include<cmath>


class Matrice{

    private:
    int nbl;
    int nbc;
    double **val;

    public:
    Matrice(int nl, int nc);
    Matrice();
    void affiche();
    void init(double d);
    Matrice operator+(Matrice&);
    Matrice& operator=(const Matrice& mat);
    Matrice(const Matrice& mat);
    ~Matrice();
};
