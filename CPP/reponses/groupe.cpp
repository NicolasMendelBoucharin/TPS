#include"groupe.h"
using namespace std;

Etudiant groupe::etudVid;

groupe::groupe(){
    nbEtud=0;
};

groupe::groupe(int n){
    nbEtud=n;
    listEtud = new Etudiant* [nbEtud] ;
    for(int i=0; i<nbEtud; i++){
        listEtud[i]=&etudVid;
    }
    
}

void groupe::modif(int i, Etudiant* p_cetEtud){
    listEtud[i-1]=p_cetEtud;
}

void groupe::afficheNbEtud() const {
    cout<<"Nombre d'étudiant : "<<nbEtud<<endl;
}

void groupe::afficheEtud(int i) const {
    listEtud[i]->afficheNum();

}

void groupe::affiche() const {
    afficheNbEtud();
    for(int i=0; i<nbEtud; i++){
        afficheEtud(i); 

    }
}

groupe::~groupe(){
    delete [] listEtud;
}

groupe::groupe(const groupe& groupe1){
    
    nbEtud = groupe1.nbEtud;
    listEtud = new Etudiant* [nbEtud];
    for(int i=0; i<nbEtud; i++){
        listEtud[i];
    }
};

groupe& groupe::operator=(const groupe& groupe1) {
    if (nbEtud != groupe1.nbEtud) {
        delete [] listEtud;
        nbEtud = groupe1.nbEtud;
        listEtud = new Etudiant* [nbEtud];
    }
    for(int i=0; i<nbEtud; i++){
        listEtud[i]=groupe1.listEtud[i];
        
    }
    return *this;
};