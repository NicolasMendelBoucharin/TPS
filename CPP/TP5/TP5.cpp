#include "TP5.h"
using namespace std;
// void init(double d);
// void affiche();
// void modif(int i, double r);
// explicit Vec(int n=0):;
// Vec(const Vec&);
// Vec& operator=(const Vec&);
// friend int getlg(const Vec& U);
// Vec operator+(const Vec& U);
// void add(const Vec& A, const Vec& B);
// ~Vec();



void Vec::init(double d){
    for(int i=0; i<this->size(); i++){
        (*this)[i]=d;
    }
}

void Vec::modif(int i, double d){
    (*this)[i] = d;
}

void Vec::affiche(){
    cout<<"( ";
    for(int i=0; i<this->size(); i++){
        cout<<(*this)[i]<< " ";
    }
    cout<<")"<<endl;
}

Vec Vec::operator+(const Vec& U){
    int taille=U.size();
    if (taille<(this->size())){
        cout<<"Warning : Le vecteur de gauche était plus long que celui de droite"<<endl;
    }
    if (taille>(this->size())){
        cout<<"Warning : Le vecteur de droite était plus long que celui de gauche"<<endl;
    }
    Vec Res = Vec(taille);
    for(int i=0; i<taille; i++){
        Res[i]=(*this)[i]+U[i];
    }
    return Res;
}

