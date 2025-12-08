#include "matrice.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include "qq.h"
template class Matrice<double>;
template class Matrice<qq>;
using namespace std;

/*
entrée : un nombre de lignes et un nombre de colonnes
sortie : une matrice de la bonne taille (mais vide)
*/
template<class C>
Matrice<C>::Matrice(int const nl){
    n=nl;
    val = new C* [n];
    for(int i=0; i<n; i++){
        val[i] = new C [n];
    }
};

/*
Constructeur par défaut
*/
template<class C>
Matrice<C>::Matrice(){
    n=1;
    val = new C* [n];
    for(int i=0; i<n; i++){
        val[i] = new C [n];
    }
};

/*
Entrée : un C d
Initialise chaque valeur de la matrice à d.
*/
template<class C>
void Matrice<C>::init(C d){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            set(i, j, d);
        }
    }
};

/*
Affiche la matrice
*/
template<class C>
void Matrice<C>::affiche(){
    cout<<"La matrice est :"<<endl;
    for(int j=0; j<n; j++){
        cout<<"(";
        for(int i=0; i<n; i++){
            cout<<get(j, i);
            if(i!=n-1) cout<<", ";
        }
        cout<<")"<<endl;
    }
};

/*
Surcharge du + pour additionner deux matrices
*/
template<class C>
Matrice<C> Matrice<C>::operator+(const Matrice& A){
    Matrice res = Matrice(n);
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res.set(i, j, get(i, j) + A.get(i, j));
        }
    }
    return res;
};

/*
Surcharge du = pour l'affectation
*/
template<class C>
Matrice<C>& Matrice<C>::operator=(const Matrice& mat){
    if (n != mat.size()) {
        for(int i=0; i<n; i++){
            delete[] val[i];
        }
        delete[] val;
        n = mat.size();
        val = new C* [n];
        for(int i=0; i<n; i++){
            val[i] = new C[n];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            set(i, j, mat.get(i, j));
        }
    }
    return *this;
};

/*
Surcharge du * pour multiplier deux matrices
*/
template<class C>
Matrice<C> Matrice<C>::operator*(const Matrice& A){
    Matrice res = Matrice(n);
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C sum = 0;
            for(int k=0; k<n; k++){
                sum += get(i, k) * A.get(k, j);
            }
            res.set(i, j, sum);
        }
    }
    return res;
};

/*
Constructeur par copie
*/
template<class C>
Matrice<C>::Matrice(const Matrice& mat){
    n = mat.n;
    val = new C* [n];
    for(int i=0; i<n; i++){
        val[i] = new C[n];
        for(int j=0; j<n; j++){
            val[i][j] = mat.val[i][j];
        }
    }
};

/*
Destructeur
*/
template<class C>
Matrice<C>::~Matrice(){
    for(int i=0; i<n; i++){
        delete[] val[i];
    }
    delete[] val;
};

/*
Determinant par méthode des comatrices
*/
template<class C>
C Matrice<C>::Determinant() {
    // Cas de base : matrice 1x1
    if (n == 1) {
        return val[0][0];
    }
    // Cas de base : matrice 2x2
    if (n == 2) {
        return val[0][0] * val[1][1] - val[0][1] * val[1][0];
    }

    C det = 0; // Initialisation à zéro

    for (int j = 0; j < n; ++j) {
        // Création de la sous-matrice mineure
        Matrice<C> sousMatrice(n - 1);
        for (int k = 1; k < n; ++k) {
            int col = 0;
            for (int l = 0; l < n; ++l) {
                if (l == j) continue;
                sousMatrice.val[k-1][col] = val[k][l];
                col++;
            }
        }

        // Calcul du cofacteur
        C cofacteur = val[0][j] * sousMatrice.Determinant();
        // Appliquer le signe (-1)^(0+j)
        if (j % 2 != 0) {
            cofacteur = -cofacteur;
        }
        det = det + cofacteur;
    }

    return det;
}
/*
Calcule le determinant d'une matrice par la methode de Gauss
*/
template<class C>
C Matrice<C>::DeterminantParPivot(){
    Matrice<C> A = *this;
    C det = 1;
    for(int i=0; i<n; i++){
        int piv=i;
        for(int j=i+1; j<n; j++){
            if(std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv=j;
        }
        if(A.get(piv, i) == C(0)) return C(0);
        if(piv!=i) det = -det;
        
        C pivot = A.get(i, i);
        det = det * A.get(i, i);
        for(int j=i; j<n; j++){
            A.set(i, j, A.get(i, j) / pivot);
        }
        
        for(int j=i+1; j<n; j++){
            C coef = A.get(j, i);
            for(int k=i; k<n; k++){
                A.set(j, k, A.get(j, k) - coef*A.get(i, k));
            }
        }
    }
    return det;
};

/*
Lis une matrice à partir d'un fichier
*/
template<class C>
void Matrice<C>::read(std::ifstream& fichiervecteur, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fichiervecteur>>val[i][j];
        }
    }
};

