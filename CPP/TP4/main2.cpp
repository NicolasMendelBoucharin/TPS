#include "matrice1.h"

int main(){
    int nl=4;
    int nc=5;
    Matrice A = Matrice(nl, nc);
    A.init(3.14);
    A.affiche();
    Matrice B = Matrice(nl, nc);
    B.init(5);
    B.affiche();
    Matrice C(A);
    Matrice D;
    D=A+B;
    C.affiche();
    D.affiche();
}