#include "trajet.h"
using namespace std;

int main(){
    string nom="Rennes-Paris";
    float du = 110;
    float di = 349; 
    trajet T = trajet(nom, di, du);
    T.print();
    trajet T2 = T.ajout(10);
    T2.print();
    
}