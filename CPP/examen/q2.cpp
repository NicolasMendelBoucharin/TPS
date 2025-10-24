#include"groupe_bis.h"
int main(){
    Etudiant Divi=Etudiant("Sequin", "Divi", 2002, 3);
    Divi.affiche();
    groupe classe(3);
    classe.affiche();
    groupe classe2(2);
    classe2.modif(2, &Divi);
    classe2.affiche();
    groupe cl = classe + classe2;
    //j'ai une segmentation error et je ne sais pas pourquoi 
    cl.affiche();

}