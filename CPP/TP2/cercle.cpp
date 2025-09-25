#include"cercle.h"

Cercle::Cercle(Point c, float r){
    centre=c;
    rayon=r;
};

Cercle::Cercle(float xc, float yc, float r){
    centre=Point(xc, yc);
    rayon=r;
};

void Cercle::translate_(float x1, float y1){
    centre.translate(x1, y1);  
};

Cercle& Cercle::translateR(float x1, float y1){
    centre.translate(x1, y1);   
    return *this;
}

Cercle Cercle::translateN(float x1, float y1){
    Cercle Cercle2=*this;
    Cercle2.centre.translate(x1, y1);
    return Cercle2;
};

void Cercle::affiche(){
    centre.affiche();
    cout<<"et le rayon est \t"<< rayon <<endl;
};