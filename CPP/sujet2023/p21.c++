#include "chaine.h"

int main(){
    char * c= new char [4];
    c[0]='c';
    c[1]='h';
    c[2]='a';
    c[3]='t';
    chaine ch = chaine(c, 2);
    ch.print();
}
