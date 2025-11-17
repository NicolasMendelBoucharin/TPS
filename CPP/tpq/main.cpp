#include "qq.h"
using namespace std;

int main(){
    qq r = qq(49, -7);
    r.affiche();
    qq s = qq(5,21);
    s.affiche();
    qq prod = r*s;
    prod.affiche();
    qq somme = r+s;
    somme.affiche();
    qq rprime = somme-s;
    rprime.affiche();
    qq rprimeprime = prod/s;
    rprimeprime.affiche();
    //double rdouble = r.converttodouble();
    //cout<<rdouble<<endl;
    //double proddouble = rdouble*s;
    s.affiche();
    qq power1 = s.pow(1);
    power1.affiche();
    qq power2 = s.pow(2);
    power2.affiche();
    qq powerinv = s.pow(-1);
    powerinv.affiche();
    double rr=s;
    cout<<rr<<endl;
    double sommereel = s + 3.14;
    double produitreel = s * 3.14;
    cout<<sommereel<<" "<<produitreel<<endl;

    Vect<double> Vdouble=Vect<double>(5);
    Vdouble.init(3.14);
    Vect<double> Udouble =Vect<double>(5);
    Udouble.init(5);
    cout<<"Vdouble="<<endl;
    Vdouble.affiche();
    cout<<"Udouble="<<endl;
    Udouble.affiche();
    // 9.a)
    Vect<double> Wdouble;
    cout<<"Avec la surcharge d'operateur Wdouble=Udouble+Vdouble="<<endl;
    Wdouble=Udouble+Vdouble;
    Wdouble.affiche();
    
    
    cout<<"Avec la fonction de copie Wdouble.add(Vdouble,Udouble) on a :"<<endl;
    Wdouble.add(Vdouble, Udouble);
    Wdouble.affiche();
    r=qq(1,3);
    Vect<qq> Vqq=Vect<qq>(5);
    Vqq.init(r);    
    Vqq.affiche();


    int n=5;
    Matrice<double> A = Matrice<double>(n);
    A.init(3.14);
    A.affiche();
    Matrice<double> B = Matrice<double>(n);
    B.init(5);
    B.affiche();
    Matrice<double> C(A);
    Matrice<double> D;
    D=A+B;
    C.affiche();
    D.affiche();

    n=6;
    Matrice<qq> Aqq = Matrice<qq>(n);
    r=qq(1,3);
    Aqq.init(r);
    Matrice<qq> Bqq = Matrice<qq>(n);
    s=qq(2,5);
    Matrice<qq> Cqq(Aqq);
    Matrice<qq> Dqq;
    Dqq=Aqq+Bqq;
    Aqq.affiche();
    Bqq.affiche();
    Cqq.affiche();
    Dqq.affiche();
    qq det= Dqq.Determinant();
    cout<<det<<endl;
    

}

