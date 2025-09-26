#include "vect3.h"

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

Vect& Vect::operator+(Vect& U){
    if (lg != U.lg){
        this->lg=0;
        cout<<"problème de taille"<<endl;
        return *this;
        
    };
    for (int i =0; i<lg; i++){
        this->val[i]=val[i]+U.val[i];
    }
    return *this;
};

void Vect::add(const Vect& A, const Vect& B){
    if(A.lg != B.lg){
        lg=0;
    }
    else{
        lg=A.lg;
        for (int i=0; i<lg; i++){
            val[i]=A.val[i]+B.val[i];
        }
    }
};

Vect::~Vect(){
    delete [] val;
    lg=0;
};



