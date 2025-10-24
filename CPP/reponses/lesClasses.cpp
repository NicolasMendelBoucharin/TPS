#include "lesClasses.h"
using namespace std;

Etudiant::Etudiant(std::string leNom, std::string lePrenom, int anneeN, int numEtud){
    nom=leNom;
    prenom=lePrenom;
    anneeNaissance=anneeN;
    numEtudiant=numEtud;

};

void Personne::afficheNomPrenom() const{
    cout<<"Nom : "<<nom<<endl;
    cout<<"Prénom : "<<prenom<<endl;
}
void Personne::afficheAnn() const{
    cout<<"Année Naissance : "<< anneeNaissance<<endl;
}
void Etudiant::afficheNum() const{
    cout<<"Numéro Etudiant : "<<numEtudiant<<endl;
}

void Etudiant::affiche() const{
    afficheNomPrenom();
    afficheAnn();
    afficheNum();

}

void Personne::affiche(){
    afficheNomPrenom();
    afficheAnn();
};