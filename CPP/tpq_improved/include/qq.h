#ifndef QQ_H
#define QQ_H

#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
#include <string>

/**
 * @class qq
 * @brief Classe pour représenter des nombres rationnels (fractions)
 * 
 * Représente un nombre p/q où p est le numérateur et q le dénominateur.
 * Le dénominateur est toujours positif après reduction().
 */
class qq {
private:
    int numerator;      ///< Numérateur
    int denominator;    ///< Dénominateur (toujours > 0 après reduction)

    /**
     * @brief Calcule le PGCD de deux entiers
     * @param a Premier entier
     * @param b Deuxième entier
     * @return Le PGCD de a et b
     */
    int pgcd(int a, int b) const;

    /**
     * @brief Calcule le PPCM de deux entiers
     * @param n Premier entier
     * @param m Deuxième entier
     * @return Le PPCM de n et m
     */
    int ppcm(int n, int m) const;

public:
    /**
     * Constructeur par défaut : 0/1
     */
    qq();

    /**
     * Constructeur avec un entier : n/1
     * @param n Valeur entière
     */
    explicit qq(int n);

    /**
     * Constructeur principal : p/q
     * @param p Numérateur
     * @param q Dénominateur (doit être != 0)
     * @throws std::invalid_argument si q == 0
     */
    qq(int p, int q);

    /**
     * @brief Retourne true si le dénominateur est positif
     */
    bool signe() const;

    /**
     * @brief Corrige la fraction pour que le dénominateur soit positif
     */
    void signecorrect();

    /**
     * @brief Affiche la fraction au format p/q
     */
    void affiche() const;

    /**
     * @brief Réduit la fraction à sa forme irréductible
     */
    void reduction();

    // Opérateurs arithmétiques
    qq operator+(const qq& frac) const;
    qq operator-(const qq& frac) const;
    qq operator*(const qq& frac) const;
    qq operator/(const qq& frac) const;
    qq operator-() const;

    /**
     * @brief Opérateur += pour addition en place
     */
    qq& operator+=(const qq& frac);

    /**
     * @brief Opérateur puissance : calcule this^n
     * @param n L'exposant (peut être négatif)
     */
    qq pow(int n) const;

    // Opérateurs de comparaison
    bool operator>(const qq& frac) const;
    bool operator==(const qq& frac) const;
    bool operator<(const qq& frac) const;
    bool operator!=(const qq& frac) const;

    /**
     * @brief Retourne la valeur absolue
     */
    qq abs() const;

    /**
     * @brief Conversion en double
     */
    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }

    /**
     * @brief Addition avec un double
     */
    double operator+(const double& d) const;

    /**
     * @brief Multiplication avec un double
     */
    double operator*(const double& d) const;

    // Opérateurs de flux
    friend std::ostream& operator<<(std::ostream& flux, const qq& r);
    friend std::istream& operator>>(std::istream& flux, qq& r);
};

std::ostream& operator<<(std::ostream& flux, const qq& r);
std::istream& operator>>(std::istream& flux, qq& r);

/**
 * Surcharge de std::abs pour qq
 */
namespace std {
    inline qq abs(const qq& x) {
        return x.abs();
    }
}

#endif // QQ_H
