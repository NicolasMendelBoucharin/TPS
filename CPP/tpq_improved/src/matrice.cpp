#include "matrice.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include "qq.h"

template class Matrice<double>;
template class Matrice<qq>;

using namespace std;

/**
 * Constructeur : crée une matrice n×n
 */
template<class C>
Matrice<C>::Matrice(int nl) : n(nl), val(nullptr) {
    if (n <= 0) {
        throw std::invalid_argument("La taille de la matrice doit être positive");
    }
    val = new C*[n];
    for (int i = 0; i < n; i++) {
        val[i] = new C[n];
    }
}

/**
 * Constructeur par défaut : 1×1
 */
template<class C>
Matrice<C>::Matrice() : n(1) {
    val = new C*[1];
    val[0] = new C[1];
}

/**
 * Constructeur par copie
 */
template<class C>
Matrice<C>::Matrice(const Matrice& mat) : n(mat.n), val(nullptr) {
    val = new C*[n];
    for (int i = 0; i < n; i++) {
        val[i] = new C[n];
        for (int j = 0; j < n; j++) {
            val[i][j] = mat.val[i][j];
        }
    }
}

/**
 * Opérateur d'affectation
 */
template<class C>
Matrice<C>& Matrice<C>::operator=(const Matrice& mat) {
    if (this == &mat) return *this;
    
    if (n != mat.n) {
        for (int i = 0; i < n; i++) {
            delete[] val[i];
        }
        delete[] val;
        
        n = mat.n;
        val = new C*[n];
        for (int i = 0; i < n; i++) {
            val[i] = new C[n];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            val[i][j] = mat.val[i][j];
        }
    }
    return *this;
}

/**
 * Destructeur
 */
template<class C>
Matrice<C>::~Matrice() {
    for (int i = 0; i < n; i++) {
        delete[] val[i];
    }
    delete[] val;
}

/**
 * Initialise tous les éléments à d
 */
template<class C>
void Matrice<C>::init(C d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            val[i][j] = d;
        }
    }
}

/**
 * Affiche la matrice
 */
template<class C>
void Matrice<C>::affiche() const {
    cout << "Matrice (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(";
        for (int j = 0; j < n; j++) {
            cout << val[i][j];
            if (j != n - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
}

/**
 * Opérateur addition
 */
template<class C>
Matrice<C> Matrice<C>::operator+(const Matrice& A) const {
    if (n != A.n) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille");
    }
    Matrice res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.val[i][j] = val[i][j] + A.val[i][j];
        }
    }
    return res;
}

template<class C>
Matrice<C> Matrice<C>::operator*(const Matrice& A) const {
    if (n != A.n) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille");
    }
    Matrice res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C sum = C(0);
            for (int k = 0; k < n; k++) {
                sum = sum + val[i][k] * A.val[k][j];
            }
            res.val[i][j] = sum;
        }
    }
    return res;
}

/**
 * Calcule le déterminant par développement de Laplace (récursif)
 */
template<class C>
C Matrice<C>::Determinant() const {
    if (n == 1) {
        return val[0][0];
    }
    if (n == 2) {
        return val[0][0] * val[1][1] - val[0][1] * val[1][0];
    }

    C det = C(0);

    for (int j = 0; j < n; ++j) {
        // Création de la sous-matrice mineure
        Matrice<C> sousMatrice(n - 1);
        for (int k = 1; k < n; ++k) {
            int col = 0;
            for (int l = 0; l < n; ++l) {
                if (l == j) continue;
                sousMatrice.val[k - 1][col] = val[k][l];
                col++;
            }
        }

        // Calcul du cofacteur
        C cofacteur = val[0][j] * sousMatrice.Determinant();
        // Appliquer le signe (-1)^j
        if (j % 2 != 0) {
            cofacteur = -cofacteur;
        }
        det = det + cofacteur;
    }

    return det;
}

/**
 * Calcule le déterminant par élimination de Gauss (plus rapide)
 */
