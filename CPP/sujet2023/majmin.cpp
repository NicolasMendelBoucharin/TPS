#include "majmin.h"
minus::minus(const char tab[], int nbcar){
    lc=nbcar;
    c= new char[lc];
    for(int i=0; i<lc; i++){
        c[i]=tolower(tab[i]);
    }
}


majus::majus(const char tab[], int nbcar){
    lc=nbcar;
    c= new char[lc];
    for(int i=0; i<lc; i++){
        c[i]=toupper(tab[i]);
    }
}