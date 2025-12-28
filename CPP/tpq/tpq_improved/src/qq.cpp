#include "qq.h"
#include <cmath>
using namespace std;

/**
 * Constructeur par défaut : 0/1
 */
qq::qq() : numerator(0), denominator(1) {}

/**
 * Constructeur avec un entier : n/1
 */
qq::qq(int n) : numerator(n), denominator(1) {}

/**
 * Constructeur principal : p/q
 */
qq::qq(int p, int q) {
    if (q == 0) throw std::invalid_argument("Dénominateur nul");
    numerator = p;
    denominator = q;
}

/**
 * @brief Retourne true si denominator > 0
 */
bool qq::signe() const {
    return (denominator > 0);
}

/**
 * @brief Corrige pour que denominator > 0
 */
void qq::signecorrect() {
    if (!this->signe()) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

/**
 * @brief Affiche p/q
 */
void qq::affiche() const {
    cout << numerator << "/" << denominator << endl;
}

/**
 * @brief Calcule le PGCD de a et b
 */
int qq::pgcd(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/**
 * @brief Réduit la fraction à sa forme irréductible
 */
void qq::reduction() {
    this->signecorrect();
    int d = pgcd(numerator, denominator);
    if (d != 0) {
        numerator = numerator / d;
        denominator = denominator / d;
    }
}

/**
 * @brief Calcule le PPCM de n et m
 */
int qq::ppcm(int n, int m) const {
    int g = pgcd(n, m);
    if (g == 0) return 0;
    return (n / g) * m;  // Ordre pour éviter overflow
}

/**
 * Surcharge du +
 */
qq qq::operator+(const qq& frac) const {
    int newDenominator = ppcm(denominator, frac.denominator);
    qq somme = qq(numerator * newDenominator / denominator + 
                  frac.numerator * newDenominator / frac.denominator, 
                  newDenominator);
    somme.reduction();
    return somme;
}

/**
 * Surcharge du -
 */
qq qq::operator-(const qq& frac) const {
    int newDenominator = ppcm(denominator, frac.denominator);
    qq diff = qq(numerator * newDenominator / denominator - 
                 frac.numerator * newDenominator / frac.denominator, 
                 newDenominator);
    diff.reduction();
    return diff;
}

/**
 * Surcharge du *
 */
qq qq::operator*(const qq& frac) const {
    qq prod = qq((this->numerator) * frac.numerator, 
                 (this->denominator) * frac.denominator);
    prod.reduction();
    return prod;
}

/**
 * Surcharge du /
 */
qq qq::operator/(const qq& frac) const {
    if (frac.numerator == 0) throw std::invalid_argument("Division par zéro");
    qq prod = qq((this->numerator) * frac.denominator, 
                 (this->denominator) * frac.numerator);
    prod.reduction();
    return prod;
}

/**
 * Surcharge du - unaire
 */
qq qq::operator-() const {
    return qq(-numerator, denominator);
}

/**
 * Surcharge du +=
 */
qq& qq::operator+=(const qq& frac) {
    int newDenominator = ppcm(denominator, frac.denominator);
    int newNumerator = numerator * newDenominator / denominator + 
                       frac.numerator * newDenominator / frac.denominator;
    numerator = newNumerator;
    denominator = newDenominator;
    reduction();
    return *this;
}

/**
 * @brief Calcule this^n (positif ou négatif)
 * CORRIGÉ : Utilise une boucle au lieu de std::pow
 */
qq qq::pow(int n) const {
    if (n == 0) {
        return qq(1, 1);
    }
    
    qq result(1, 1);
    qq base = *this;
    
    int absN = std::abs(n);
    for (int i = 0; i < absN; ++i) {
        result = result * base;
    }
    
    if (n < 0) {
        return qq(result.denominator, result.numerator);
    }
    return result;
}

/**
 * Surcharge du << pour l'affichage
 */
ostream& operator<<(ostream& flux, const qq& r) {
    flux << r.numerator << "/" << r.denominator;
    return flux;
}

/**
 * Surcharge du >> pour la lecture
 */
std::istream& operator>>(std::istream& flux, qq& r) {
    int num, den;
    flux >> num >> den;
    r = qq(num, den);
    return flux;
}

/**
 * Addition avec un double
 */
double qq::operator+(const double& d) const {
    return d + static_cast<double>(numerator) / denominator;
}

/**
 * Multiplication avec un double
 */
double qq::operator*(const double& d) const {
    return d * static_cast<double>(numerator) / denominator;
}

/**
 * Opérateur > pour qq
 */
bool qq::operator>(const qq& frac) const {
    // a/b > c/d  ⟺  a*d > c*b
    return numerator * frac.denominator > frac.numerator * denominator;
}

/**
 * Opérateur == pour qq
 */
bool qq::operator==(const qq& frac) const {
    // a/b == c/d  ⟺  a*d == c*b
    return numerator * frac.denominator == frac.numerator * denominator;
}

/**
 * Opérateur < pour qq
 */
bool qq::operator<(const qq& frac) const {
    // a/b < c/d  ⟺  a*d < c*b
    return numerator * frac.denominator < frac.numerator * denominator;
}

/**
 * Opérateur != pour qq
 */
bool qq::operator!=(const qq& frac) const {
    return !(*this == frac);
}

/**
 * @brief Retourne la valeur absolue
 */
qq qq::abs() const {
    if (numerator < 0) {
        return qq(-numerator, denominator);
    }
    return qq(numerator, denominator);
}
