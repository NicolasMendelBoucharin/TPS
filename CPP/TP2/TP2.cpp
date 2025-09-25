#include "TP2.h"

int prod(int a, int b){
    return a*b;
}

double prod(double a, double b){
    return a*b;
}

//float prod(double a, double b){
  //  return a*b;
//}

float carre(float &a){
    a = a*a;
    return a;
}

void carre(float *a){
    *a = (*a) * (*a);
}

float carreV(const float a){
    return a*a;
}

//void carreP(const float *a){
    //*a = (*a)*(*a); //problème avec le type constant
//}

//void carreR(const float &a){
    //a = a*a
//}

