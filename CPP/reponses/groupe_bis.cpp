#include"groupe_bis.h"
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
        listEtud[i]=groupe1.listEtud[i];
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

groupe groupe::operator+(const groupe& groupe1){
    int nb=nbEtud+groupe1.nbEtud;
    groupe gr=groupe(nb);
    for(int i=0; i<nbEtud; i++){
        gr.listEtud[i]=listEtud[i];
    }
    for(int i=nbEtud; i<nb; i++){
        gr.listEtud[i]=listEtud[i];
    }
    return gr;
}