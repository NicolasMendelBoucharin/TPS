#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

/**
 * @class Vect
 * @brief Classe template pour représenter un vecteur dynamique
 * 
 * Gère dynamiquement un tableau de taille variable du type C.
 */
template<class C>
class Vect {
private:
    int lg;     ///< Longueur du vecteur
    C* val;     ///< Tableau de valeurs

public:
    /**
     * @brief Constructeur avec taille
     * @param n Taille du vecteur (défaut : 0)
     */
    explicit Vect(int n = 0);

    /**
     * @brief Constructeur par copie
     */
    Vect(const Vect& V);

    /**
     * @brief Opérateur d'affectation
     */
    Vect& operator=(const Vect& V);

    /**
     * @brief Destructeur
     */
    ~Vect();

    /**
     * @brief Initialise tous les éléments à la valeur d
     */
    void init(C d);

    /**
     * @brief Affiche le vecteur au format (x1, x2, ..., xn)
     */
    void affiche() const;

    /**
     * @brief Modifie l'élément à l'indice i
     */
    void modif(int i, C r);

    /**
     * @brief Opérateur addition
     */
    Vect operator+(const Vect& U) const;

    /**
     * @brief Opérateur soustraction
     */
    Vect operator-(const Vect& U) const;

    /**
     * @brief Addition en place : this += A + B
     */
    void add(const Vect& A, const Vect& B);

    /**
     * @brief Produit scalaire avec un autre vecteur
     */
    C scal(const Vect& B) const;

    /**
     * @brief Lit le vecteur depuis un fichier
     */
    void read(std::ifstream& fichiermatrice, int n);

    /**
     * @brief Getter pour l'élément à l'indice i
     */
    C get(int i) const;

    /**
     * @brief Setter pour l'élément à l'indice i
     */
    void set(int i, C value);

    /**
     * @brief Retourne la taille du vecteur
     */
    int size() const;

    /**
     * @brief Produit externe avec un scalaire : this * scalar
     */
    Vect produit_externe(C scalar) const;

    /**
     * @brief Calcule ||this - B||²
     * @return La norme au carré de la différence
     * @throws std::invalid_argument si les tailles diffèrent
     */
    double difference_norme(const Vect<C>& B) const;
};

#endif // VECT_HPP
