#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;


class Vect{

    private:
    int lg;
    double* val;

    public:
    void init(double d);
    void affiche();
    void modif(int i, double r);
    Vect(int n=0);
    Vect(const Vect&);
    Vect& operator=(const Vect&);
    friend int getlg(const Vect& U);
};

int getlg(const Vect& U);