/*
Effectue une pivot de Gauss
*/
template<class C>
Matrice<C> Matrice<C>::Pivot(){
    Matrice<C> A = *this;
    for(int i=0; i<n; i++){
        int piv=i;
        for(int j=i+1; j<n; j++){
            if(std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv=j;
        }
        if(A.get(piv, i) == C(0)) return A;
        
        C pivot = A.get(i, i);
        for(int j=i; j<n; j++){
            A.set(i, j, A.get(i, j) / pivot);
        }
        
        for(int j=i+1; j<n; j++){
            C coef = A.get(j, i);
            for(int k=i; k<n; k++){
                A.set(j, k, A.get(j, k) - coef*A.get(i, k));
            }
        }
    }
    return A;
};

/*
Algorithme de Gauss pour résoudre AX=B
Entrée : M (matrice A), B (vecteur B)
Sortie : Vect X tel que A*X = B
*/
template<class C>
Vect<C> Matrice<C>::gauss(Vect<C>& B){
    // Créer une copie de la matrice et du vecteur
    Matrice<C> A = *this;
    Vect<C> b = B;
    
    // Phase de remontée (forward elimination)
    for(int i=0; i<n; i++){
        // Trouver le pivot (celui avec la plus grande valeur absolue)
        int piv=i;
        for(int j=i+1; j<n; j++){
            if(std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv=j;
        }
        
        // Échanger les lignes si nécessaire
        if(piv != i){
            for(int k=i; k<n; k++){
                C temp = A.get(i, k);
                A.set(i, k, A.get(piv, k));
                A.set(piv, k, temp);
            }
            C temp = b.get(i);
            b.set(i, b.get(piv));
            b.set(piv, temp);
        }
        
        // Vérifier que le pivot n'est pas zéro
        if(A.get(i, i) == C(0)){
            std::cout << "Erreur: matrice singulière!" << std::endl;
            return b;
        }
        
        // Élimination
        for(int j=i+1; j<n; j++){
            C coef = A.get(j, i) / A.get(i, i);
            for(int k=i; k<n; k++){
                A.set(j, k, A.get(j, k) - coef*A.get(i, k));
            }
            b.set(j, b.get(j) - coef*b.get(i));
        }
    }
    
    // Phase de descente (back substitution)
    Vect<C> X(n);
    for(int i=n-1; i>=0; i--){
        C sum = b.get(i);
        for(int j=i+1; j<n; j++){
            sum = sum - A.get(i, j)*X.get(j);
        }
        X.set(i, sum / A.get(i, i));
    }
    
    return X;
};

/*
Résout AX=B en utilisant la décomposition LU
La matrice A est décomposée en L*U où L est triangulaire inférieure et U triangulaire supérieure
Ensuite on résout Ly=B (substitution avant) puis Ux=y (substitution arrière)
*/
template<class C>
Vect<C> Matrice<C>::solveLU(Vect<C>& B){
    // Créer une copie de la matrice pour la décomposition LU
    Matrice<C> A = *this;
    Vect<C> b = B;
    
    // Décomposition LU avec pivot partiel
    // A sera modifiée en place : la partie basse contient L-I, la partie supérieure contient U
    for(int i=0; i<n; i++){
        // Trouver le pivot
        int piv=i;
        for(int j=i+1; j<n; j++){
            if(std::abs(A.get(j, i)) > std::abs(A.get(piv, i))) piv=j;
        }
        
        // Échanger les lignes si nécessaire
        if(piv != i){
            for(int k=0; k<n; k++){
                C temp = A.get(i, k);
                A.set(i, k, A.get(piv, k));
                A.set(piv, k, temp);
            }
            C temp = b.get(i);
            b.set(i, b.get(piv));
            b.set(piv, temp);
        }
        
        // Vérifier que le pivot n'est pas zéro
        if(A.get(i, i) == C(0)){
            std::cout << "Erreur: matrice singulière!" << std::endl;
            return b;
        }
        
        // Calcul des multiplicateurs (facteurs de L)
        for(int j=i+1; j<n; j++){
            C multiplier = A.get(j, i) / A.get(i, i);
            A.set(j, i, multiplier);
            
            // Élimination : U(j, k) = A(j, k) - multiplier * A(i, k)
            for(int k=i+1; k<n; k++){
                A.set(j, k, A.get(j, k) - multiplier*A.get(i, k));
            }
        }
    }
    
    // Forward substitution : Ly = b
    // L est stockée dans la partie basse de A avec diagonale = 1
    Vect<C> y(n);
    for(int i=0; i<n; i++){
        C sum = b.get(i);
        for(int j=0; j<i; j++){
            sum = sum - A.get(i, j)*y.get(j);
        }
        y.set(i, sum);
    }
    
    // Back substitution : Ux = y
    // U est stockée dans la partie supérieure de A
    Vect<C> X(n);
    for(int i=n-1; i>=0; i--){
        C sum = y.get(i);
        for(int j=i+1; j<n; j++){
            sum = sum - A.get(i, j)*X.get(j);
        }
        X.set(i, sum / A.get(i, i));
    }
    
    return X;
};

/*
Getters pour pas avoir à mettre en public les données membres
*/
template<class C>
C Matrice<C>::get(int i, int j) const{
    return val[i][j];
};

template<class C>
int Matrice<C>::size() const{
    return n;
};

/*
Setter pour la même raison
*/
template<class C>
void Matrice<C>::set(int i, int j, C value){
    val[i][j] = value;
};

/*
Produit Matrice Vecteur
*/

template<class C>
Vect<C> Matrice<C>::produit_matrice_vecteur(Vect<C> B){
    if (B.size() != n) {
        throw std::invalid_argument("Taille du vecteur incompatible avec la matrice");
    }
    Vect<C> res;
    res = Vect<C>(n);
    for (int i = 0; i < n; i++) {
        C sum = 0;
        for (int j = 0; j < n; j++) {
            sum = sum + get(i, j) * B.get(j);;
        }
        res.set(i, sum);
    }
    return res;
};

/* Descente de gradient */

template<class C>
Vect<C> Matrice<C>::descente_de_gradient(const Vect<C>& B, double tolerance) {
    // Initialisation de X à zéro
    Vect<C> X(n);
    X.init(C(0));
    
    // Calcul du résidu initial: r = B - A*X = B
    Vect<C> r = B;
    
    // Boucle d'itération jusqu'à convergence
    while (true) {
        // Calcul de A*r
        Vect<C> Ar = produit_matrice_vecteur(r);
        
        // Calcul de alpha = <r,r> / <r,A*r>
        C r_scal_r = r.scal(r);
        C r_scal_Ar = r.scal(Ar);
        
        C alpha = r_scal_r / r_scal_Ar;
        
        // Mise à jour de X: X = X + alpha * r
        X = X + r.produit_externe(alpha);
        
        // Mise à jour du résidu: r = r - alpha * A*r
        r = r - Ar.produit_externe(alpha);
        
        // Vérifier la convergence: ||r|| < tolerance
        double r_norm = std::sqrt(std::abs(static_cast<double>(r.scal(r))));
        if (r_norm < tolerance) {
            break;
        }
    }
    
    return X;
}
// faire la différence