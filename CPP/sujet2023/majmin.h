#include "chaine.h"

class minus:public chaine{
    private:
    int lc;
    char * c;
    public:
    minus(const char tab[], int nbcar=0);

};

class majus:public chaine{
    private:
    int lc;
    char * c;
    public:
    majus(const char tab[], int nbcar=0);

};