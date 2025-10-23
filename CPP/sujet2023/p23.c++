#include "chaine.h"

void fonc(chaine s){
s.print();
}

int main(){
chaine ch("blabla",3);
fonc(ch); 
ch.print();
}

