#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Matrice{

    private:
    int nbl;
    int nbc;
    double **val;

    public:
    Matrice(int nl, int nc);
    void affiche();
    void init(double d);
    
};
