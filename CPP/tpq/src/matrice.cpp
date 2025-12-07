// Fichier vide - les implémentations des templates Matrice sont dans include/qq.h
#include "matrice.hpp"
#include <iostream>
#include <fstream>

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
            val[i][j]=d;
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
            cout<<val[j][i];
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
            res.val[i][j]=val[i][j]+A.val[i][j];
        }
    }
    return res;
};

/*
Surcharge du = pour l'affectation
*/
template<class C>
Matrice<C>& Matrice<C>::operator=(const Matrice& mat){
    if (n != mat.n) {
        for(int i=0; i<n; i++){
            delete[] val[i];
        }
        delete[] val;
        n = mat.n;
        val = new C* [n];
        for(int i=0; i<n; i++){
            val[i] = new C[n];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            val[i][j] = mat.val[i][j];
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
            res.val[i][j]=0;
            for(int k=0; k<n; k++){
                res.val[i][j]+=val[i][k]*A.val[k][j];
            }
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
Calcule le determinant d'une matrice par la methode de Gauss
*/
template<class C>
C Matrice<C>::Determinant(){
    Matrice<C> A = *this;
    C det = 1;
    for(int i=0; i<n; i++){
        int piv=i;
        for(int j=i+1; j<n; j++){
            if((double)A.val[j][i] > (double)A.val[piv][i]) piv=j;
        }
        if((double)A.val[piv][i] == 0) return 0;
        if(piv!=i) det = -det;
        
        C pivot = A.val[i][i];
        det = det * A.val[i][i];
        for(int j=i; j<n; j++){
            A.val[i][j] = A.val[i][j]  / pivot;
        }
        
        for(int j=i+1; j<n; j++){
            C coef = A.val[j][i];
            for(int k=i; k<n; k++){
                A.val[j][k] = A.val[j][k] - coef*A.val[i][k];
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
            if((double)A.val[j][i] > (double)A.val[piv][i]) piv=j;
        }
        if((double)A.val[piv][i] == 0) return A;
        
        C pivot = A.val[i][i];
        for(int j=i; j<n; j++){
            A.val[i][j] = A.val[i][j]  / pivot;
        }
        
        for(int j=i+1; j<n; j++){
            C coef = A.val[j][i];
            for(int k=i; k<n; k++){
                A.val[j][k] = A.val[j][k] - coef*A.val[i][k];
            }
        }
    }
    return A;
};

// Instanciations explicites pour les types utilisés
template class Matrice<double>;
template class Matrice<int>;

// Inclure les déclarations pour les types plus complexes si nécessaire
#include "qq.h"
template class Matrice<qq>;
