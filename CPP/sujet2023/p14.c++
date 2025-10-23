#include "trajet.h"
using namespace std;

int main(){
    string nom="Rennes-Paris";
    float du = 110;
    float di = 349; 
    trajet T = trajet(nom, di, du);
    T.print();
}