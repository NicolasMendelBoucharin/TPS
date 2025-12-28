#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "vect.hpp"

/**
 * @class Matrice
 * @brief Classe template pour représenter une matrice carrée
 * 
 * Gère dynamiquement une matrice n×n du type C.
 */
template<class C>
class Matrice {
private:
    int n;      ///< Taille de la matrice (n×n)
    C** val;    ///< Tableau 2D des valeurs

public:
    /**
     * @brief Constructeur : crée une matrice n×n non initialisée
     */
    explicit Matrice(int n);

    /**
     * @brief Constructeur par défaut : matrice 1×1
     */
    Matrice();

    /**
     * @brief Constructeur par copie
     */
    Matrice(const Matrice& mat);

    /**
     * @brief Opérateur d'affectation
     */
    Matrice& operator=(const Matrice& mat);

    /**
     * @brief Destructeur
     */
    ~Matrice();

    /**
     * @brief Initialise tous les éléments à d
     */
    void init(C d);

    /**
     * @brief Affiche la matrice
     */
    void affiche() const;

    /**
     * @brief Opérateur addition
     */
    Matrice operator+(const Matrice& A) const;

    /**
     * @brief Opérateur multiplication matricielle
     */
    Matrice operator*(const Matrice& A) const;

    /**
     * @brief Calcule le déterminant par développement de Laplace
     */
    C Determinant() const;

    /**
     * @brief Calcule le déterminant par élimination de Gauss (plus rapide)
     */
    C DeterminantParPivot();

    /**
     * @brief Effectue une élimination de Gauss sur une copie
     * @return La matrice après élimination
     */
    Matrice<C> Pivot();

    /**
     * @brief Lit la matrice depuis un fichier
     */
    void read(std::ifstream& fichiervecteur, int n);

    /**
     * @brief Résout AX = B par élimination de Gauss avec pivot partiel
     * @param B Vecteur B
     * @return Vecteur solution X
     */
    Vect<C> gauss(Vect<C>& B);

    /**
     * @brief Résout AX = B par décomposition LU avec pivot partiel
     * @param B Vecteur B
     * @return Vecteur solution X
     */
    Vect<C> solveLU(Vect<C>& B);

    /**
     * @brief Résout AX = B par descente de gradient
     * @param B Vecteur B
     * @param tolerance Critère d'arrêt (norme du résidu)
     * @return Vecteur solution X (approchée)
     */
    Vect<C> descente_de_gradient(const Vect<C>& B, double tolerance);

    /**
     * @brief Calcule le produit matrice-vecteur : this * B
     */
    Vect<C> produit_matrice_vecteur(const Vect<C>& B) const;

    /**
     * @brief Getter pour l'élément (i,j)
     */
    C get(int i, int j) const;

    /**
     * @brief Setter pour l'élément (i,j)
     */
    void set(int i, int j, C value);

    /**
     * @brief Retourne la taille de la matrice
     */
    int size() const;
};

#endif // MATRICE_HPP
