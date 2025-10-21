#include "matrice4.h"
using namespace std;
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
    Matrice F=A+B+A;
    F.affiche();
    Matrice G=A+(B+A);
    //création de nouvelles matrices vide pour y mettre celles 
    //du fichier
    Matrice(U);
    Matrice(V);
    string mats("mesmatrices.txt");
    string somme("somme.txt");
    ifstream fichierentree(mats.c_str());
    ofstream fichiersortie(somme.c_str());
    U.read(fichierentree);
    V.read(fichierentree);
    Matrice W=U+V;
    W.write(fichiersortie);
}