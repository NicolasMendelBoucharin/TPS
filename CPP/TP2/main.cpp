#include "cercle.h"
//notebook :
//pas compris la question 3_c et la question 4.
int main(){
    /*
    int a = 5 ;
    int b = 10 ;

    double c=3.14;
    double d=2.5;
    float pi=3.14;
    int prod1 = prod(a, b);//produit de deux int
    double prod2= prod(c,d);// produit de deux double
    double prod1bis = prod(a,b);//produit de deux int vu comme double
    //double prodintdouble = prod(a, c); //ne marche pas 
    cout<<prod1<<endl;
    cout<<prod2<<endl;
    cout<<prod1bis<<endl;
    //cout<<prodintdouble<<endl;
    carre(&pi);
    cout<<pi<<endl;
    carre(pi);
    cout<<pi<<endl;
    */
    //à faire : les test de la question 5. créer une fonction affiche
    Cercle C=Cercle(0, 0, 3);
    C.affiche();
    //Cercle C1=C.translate_(1,1).translate_//pas possible car ne retourne rien
    Cercle C1 = C.translateR(1,1).translateR(2,2).translateR(3,3);
    C1.affiche();
    Cercle C2 = C.translateN(1,1).translateN(2,2).translateN(3,3);
    C2.affiche();
    //
}
