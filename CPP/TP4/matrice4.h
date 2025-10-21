#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
#include <iostream>
#include <string>



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
    Matrice operator+(const Matrice&);
    Matrice& operator=(const Matrice& mat);
    Matrice(const Matrice& mat);
    ~Matrice();
    void read(std::ifstream& fichierentree);
    void write(std::ofstream& fichiersorite);
};
