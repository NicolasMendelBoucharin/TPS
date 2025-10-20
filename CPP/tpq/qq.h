#include<iostream>
#include<cassert>
#include<cmath>
//throw

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
    double converttodouble();
    qq& operator&=(const qq& frac);
    qq pow(int n);
};