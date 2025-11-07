#include<iostream>
#include<cassert>
#include<cmath>


class qq{
    private:
    int numerator;
    int denominator;
    bool positive;
    public:
    qq(int a, int b);
    qq();
    bool signe();
    void signecorrect();
    void affiche();
    int pgcd(int a, int b);
    void reduction();
    int ppcm(int a, int b);
    qq operator+(const qq& frac);
    qq operator*(const qq& frac);
    qq operator/(const qq& frac);
    qq operator-(const qq& frac);
    operator double() const{return (double) numerator/denominator;}
    qq& operator&=(const qq& frac);
    qq pow(int n);
};

template<class C>
class Vect{

    private:
    int lg;
    C* val;

    public:
    void init(C d);
    void affiche();
    void modif(int i, C r);
    explicit Vect(int n=0);
    Vect(const Vect&);
    Vect& operator=(const Vect&);
    Vect operator+(const Vect& U);
    void add(const Vect& A, const Vect& B);
    ~Vect();
};

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
    Matrice(const Matrice& mat);
    ~Matrice();
};
