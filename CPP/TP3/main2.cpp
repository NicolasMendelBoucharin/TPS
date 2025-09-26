#include "vect2.h"


int main(){

    Vect V=Vect(5);
    V.init(3.14);
    V.affiche();
    Vect U;
    U.affiche();
    //on ne pourrait pas modifier U car il est vide je crois
    U=V;
    U.affiche();
    U.modif(2, 4);
    U.affiche();
    V.affiche();
    //on a aussi modifié les valeurs de V en modifiant celles de U. 
    V.init(3.14);
    V.affiche();
    Vect U1=Vect(V);
    U1.affiche();
    V.modif(2, 4);
    V.affiche();
    U1.affiche();
    U=V;
    U.affiche();
    Vect W;
    W=U=V;
    W.affiche();
};