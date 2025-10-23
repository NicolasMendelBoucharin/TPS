#include "trajet.h"
using namespace std;

trajet::trajet(std::string n, float di, float du){
    nom= n;
    distance= di;
    duree=du;
}

trajet::trajet(){
    nom="";
    distance=0;
    duree=0;
}

void trajet::print(){
    cout<<nom<< " : "<<distance<<" Km, "<<duree<<"mn"<<endl;
}

void trajet::modur(float delta){
    duree+=delta;
}

trajet trajet::ajout(float delta){
    return (trajet(nom, distance, duree+delta));
}

trajet trajet::operator+(float delta){
    return (trajet(nom, distance, duree+delta));
}

trajet trajet::operator+(const trajet& T){
    return(trajet(nom+T.nom, distance+T.distance, duree+T.duree));
}

trajet::trajet(float du){
    nom="";
    distance=0;
    duree=du;
}

