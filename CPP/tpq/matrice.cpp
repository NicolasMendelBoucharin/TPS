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

//full chat gpt
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

template<class C>
Matrice<C> Matrice<C>::Pivot() {
    Matrice<C> M(*this);   // copie de travail

    for (int i = 0; i < n; i++) {

        // --- Pivot partiel ---
        int pivot = i;
        double best = std::abs(double(M.val[i][i]));

        for (int r = i + 1; r < n; r++) {
            double cur = std::abs(double(M.val[r][i]));
            if (cur > best) {
                best = cur;
                pivot = r;
            }
        }

        // Échange des lignes si nécessaire
        if (pivot != i) {
            std::swap(M.val[i], M.val[pivot]);
        }

        // Si pivot nul → colonne ignorée (matrice singulière)
        if (std::abs(double(M.val[i][i])) < 1e-15) {
            continue;
        }

        // --- Élimination ---
        for (int r = i + 1; r < n; r++) {
            C m = M.val[r][i] / M.val[i][i];

            for (int c = i; c < n; c++) {
                M.val[r][c] = M.val[r][c] - m * M.val[i][c];
            }
        }
    }

    return M;
}

template<class C>
void Matrice<C>::read(std::ifstream& fichiermatrice, std::ifstream& fichierdonnee){
    int taille;
    int type;
    fichierdonnee>>taille;
    fichierdonnee>>type;

    for(int i=0; i<n; i++){
        delete [] val[i];
    }
    delete [] val;
    n=taille;

    if(type==0){
        val = new double* [n];
        for(int i=0; i<n; i++){
                val[i] = new C [n];
            }
        double d;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fichiermatrice>>d;
                val[i][j]=d;
            }
        }
    }
    else{
        val = new qq* [n];
        for(int i=0; i<n; i++){
                val[i] = new qq [n];
            }
        int numerator;
        int denominator;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fichiermatrice>>numerator;
                fichiermatrice>>denominator;
                val[i][j]=qq(numerator, denominator);
            }
        }
    }
}




//Il faut instancier de base pour pas avoir d'erreur
template class Matrice<double>;
template class Matrice<qq>;


//il faudrait essayer de faire des matrices creuses à terme