template<class C>
C Matrice<C>::DeterminantParPivot() {
    Matrice<C> A = *this;
    C det = C(1);
    for (int i = 0; i < n; i++) {
        int piv = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv = j;
        }
        if (A.get(piv, i) == C(0)) return C(0);
        if (piv != i) det = -det;

        C pivot = A.get(i, i);
        det = det * pivot;
        for (int j = i; j < n; j++) {
            A.set(i, j, A.get(i, j) / pivot);
        }

        for (int j = i + 1; j < n; j++) {
            C coef = A.get(j, i);
            for (int k = i; k < n; k++) {
                A.set(j, k, A.get(j, k) - coef * A.get(i, k));
            }
        }
    }
    return det;
}

/**
 * Effectue une élimination de Gauss avec pivot partiel
 */
template<class C>
Matrice<C> Matrice<C>::Pivot() {
    Matrice<C> A = *this;
    for (int i = 0; i < n; i++) {
        int piv = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv = j;
        }
        if (A.get(piv, i) == C(0)) return A;

        C pivot = A.get(i, i);
        for (int j = i; j < n; j++) {
            A.set(i, j, A.get(i, j) / pivot);
        }

        for (int j = i + 1; j < n; j++) {
            C coef = A.get(j, i);
            for (int k = i; k < n; k++) {
                A.set(j, k, A.get(j, k) - coef * A.get(i, k));
            }
        }
    }
    return A;
}

/**
 * Lit la matrice depuis un fichier
 */
template<class C>
void Matrice<C>::read(std::ifstream& fichiervecteur, int n) {
    if (!fichiervecteur.is_open()) {
        throw std::runtime_error("Fichier non ouvert");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(fichiervecteur >> val[i][j])) {
                throw std::runtime_error("Erreur lors de la lecture de la matrice");
            }
        }
    }
}

/**
 * Résout AX = B par élimination de Gauss avec pivot partiel
 * CORRIGÉ : Bug dans le swap du vecteur B
 */
template<class C>
Vect<C> Matrice<C>::gauss(Vect<C>& B) {
    Matrice<C> A = *this;
    Vect<C> b = B;

    // Phase de remontée (forward elimination)
    for (int i = 0; i < n; i++) {
        // Trouver le pivot
        int piv = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv = j;
        }

        // Échanger les lignes si nécessaire
        if (piv != i) {
            for (int k = i; k < n; k++) {
                C temp = A.get(i, k);
                A.set(i, k, A.get(piv, k));
                A.set(piv, k, temp);
            }
            // CORRIGÉ : Bug original - b.set(i, b.get(piv)) manquait un argument
            C temp = b.get(i);
            b.set(i, b.get(piv));
            b.set(piv, temp);
        }

        // Vérifier que le pivot n'est pas zéro
        if (A.get(i, i) == C(0)) {
            std::cout << "Avertissement: pivot zéro à la position " << i << endl;
            continue;
        }

        // Élimination
        for (int j = i + 1; j < n; j++) {
            C coef = A.get(j, i) / A.get(i, i);
            for (int k = i; k < n; k++) {
                A.set(j, k, A.get(j, k) - coef * A.get(i, k));
            }
            b.set(j, b.get(j) - coef * b.get(i));
        }
    }

    // Phase de descente (back substitution)
    Vect<C> X(n);
    for (int i = n - 1; i >= 0; i--) {
        C sum = b.get(i);
        for (int j = i + 1; j < n; j++) {
            sum = sum - A.get(i, j) * X.get(j);
        }
        if (A.get(i, i) != C(0)) {
            X.set(i, sum / A.get(i, i));
        }
    }

    return X;
}

/**
 * Résout AX = B par décomposition LU
 */
