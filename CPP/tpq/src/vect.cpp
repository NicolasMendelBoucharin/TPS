#include "vect.hpp"
#include <iostream>
#include <fstream>

using namespace std;

/*
Entrée : Une valeur qu'on assigne à toute les cases du tableau
*/
template<class C>
void Vect<C>::init(C d){
    for(int i=0; i<lg; i++){
        val[i]=d;
    }
};

/*
Affiche toute les valeurs d'un vecteur
*/
template<class C>
void Vect<C>::affiche(){
    cout<<"("<<val[0];
    for(int i=1; i<lg; i++){
        cout<<", "<<val[i];
    }
    cout<<")"<<endl;
};

/*
Entrée : un entier i de position dans le tableau, un réel r
Associe la valeur r à la position i dans le tableau
*/
template<class C>
void Vect<C>::modif(int i, C r){
    val[i]=r;
};

/*
Entrée : un entier n 
Initialise le vecteur en créant un tableau de taille n 
*/
template<class C>
Vect<C>::Vect(int n){
    val = new C[n];
    lg=n;
};

/*
Entrée : un vecteur V
Sortie : un autre vecteur avec les mêmes valeurs que V 
Constructeur par copie
*/
template<class C>
Vect<C>::Vect(const Vect& V){
    lg = V.lg;
    val = new C[lg];
    for (int i=0; i<lg; i++){
        val[i] = V.val[i];
    };
};

/*
Surcharge de l'opérateur '='
Récupère la longueur et toute les valeurs du tableau à droite du '='
*/
template<class C>
Vect<C>& Vect<C>::operator=(const Vect& V) { 
    if (lg != V.lg) {
        delete [] val;
        lg = V.lg; 
        val = new C [lg];
    }
    for (int i=0; i<lg; i++) { 
        val[i]=V.val[i]; 
    }
    return *this;
};

/*
Surcharge de l'operateur +
*/
template<class C>
Vect<C> Vect<C>::operator+(const Vect& U){
    Vect W = Vect(lg);
    for(int i=0; i<lg ;i++){
        W.val[i]=val[i]+U.val[i];
    }
    Vect V=U;
    V.affiche();
    return W;
};

/*
Destructeur
*/
template<class C>
Vect<C>::~Vect(){
    delete[] val;
};

template<class C>
void Vect<C>::add(const Vect& A, const Vect& B){
    for(int i=0; i<lg; i++){
        val[i]=A.val[i]+B.val[i];
    }
};

template<class C>
void Vect<C>::scal(const Vect& A, const Vect& B){
    val[0]=0;
    for(int i=0; i<lg; i++){
        val[0]=val[0]+A.val[i]*B.val[i];
    }
};

template<class C>
void Vect<C>::read(std::ifstream& fichiermatrice, int n){
    for(int i=0; i<n; i++){
        fichiermatrice>>val[i];
    }
};

template<class C>
C Vect<C>::get(int i) const{
    return val[i];
};

template<class C>
void Vect<C>::set(int i, C value){
    val[i] = value;
};

template<class C>
int Vect<C>::size() const{
    return lg;
};

// Instanciations explicites pour les types utilisés
template class Vect<double>;
template class Vect<int>;

// Inclure les déclarations pour les types plus complexes si nécessaire
#include "qq.h"
template class Vect<qq>;
