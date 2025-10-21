#include "matrice1.h"

int main(){
    int nl=4;
    int nc=5;
    Matrice M = Matrice(nl, nc);
    M.init(3.14);
    M.affiche();
    Matrice M2 = Matrice(nl, nc);
    M2.init(5);
    M2.affiche();
    Matrice M3=M+M2;
    M3.affiche();
};

