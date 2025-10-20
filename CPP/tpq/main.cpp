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
    cout<<sommereel<<produitreel<<endl;
}