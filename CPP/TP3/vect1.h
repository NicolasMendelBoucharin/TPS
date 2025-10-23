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
    Vect(int n);
    trajet ajout(float delta);
};