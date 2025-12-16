#include <iterator>
#include<cassert>
#include<cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

template<class C>
class Vec : public std::vector<C>{
    public:
        void init(C d);
        void affiche();
        void modif(int i, C r);
        Vec(int n) : std::vector<C>(n){}
        Vec operator+(const Vec& U);

};

enum methode{
    rectangles, trapezes
};

class Integ{
    private :
        methode met;
        double computerec(double a, double b, int nbsub, double (*f) (double));
        double computetrap(double a, double b, int nbsub, double (*f) (double));

    public:
        Integ(methode);
        double compute(double a, double b, int nbsub, double (*f)(double));
    
};

double puissance4(double x);