#include "vect3.h"

/*
Entrée : Une valeur qu'on assigne à toute les cases du tableau
*/
void Vect::init(double d){
    
    for(int i=0; i<lg; i++){
        val[i]=d;
    }
};

/*
Affiche toute les valeurs d'un vecteur
*/
void Vect::affiche(){
    
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
void Vect::modif(int i, double r){
    
    val[i]=r;
};

/*
Entrée : un entier n 
Initialise le vecteur en créant un tableau de taille n 
*/
Vect::Vect(int n){
    
    val = new double[n];
    lg=n;
};

/*
Entrée : un vecteur V
Sortie : un autre vecteur avec les mêmes valeurs que V 
Constructeur par copie
*/
Vect::Vect(const Vect& V){
    
    lg = V.lg;
    val = new double[lg];
    for (int i=0; i<lg; i++){
        val[i] = V.val[i];
    };
};

/*
Surcharge de l'opérateur '='
Récupère la longueur et toute les valeurs du tableau à droite du '='
*/
Vect& Vect::operator=(const Vect& V) {
    
    if (lg != V.lg) {
        delete [] val;
        lg = V.lg; 
        val = new double [lg];
    }
    for (int i=0; i<lg; i++) { 
        val[i]=V.val[i]; 
    }
    return *this;
};


//pour la fonction getlg j'ai du faire un friend, c'est peut être un peu de la triche
/*
Entrée : un vecteur U
Sortie : sa longueur lg
*/
int getlg(const Vect& U){
    
    return  U.lg;
};


Vect Vect::operator+(const Vect& U){
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
void Vect::add(const Vect& A, const Vect& B){
    assert(A.lg==B.lg);
    lg=A.lg;
    for (int i=0; i<lg; i++){
        val[i]=A.val[i]+B.val[i];
    }
    
};

/*
Surcharge de suppression
*/
Vect::~Vect(){
    
    delete [] val;
};




