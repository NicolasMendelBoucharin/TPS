#ifndef QQ_H
#define QQ_H

#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
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

#endif // QQ_H
