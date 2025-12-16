#include "vect.hpp"
#include <iostream>
#include <fstream>
#include "qq.h"

template class Vect<qq>;
template class Vect<double>;
template class Vect<int>;

using namespace std;

/**
 * Constructeur : crée un vecteur de taille n
 */
template<class C>
Vect<C>::Vect(int n) : lg(n), val(nullptr) {
    if (n > 0) {
        val = new C[n];
    }
}

/**
 * Constructeur par copie
 */
template<class C>
Vect<C>::Vect(const Vect& V) : lg(V.lg), val(nullptr) {
    if (lg > 0) {
        val = new C[lg];
        for (int i = 0; i < lg; i++) {
            val[i] = V.val[i];
        }
    }
}

/**
 * Opérateur d'affectation
 */
template<class C>
Vect<C>& Vect<C>::operator=(const Vect& V) {
    if (this == &V) return *this;  // Auto-affectation
    
    if (lg != V.lg) {
        delete[] val;
        lg = V.lg;
        val = (lg > 0) ? new C[lg] : nullptr;
    }
    
    for (int i = 0; i < lg; i++) {
        val[i] = V.val[i];
    }
    return *this;
}

/**
 * Destructeur
 */
template<class C>
Vect<C>::~Vect() {
    delete[] val;
}

/**
 * Initialise tous les éléments à d
 */
template<class C>
void Vect<C>::init(C d) {
    for (int i = 0; i < lg; i++) {
        val[i] = d;
    }
}

/**
 * Affiche le vecteur
 */
template<class C>
void Vect<C>::affiche() const {
    cout << "(";
    if (lg > 0) {
        cout << val[0];
        for (int i = 1; i < lg; i++) {
            cout << ", " << val[i];
        }
    }
    cout << ")" << endl;
}

/**
 * Modifie l'élément à l'indice i
 */
template<class C>
void Vect<C>::modif(int i, C r) {
    if (i < 0 || i >= lg) {
        throw std::out_of_range("Index hors limites");
    }
    val[i] = r;
}

/**
 * Opérateur addition
 */
template<class C>
Vect<C> Vect<C>::operator+(const Vect& U) const {
    if (lg != U.lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");
    }
    Vect W(lg);
    for (int i = 0; i < lg; i++) {
        W.val[i] = val[i] + U.val[i];
    }
    return W;
}

/**
 * Opérateur soustraction
 */
template<class C>
Vect<C> Vect<C>::operator-(const Vect& U) const {
    if (lg != U.lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");
    }
    Vect W(lg);
    for (int i = 0; i < lg; i++) {
        W.val[i] = val[i] - U.val[i];
    }
    return W;
}

/**
 * Addition en place : this += A + B
 */
template<class C>
void Vect<C>::add(const Vect& A, const Vect& B) {
    if (A.lg != B.lg || A.lg != lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");
    }
    for (int i = 0; i < lg; i++) {
        val[i] = A.val[i] + B.val[i];
    }
}

/**
 * Produit scalaire
 */
template<class C>
C Vect<C>::scal(const Vect& B) const {
    if (lg != B.lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");
    }
    C result = C(0);
    for (int i = 0; i < lg; i++) {
        result = result + val[i] * B.val[i];
    }
    return result;
}

/**
 * Lit le vecteur depuis un fichier
 */
template<class C>
void Vect<C>::read(std::ifstream& fichiermatrice, int n) {
    if (!fichiermatrice.is_open()) {
        throw std::runtime_error("Fichier non ouvert");
    }
    for (int i = 0; i < n; i++) {
        if (!(fichiermatrice >> val[i])) {
            throw std::runtime_error("Erreur lors de la lecture du vecteur");
        }
    }
}

/**
 * Getter pour l'élément i
 */
template<class C>
C Vect<C>::get(int i) const {
    if (i < 0 || i >= lg) {
        throw std::out_of_range("Index hors limites");
    }
    return val[i];
}

/**
 * Setter pour l'élément i
 */
template<class C>
void Vect<C>::set(int i, C value) {
    if (i < 0 || i >= lg) {
        throw std::out_of_range("Index hors limites");
    }
    val[i] = value;
}

/**
 * Retourne la taille du vecteur
 */
template<class C>
int Vect<C>::size() const {
    return lg;
}

/**
 * Produit externe avec un scalaire
 */
template<class C>
Vect<C> Vect<C>::produit_externe(C scalar) const {
    Vect<C> result(lg);
    for (int i = 0; i < lg; i++) {
        result.val[i] = val[i] * scalar;
    }
    return result;
}

/**
 * Calcule ||this - B||² (norme au carré de la différence)
 * CORRIGÉ : Retourne toujours double pour compatibilité
 */
template<class C>
double Vect<C>::difference_norme(const Vect<C>& B) const {
    if (lg != B.lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");
    }
    double sum = 0;
    for (int i = 0; i < lg; i++) {
        C diff = val[i] - B.val[i];
        sum += static_cast<double>(diff * diff);
    }
    return sum;
}
