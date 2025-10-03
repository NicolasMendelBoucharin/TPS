#include "vect3.h"

int main(){
    Vect V=Vect(5);
    V.init(3.14);
    //il faut vraiment que je fasse les test là pour la questoin 9
    Vect U=Vect(5);
    U.init(5);
    cout<<"V="<<endl;
    V.affiche();
    cout<<"U="<<endl;
    U.affiche();
    // 9.a)
    Vect W;
    cout<<"Avec la surcharge d'operateur W=U+V="<<endl;
    W=U+V;
    W.affiche();
    
    

    //question 9.b);
    cout<<"Avec la fonction de copie W.add(V,U) on a :"<<endl;
    W.add(V, U);
    W.affiche();

    //question 9.c)

    /*
    int n=15;

    cout<<"En ajoutant un entier n à U on a un problème à cause du assert :"<<endl;
    Vect C=U+n;
    C.affiche();
    */

    //question 10)
    int deux=2;
    int trois=3;
    float pi=3.14;
    float deuxpi=6.28;
    double zerovirugle2=0.2;
    double zerovirgule5=0.5;

    cout<<prod( deux,  trois)<<endl;
    cout<<prodBis(zerovirgule5, pi)<<endl;




}



