#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
#include <iostream>
#include <string>

/*
TODO : 
    faire un algo de gauss
    faire un algo de LU
    faire un algo par gradient maximisé ou jsp quoi
*/


//_______________________________________CLASSE QQ___________________________________________________
class qq{

    private:
    int numerator;
    int denominator;

    public:
    qq(int a, int b);
    qq();
    qq(int n);
    bool signe();
    void signecorrect();
    void affiche();
    int pgcd(int a, int b);
    void reduction();
    int ppcm(int a, int b);
    qq operator+(const qq& frac);
    double operator+(const double& d);
    double operator*(const double& d);
    qq operator*(const qq& frac);
    qq operator/(const qq& frac);
    qq operator-(const qq& frac);
    qq operator-() const;
    qq& operator&=(const qq &frac);
    operator double() const{return (double) numerator/denominator;}
    qq& operator+=(const qq& frac);
    qq pow(int n);
    friend std::ostream& operator<<(std::ostream &flux, const qq &r);
    friend std::istream& operator>>(std::istream& flux, qq& r);
    
};

std::ostream& operator<<(std::ostream &flux, const qq &r);
std::istream& operator>>(std::istream& flux, qq& r);


//__________________________________________CLASSE VECT_______________________________________________


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
    void scal(const Vect& A, const Vect& B);
    ~Vect();
    void read(std::ifstream& fichiermatrice, int n);
};


//_________________________________________CLASSE MATRICE_____________________________________________________


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


//___________________________________CLASSE_DONNEE__________________________________________

class datas{
    private:
    int corps;
    int taille;
    int algo;
    double tolerance;
    public:
    int getCorps();
    int getTaille();
    int getAlgo();
    double getTolerance();
    void read(std::ifstream& fichierdatas);

};



