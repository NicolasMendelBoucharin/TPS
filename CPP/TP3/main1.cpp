#include "vect2.h"


int main(){

    Vect v=Vect(5);
    v.init(3.14);
    v.affiche();
    v.modif(2, 4);
    v.affiche();
    Vect u(v);
    u.affiche();
    Vect u1 = v;
    u1.affiche();
};