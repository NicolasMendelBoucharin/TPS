#include "matrice4.h"
using namespace std;

//___________________Matrices________________________

void Matrice::affiche(std::string nom){};
void Matrice::init(double d){};
Matrice Matrice::operator+(const Matrice&){return *this;}
Matrice& Matrice::operator=(const Matrice& mat){return *this;}


//________________Matrices pleines______________________
/*
Constructeur pour matrice pleine
entrée : un nombre de lignes et un nombre de colonnes
sortie : une matrice de la bonne taille (mais vide)
*/
MatFull::MatFull(int const nl, int const nc){
    nbl=nl;
    nbc=nc;
    val = new double* [nbl];
    for(int i=0; i<nbl; i++){
        val[i] = new double [nbc];
    }
    
};

/*
Constructeur par défaut pour matrice pleine
*/
MatFull::MatFull(){
    nbl=1;
    nbc=1;
    val = new double* [1];
    val[0]=new double [1];
    val[0][0]=0;
};

void MatFull::init(double d){
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            val[i][j]=d;
        }
    }
};

/*
Affiche une matrice pleine
J'ai changé par rapport au fichier d'avant parce que sinon c'est un enfer pour les matrices symétrique que ça ait la même tête
*/
void MatFull::affiche(string nom){
    cout<<"La matrice "<< nom << " est :"<<endl;
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            cout<<val[i][j]<<" ";
        }
        cout<<endl;
    }
};

/*
Surcharge de l'addition pour les matrices pleines.
*/
MatFull MatFull::operator+(const MatFull& mat){
    if(nbl != mat.nbl || nbc != mat.nbc){
        cerr<<"Pas la même taille de MatFull"<<endl;
        exit(1);
    }
    MatFull Mresult = MatFull(nbl, nbc);
    for(int i=0; i<nbl; i++){
        for(int j=0; j<nbc; j++){
            Mresult.val[i][j] = val[i][j]+mat.val[i][j];
        }
    }
    return Mresult;
};

/*
Surcharge du constructeur par copie pour matrice pleine
*/
MatFull::MatFull(const MatFull& mat){
    
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
Surcharge de l'operateur d'affectation pour une matrice pleine
*/
MatFull& MatFull::operator=(const MatFull& mat) {
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
MatFull::~MatFull(){
    for(int i=0; i<nbl; i++){
        delete [] val[i];
    }
    delete [] val;
};

// /*
// Lecture du fichier et écriture dans une matrice
// */
// void Matrice::read(std::ifstream& fichierentree){
//     int nl;
//     int nc;
//     fichierentree>>nl;
//     fichierentree>>nc;
//     for(int i=0; i<nbl; i++){
//         delete [] val[i];
//     }
//     delete [] val;
//     nbl=nl;
//     nbc=nc;
//     val = new double* [nbl];
//     for(int i=0; i<nbl; i++){
//             val[i] = new double [nbc];
//         }
//     double d;

//     for(int i=0; i<nbl; i++){
//         for(int j=0; j<nbc; j++){
//             fichierentree>>d;
//             val[i][j]=d;
//         }
//     }
// }

// /*
// Ecriture dans le fichier la matrice
// */
// void Matrice::write(std::ofstream& fichiersortie){
//     fichiersortie<< (nbl) <<" "<< (nbc) <<endl;
//     for(int i=0; i<nbl; i++){
//         for(int j=0; j<nbc; j++){
//             fichiersortie<<val[i][j]<<" ";
//         }
//         fichiersortie<<endl;
//     }
// }


//___________Matrices Symétriques__________________


/*
Constructeur pour une matrice symetrique de taille n 
*/
MatSym::MatSym(int n){
    taille=n;
    val = new double* [taille];
    for(int i=0;i<taille;i++){
        val[i]=new double [i+1];
    }
}

/*
Constructeur par copie d'une matrice symétrique
*/

MatSym::MatSym(const MatSym& matS){
    if (taille != matS.taille) {
        taille=matS.taille;
        val = new double* [taille];
        for(int i=0; i<taille; i++){
            val[i] = new double [i+1];
        }
        for(int i=0; i<taille; i++){
            for(int j=0; j<i+1; j++){
                val[i][j]=matS.val[i][j];
            }
        }
    }
}

void MatSym::init(double d){
    for(int i=0; i<taille; i++){
        for(int j=0; j<i+1; j++){
            val[i][j]=d;
        }
    }
};

/*
Affiche la matrice symétrique
*/
void MatSym::affiche(string nom){
    cout<<"La matrice"<< nom << " est :"<<endl;
    for(int i=0; i<taille; i++){
        for(int j=0; j<i+1; j++){
            cout<<val[i][j]<<" ";
        }
        for(int j=i+1; j<taille; j++){
            cout<<val[j][i]<<" ";
        }
        cout<<endl;
    }
};

/*
Constructeur par défaut pour les matrices symétriques
*/
MatSym::MatSym(){
    taille=1;
    val = new double* [1];
    val[0]=new double [1];
    val[0][0]=0;
};

/*
Surcharge du destructeur pour les matrices symétriques
*/
MatSym::~MatSym(){
    for(int i=0; i<taille; i++){
        delete [] val[i];
    }
    delete [] val;
};

/*
Surcharge de l'addition pour les matrices symétriques.
*/
MatSym MatSym::operator+(const MatSym& mat){
    if(taille != mat.taille){
        cerr<<"Pas la même taille de MatSym"<<endl;
        exit(1);
    }
    MatSym Mresult = MatSym(taille);
    for(int i=0; i<taille; i++){
        for(int j=0; j<i+1; j++){
            Mresult.val[i][j] = val[i][j]+mat.val[i][j];
        }
    }
    return Mresult;
};

/*
Surcharge de l'operateur d'affectation pour une matrice symétrique
*/
MatSym& MatSym::operator=(const MatSym& mat) {
    if (taille != mat.taille) {
        for(int i=0; i<taille; i++){
            delete [] val[i];
        }
        delete [] val;
        taille=mat.taille;
        val = new double* [taille];
        for(int i=0; i<taille; i++){
            val[i] = new double [i+1];
        }
        for(int i=0; i<taille; i++){
            for(int j=0; j<i+1; j++){
                val[i][j]=mat.val[i][j];
            }
        }
    }
    return *this;
};