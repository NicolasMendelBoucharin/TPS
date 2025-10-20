#include "qq.h"
using namespace std;

/*
Constructeur par défaut d'un rationnel
*/
qq::qq(){
    numerator=0;
    denominator=1;
}

/*
Entrée : p et q
Retour: p/q
*/
qq::qq(int p, int q){
    numerator = p;
    denominator =q;
};

/*
renvoie true ssi q>0
*/
bool qq::signe(){
    return (denominator>0);
};

/*
Corrige la fraction pour que q>0
*/
void qq::signecorrect(){
    if (not this->signe()){
        this->numerator=-this->numerator;
        this->denominator=-this->denominator;
    }
};

/*
Affiche la fraction
*/
void qq::affiche(){
    cout<<numerator<<"/"<<denominator<<endl;
};

/*
Entrée : a et b
Sortie : pgcd de a et b
*/
int qq::pgcd(int a, int b){
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
};

/*
Donne la fraction réduite avec le dénominateur positif (unique)
*/
void qq::reduction(){
    this->signecorrect();
    int d=pgcd(numerator, denominator);
    numerator = numerator/d;
    denominator = denominator/d;
};

/*
Entrée: n et m
Sortie: ppcm de n et m
*/
int qq::ppcm(int n, int m){
    return n*m/pgcd(n, m);
};

/*
Surchage du *
*/
qq qq::operator*(const qq& frac){
    qq prod =qq((this->numerator)*frac.numerator, (this->denominator)*frac.denominator);
    prod.reduction();
    return prod;
};

/*
Surcharche du +
*/
qq qq::operator+(const qq& frac){
    int newDenominator = ppcm(denominator, frac.denominator);
    qq somme = qq(numerator*newDenominator/denominator + frac.numerator*newDenominator/frac.denominator, newDenominator);
    somme.reduction();
    return somme;
}

/*
Surcharge du /
*/
qq qq::operator/(const qq& frac){
    qq prod =qq((this->numerator)*frac.denominator, (this->denominator)*frac.numerator);
    prod.reduction();
    return prod;
};

/*
Surcharge du -
*/
qq qq::operator-(const qq& frac){
    int newDenominator = ppcm(denominator, frac.denominator);
    qq somme = qq(numerator*newDenominator/denominator - frac.numerator*newDenominator/frac.denominator, newDenominator);
    somme.reduction();
    return somme;
};



/*
Operateur d'affectation
*/
qq& qq::operator&=(const qq& frac){
    numerator = frac.numerator;
    denominator = frac.denominator;
    return *this;
};

/*
Opérateur de puissance
*/
qq qq::pow(const int n){;
    qq power;  
    if(n<0){
        power = qq( std::pow(this->denominator,(-n)), std::pow(this->numerator,(-n)));
        
    }
    else{
        power = qq(std::pow(this->numerator, n), std::pow(this->denominator, n));
    };
    power.reduction();
    return power;

}

