#include "matrice1.h"
/*
entrée : un nombre de lignes et un nombre de colonnes
sortie : une matrice de la bonne taille (mais vide)
*/
Matrice::Matrice(int const nl, int const nc){
    nbl=nl;
    nbc=nc;
    val = new double* [nbl];
    for(int i=0; i<nbl; i++){
        val[i] = new double [nbc];
    }
    
}

/*
Entrée : un double d
Initialise chaque valeur de la matrice à d.
*/
void Matrice::init(double d){
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            val[i][j]=d;
        }
    }
}

/*
Affiche la matrice
*/
void Matrice::affiche(){
    cout<<"La matrice est :"<<endl;
    for(int j=0; j<nbl; j++){
        cout<<"("<<val[j][0];
        for(int i=1; i<nbc; i++){
            cout<<", "<<val[j][i];
        }
        cout<<")"<<endl;
    }
}

