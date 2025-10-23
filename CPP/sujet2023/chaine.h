#include<iostream>

class chaine {
int lc;
char * c;
public:

    chaine(const char tab[], int nbcar=0);
    ~chaine();
    void print();
    chaine();
    chaine(const chaine& chain);
    
};