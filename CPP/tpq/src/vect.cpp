#include "vect.hpp"
#include <iostream>
#include <fstream>
#include "qq.h"
template class Vect<qq>;
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
Vect<C> Vect<C>::operator+(const Vect& U) const{
    Vect W = Vect(lg);
    for(int i=0; i<lg ;i++){
        W.val[i]=val[i]+U.val[i];
    }
    Vect V=U;
    //V.affiche()
    return W;
};

/*
Surcharge de l'opérateur -
*/
template<class C>
Vect<C> Vect<C>::operator-(const Vect& U) const { 
    Vect W = Vect(lg);
    for(int i=0; i<lg ;i++){
        W.val[i]=val[i]-U.val[i];
    }
    Vect V=U;
    //V.affiche();
    return W;
};

/*
Destructeur
*/
template<class C>
Vect<C>::~Vect(){
    delete[] val;
};

/*
Fonction d'addition de vecteurs
*/
template<class C>
void Vect<C>::add(const Vect& A, const Vect& B){
    for(int i=0; i<lg; i++){
        val[i]=A.val[i]+B.val[i];
    }
};

/*
Produit scalaire de deux vecteurs
*/
template<class C>
C Vect<C>::scal(const Vect& B){
    C result = 0;
    for(int i=0; i<lg; i++){
        result += val[i]*B.val[i];
    }
    return result;
};

/*
Fichier de lecture de fichier
*/
template<class C>
void Vect<C>::read(std::ifstream& fichiermatrice, int n){
    for(int i=0; i<n; i++){
        fichiermatrice>>val[i];
    }
};

//getter pour accès externe
template<class C>
C Vect<C>::get(int i) const{
    return val[i];
};

//setter (pas utilisé)
template<class C>
void Vect<C>::set(int i, C value){
    val[i] = value;
};

//getter pour accès externe
template<class C>
int Vect<C>::size() const{
    return lg;
};

/*produit avec un scalaire*/
template<class C>
Vect<C> Vect<C>::produit_externe(C scalar) {
    Vect<C> result(lg);
    for (int i = 0; i < lg; i++) {
        result.val[i] = val[i] * scalar;
    }
    return result;
};

/*différence de norme entre deux vecteurs
Attention ! renvoie le carré de la norme pas la norme elle-même
*/
template<class C>
C Vect<C>::difference_norme(const Vect<C>& B) {
    if (lg != B.lg) {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille pour calculer la différence de norme.");
    }
    C sum = 0;
    for (int i = 0; i < lg; i++) {
        C diff = val[i] - B.val[i];
        sum += diff * diff;
    }
    return sum;
};

// Instanciations explicites pour les types utilisés
template class Vect<double>;
template class Vect<int>;



