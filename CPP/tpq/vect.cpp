#include "qq.h"
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
//à changer pour pas convertir
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
    //assert(lg==U.lg);
    Vect W = Vect(lg);
    for(int i=0; i<lg ;i++){
        W.val[i]=val[i]+U.val[i];
        
    }
    
    Vect V=U;
    V.affiche();
    return W;

};



/*
Entrée : Deux vecteurs A et B
Sortie : A + B
Fonction d'addition de deux vecteurs "par copie"
*/
template<class C>
void Vect<C>::add(const Vect& A, const Vect& B){
    assert(A.lg==B.lg);
    lg=A.lg;
    for (int i=0; i<lg; i++){
        val[i]=A.val[i]+B.val[i];
    }
    
};


template<class C>
void Vect<C>::scal(const Vect& A, const Vect& B){
    assert(A.lg==B.lg);
    lg=A.lg;
    for (int i=0; i<lg; i++){
        val[i]=A.val[i]*B.val[i];
    }
};

/*
Surcharge de suppression
*/
template<class C>
Vect<C>::~Vect(){
    
    delete [] val;
};

/*
Lecture d'un vecteur
*/
template<class C>
void Vect<C>::read(std::ifstream& fichiervecteur, int taille){
    lg=taille;
    val = new C [lg];
    C valeur;

    for(int i=0; i<lg; i++){
        fichiervecteur>>valeur;
        val[i]=valeur;
    }
}


//fonction qui multpilie un vecteur par une matrice et qui rends un vecteur
template<class C>
Vect<C> Vect<C>::multparmat(const Matrice<C>& M){
    if(M.n!=lg)
    
}

//On instancie les possibilitées de base pour ne pas avoir d'erreur 
template class Vect<double>;
template class Vect<qq>;
