#include "TP5.h"
int main(){
    Vec A = Vec(10);
    A.init(12);
    A.affiche();
    Vec B = Vec(5);
    B.init(3.14);
    B.affiche();
    Vec C = A+B;
    C.affiche();
}