#include "vect2.h"
//J'ai commenté que le vect3 parce que c'est ça + d'autres trucs alors


void Vect::init(double d){
    for(int i=0; i<lg; i++){
        val[i]=d;
    }
};

void Vect::affiche(){
    cout<<"("<<val[0];
    for(int i=1; i<lg; i++){
        cout<<", "<<val[i];
    }
    cout<<")"<<endl;
};

void Vect::modif(int i, double r){
    val[i]=r;
};

Vect::Vect(int n){
    val = new double[n];
    lg=n;
};

Vect::Vect(const Vect& V){
    lg = V.lg;
    val = new double[lg];
    for (int i=0; i<lg; i++){
        val[i] = V.val[i];
    };
};


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

//J'ai du utiliser un friend c'est pas dingue
int getlg(const Vect& U){
    return  U.lg;
};
