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
    explicit Vect(int n=0);
    Vect(const Vect&);
    Vect& operator=(const Vect&);
    friend int getlg(const Vect& U);
    Vect operator+(const Vect& U);
    void add(const Vect& A, const Vect& B);
    ~Vect();
};
//julien.mathiaud@univ-rennes.frcl


int getlg(const Vect& U);
template <class K>
K prod(K a, K b){return a*b;}

//attention il faut mettre le type qui accepte le plus de truc à gauche
template <class L, class I>
L prodBis(L a, I b){return a*b;}

