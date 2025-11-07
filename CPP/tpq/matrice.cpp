#include "qq.h"
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

}

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
        cout<<"("<<val[j][0];
        for(int i=1; i<n; i++){
            cout<<", "<<val[j][i];
        }
        cout<<")"<<endl;
    }
};

/*
Surcharge de l'addition pour les matrices.
*/
template<class C>
Matrice<C> Matrice<C>::operator+(const Matrice& mat){
    if(n != mat.n){
        cerr<<"Pas la même taille de matrice"<<endl;
        exit(1);
    }
    Matrice Mresult = Matrice(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Mresult.val[i][j] = val[i][j]+mat.val[i][j];
        }
    }
    return Mresult;
};

/*
Surcharge du constructeur par copie
*/
template<class C>
Matrice<C>::Matrice(const Matrice& mat){
    
    n = mat.n;
    val = new C* [n];
    for(int i=0; i<n; i++){
        val[i] = new C [n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            val[i][j]=mat.val[i][j];
        }
    }
};

/*
Surcharge de l'operateur d'affectation
*/
template<class C>
Matrice<C>& Matrice<C>::operator=(const Matrice& mat) {
    if (n != mat.n) {
        for(int i=0; i<n; i++){
            delete [] val[i];
        }
        delete [] val;
        n = mat.n;
        
        val = new C* [n];
        for(int i=0; i<n; i++){
            val[i] = new C [n];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                val[i][j]=mat.val[i][j];
            }
        }
    }
    return *this;
};

/*
Surcharge du destructeur
*/
template<class C>
Matrice<C>::~Matrice(){
    for(int i=0; i<n; i++){
        delete [] val[i];
    }
    delete [] val;
};

template class Matrice<double>;
template class Matrice<qq>;


