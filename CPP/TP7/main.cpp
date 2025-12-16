#include "TP7.hpp"
#include <map>
using namespace std;

int main(){
    cout<<"==========Test pour les vecteurs========"<<endl;
    cout<<endl;

    Vec<int> A(10);
    A.init(1);
    cout<<"A un vecteur de int (10 * 1) :"<<endl;
    A.affiche();
    cout<<endl;
    Vec<double> B(15);
    B.init(3.14);
    cout<<"B un vecteur de double (15 * 3.14) :"<<endl;
    B.affiche();
    cout<<endl;
    Vec<double> C(15);
    C.init(6.7);
    cout<<"C un vecteur de double (15 * 6.7) :"<<endl;
    C.affiche();
    cout<<endl;
    Vec<double> somme = C+B;
    cout<<"somme de B et C :"<<endl;
    somme.affiche();
    cout<<endl;
    Vec<std::string> S(3);
    cout<<"S un vecteur de string (très mature) :"<<endl;
    S[0]="pipi";
    S[1]="caca";
    S[2]="prout";
    S.affiche();
    cout<<endl;

    cout<<"==========Test pour les intégales========"<<endl;
    cout<<endl;


    

//J'ai fait ça parce que je savais pas comment faire avec cmath
    
    //trapèzes 0 pi sin
    Integ integraletrap = Integ(trapezes);
    double miaou = integraletrap.compute(0, M_PI, 5, &sin);
    cout<<"Intégrale du sin entre 0 et pi par la méthode des trapèzes sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integraletrap.compute(0, M_PI, 10, &sin);
    cout<<"Intégrale du sin entre 0 et pi par la méthode des trapèzes sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //rectangles 0 pi sin 
    Integ integralerec = Integ(rectangles);
    miaou = integralerec.compute(0, M_PI, 5, &sin);
    cout<<"Intégrale du sin entre 0 et pi par la méthode des rectangles à gauche sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integralerec.compute(0, M_PI, 10, &sin);
    cout<<"Intégrale du sin entre 0 et pi par la méthode des rectangles à gauche sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //trapèzes 0 pi puissance 4
    miaou = integraletrap.compute(0, M_PI, 5, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et pi par la méthode des trapèzes sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integraletrap.compute(0, M_PI, 10, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et pi par la méthode des trapèzes sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //rectangle 0 pi puissance 4
    miaou = integralerec.compute(0, M_PI, 5, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et pi par la méthode des rectangles à gauche sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integralerec.compute(0, M_PI, 10, &puissance4);
    cout<<"Intégrale du x** 4 entre 0 et pi par la méthode des rectangles à gauche sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //trapèzes 0 2pi sin
    miaou = integraletrap.compute(0, 2*M_PI, 5, &sin);
    cout<<"Intégrale du sin entre 0 et 2pi par la méthode des trapèzes sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integraletrap.compute(0, 2*M_PI, 10, &sin);
    cout<<"Intégrale du sin entre 0 et 2pi par la méthode des trapèzes sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //rectange 0 2pi sin
    miaou = integralerec.compute(0, 2*M_PI, 5, &sin);
    cout<<"Intégrale du sin entre 0 et 2pi par la méthode des rectangles à gauche sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integralerec.compute(0, 2*M_PI, 10, &sin);
    cout<<"Intégrale du sin entre 0 et 2pi par la méthode des rectangles à gauche sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;


    //trapèzes 0 2pi puissance 4
    miaou = integraletrap.compute(0, 2*M_PI, 5, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et 2pi par la méthode des trapèzes sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integraletrap.compute(0, 2*M_PI, 10, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et 2pi par la méthode des trapèzes sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //rectange 0 2pi puissance4
    miaou = integralerec.compute(0, 2*M_PI, 5, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et 2pi par la méthode des rectangles à gauche sur 5 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    miaou = integralerec.compute(0, 2*M_PI, 10, &puissance4);
    cout<<"Intégrale de x**4 entre 0 et 2pi par la méthode des rectangles à gauche sur 10 intervales"<<endl;
    cout<<miaou<<endl;
    cout<<endl;

    //de grosses variations entres les méthodes et le nombre d'intervalles quand même pour le x**4







}