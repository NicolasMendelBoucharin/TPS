#include "matrice4.h"

int main (void) {
	MatFull Af(2,3);
   Matrice *pAf = &Af;
   pAf->init(1.);
   pAf->affiche("Af");
   
	MatFull Bf(2,3);
   Matrice *pBf = &Bf;
   pBf->init(2.);
   pBf->affiche("Bf");
   
   MatFull Cf(Af);
   Cf.affiche("Cf(Af)");
   
   MatFull Df;
   Df=Af+Bf;
   Df.affiche("Df=Af+Bf");

	MatSym As(3);
   Matrice *pAs = &As;
   pAs->init(1.);
   pAs->affiche("As");
   
	MatSym Bs(3);
   Matrice *pBs = &Bs;
   pBs->init(2.);
   pBs->affiche("Bs");
   
   std::cout<<"prout"<<std::endl;
   MatSym Cs(As);
   Cs.affiche("Cs(As)");
   
   MatSym Ds;
   Ds=As+Bs;
   Ds.affiche("Ds=As+Bs");
}