template<class C>
Vect<C> Matrice<C>::solveLU(Vect<C>& B) {
    Matrice<C> A = *this;
    Vect<C> b = B;

    // Décomposition LU avec pivot partiel
    for (int i = 0; i < n; i++) {
        // Trouver le pivot
        int piv = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv = j;
        }

        // Échanger les lignes
        if (piv != i) {
            for (int k = 0; k < n; k++) {
                C temp = A.get(i, k);
                A.set(i, k, A.get(piv, k));
                A.set(piv, k, temp);
            }
            C temp = b.get(i);
            b.set(i, b.get(piv));
            b.set(piv, temp);
        }

        // Vérifier pivot
        if (A.get(i, i) == C(0)) {
            std::cout << "Avertissement: pivot zéro à la position " << i << endl;
            continue;
        }

        // Calcul des multiplicateurs et élimination
        for (int j = i + 1; j < n; j++) {
            C multiplier = A.get(j, i) / A.get(i, i);
            A.set(j, i, multiplier);

            for (int k = i + 1; k < n; k++) {
                A.set(j, k, A.get(j, k) - multiplier * A.get(i, k));
            }
        }
    }

    // Forward substitution : Ly = b
    Vect<C> y(n);
    for (int i = 0; i < n; i++) {
        C sum = b.get(i);
        for (int j = 0; j < i; j++) {
            sum = sum - A.get(i, j) * y.get(j);
        }
        y.set(i, sum);
    }

    // Back substitution : Ux = y
    Vect<C> X(n);
    for (int i = n - 1; i >= 0; i--) {
        C sum = y.get(i);
        for (int j = i + 1; j < n; j++) {
            sum = sum - A.get(i, j) * X.get(j);
        }
        if (A.get(i, i) != C(0)) {
            X.set(i, sum / A.get(i, i));
        }
    }

    return X;
}

/**
 * Getter pour l'élément (i,j)
 */
template<class C>
C Matrice<C>::get(int i, int j) const {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        throw std::out_of_range("Index hors limites");
    }
    return val[i][j];
}

/**
 * Setter pour l'élément (i,j)
 */
template<class C>
void Matrice<C>::set(int i, int j, C value) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        throw std::out_of_range("Index hors limites");
    }
    val[i][j] = value;
}

/**
 * Retourne la taille de la matrice
 */
template<class C>
int Matrice<C>::size() const {
    return n;
}

/**
 * Produit matrice-vecteur : A * B
 */
template<class C>
Vect<C> Matrice<C>::produit_matrice_vecteur(const Vect<C>& B) const {
    if (B.size() != n) {
        throw std::invalid_argument("Taille du vecteur incompatible avec la matrice");
    }
    Vect<C> res(n);
    for (int i = 0; i < n; i++) {
        C sum = C(0);
        for (int j = 0; j < n; j++) {
            sum = sum + val[i][j] * B.get(j);
        }
        res.set(i, sum);
    }
    return res;
}

/**
 * Résout AX = B par descente de gradient
 * CORRIGÉ : Meilleure gestion du type générique
 */
template<class C>
Vect<C> Matrice<C>::descente_de_gradient(const Vect<C>& B, double tolerance) {
    // Initialisation de X à zéro
    Vect<C> X(n);
    X.init(C(0));

    // Calcul du résidu initial: r = B - A*X = B
    Vect<C> r = B;

    // Boucle d'itération jusqu'à convergence
    int max_iterations = 1000;  // Limite pour éviter boucles infinies
    int iteration = 0;
    
    while (iteration < max_iterations) {
        iteration++;
        
        // Calcul de A*r
        Vect<C> Ar = produit_matrice_vecteur(r);

        // Calcul de alpha = <r,r> / <r,A*r>
        C r_scal_r = r.scal(r);
        C r_scal_Ar = r.scal(Ar);

        if (r_scal_Ar == C(0)) {
            std::cout << "Attention: dénominateur zéro dans la descente de gradient" << endl;
            break;
        }

        C alpha = r_scal_r / r_scal_Ar;

        // Mise à jour de X: X = X + alpha * r
        X = X + r.produit_externe(alpha);

        // Mise à jour du résidu: r = r - alpha * A*r
        r = r - Ar.produit_externe(alpha);

        // Vérifier la convergence: ||r||² < tolerance²
        double r_norm_sq = r.difference_norme(r - r);
        if (r_norm_sq < tolerance * tolerance) {
            cout << "Convergence atteinte après " << iteration << " itérations" << endl;
            break;
        }
    }

    if (iteration == max_iterations) {
        cout << "Avertissement: nombre maximal d'itérations atteint" << endl;
    }

    return X;
}
