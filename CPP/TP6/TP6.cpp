#include "TP6.h"
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
        cout<<"Warning : Le vecteur de gauche était plus long que celuide droite"<<endl;
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

void affiche(std::vector<double> &V, int n){
    
      for(int i=0; i<min(n, (int)V.size()); i++){
        cout<<V[i]<< " ";
    }
}

void affiche(std::vector<double> &V ){

    for(auto it=V.begin(); it<V.end(); it++){
        cout<<*it<< " ";
    }
    cout<<endl;
}

std::vector<double> readFromFile(std::ifstream& fichierentree){
    vector<double> A;
    std::istream_iterator<double> iit(fichierentree);
    while(!fichierentree.eof()){
        A.push_back(*iit);
        iit++;
    }
    return A;
};

template <class L, class I>
void somme(const std::vector<L> &A, const std::vector<I> &B, std::vector<L> &C){
    int i=0;
    for(auto it=C.begin(); it<C.end(); it++){
        *it=(A[i]+(L)B[i]);
        i++;
    }
};
/*
Créé une matrice de double et affiche toute les valeurs.
*/

std::vector<std::vector<double>> matricemake(int n, int m, double d){
    vector<vector<double>> M(n, vector<double> (m, d));
    return M;
}

void matriceaffiche(std::vector<std::vector<double>> &M){
    cout<<endl;
    for (int i=0; i<M.size(); i++){
        affiche(M[i]);
    }
}




