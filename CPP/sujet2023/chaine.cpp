#include "chaine.h"
using namespace std;
chaine::chaine(const char tab[], int nbcar){
    lc=nbcar;
    c = new char[lc];
    for(int i=0; i<lc; i++){
        c[i]=tab[i];
    }

}

chaine::~chaine(){
    delete [] c;
}

void chaine::print(){
    for(int i =0; i<lc; i++){
        cout<<c[i];
        
    }
    cout<<endl;
}

chaine::chaine(){
    lc=0;
}

chaine::chaine(const chaine& chain){
    lc=chain.lc;
    c=new char[lc];
    for(int i=0; i<lc; i++){
        c[i]=chain.c[i];
    }

}