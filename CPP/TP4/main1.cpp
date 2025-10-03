#include "matrice1.h"

int main(){
    int nl=4;
    int nc=5;
    Matrice M = Matrice(nl, nc);
    M.init(3.14);
    M.affiche();
}