#include <string>
#include <ostream>
#include<iostream>

class trajet {
    std::string nom;
    float distance, // en Km
    duree; // en mn
    public:
    trajet(std::string n, float di, float du);
    trajet();
    trajet(float du);
    void print();
    void modur(float delta);
    trajet ajout(float delta);
    trajet operator+(float delta);
    trajet operator+(const trajet& T);
};