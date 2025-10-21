#include "matrice2.h"
using namespace std;

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
    
};

/*
Constructeur par défaut
*/
Matrice::Matrice(){
    nbl=1;
    nbc=1;
    val = new double* [nbl];
    for(int i=0; i<nbl; i++){
        val[i] = new double [nbc];
    }
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            val[i][j]=0;
        }
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
};

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
};

/*
Surcharge de l'addition pour les matrices.
*/
Matrice Matrice::operator+(Matrice& mat){
    if(nbl != mat.nbl || nbc != mat.nbc){
        cerr<<"Pas la même taille de matrice"<<endl;
        exit(1);
    }
    Matrice Mresult = Matrice(nbl, nbc);
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            Mresult.val[i][j] = val[i][j]+mat.val[i][j];
        }
    }
    return Mresult;
};

/*
Surcharge du constructeur par copie
*/
Matrice::Matrice(const Matrice& mat){
    
    nbl = mat.nbl;
    nbc = mat.nbc;
    val = new double* [nbl];
    for(int i=0; i<nbl; i++){
        val[i] = new double [nbc];
    }
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            val[i][j]=mat.val[i][j];
        }
    }
};

/*
Surcharge de l'operateur d'affectation
*/
Matrice& Matrice::operator=(const Matrice& mat) {
    if (nbl != mat.nbl || nbc != mat.nbc) {
        for(int i=0; i<nbl; i++){
            delete [] val[i];
        }
        delete [] val;
        nbl = mat.nbl;
        nbc = mat.nbc;
        val = new double* [nbl];
        for(int i=0; i<nbl; i++){
            val[i] = new double [nbc];
        }
        for(int i=0; i<nbl; i++){
            for(int j=0; j<nbc; j++){
                val[i][j]=mat.val[i][j];
            }
        }
    }
    return *this;
};

/*
Surcharge du destructeur
*/
Matrice::~Matrice(){
    for(int i=0; i<nbl; i++){
        delete [] val[i];
    }
    delete [] val;
};