#include "point.h"

Point::Point(float x, float y){
    xP=x;
    yP=y;
    cout<<"creation du point \t"<<this<<endl;
}

void Point::affiche() {
    cout << "x=\t" << this->xP << ", \t y=\t" << this->yP << endl; //pour accèder à xp et yp on est obligé du this ? 

}

Point::~Point(){
    cout<<"destruction du point \t"<<this<<endl;
};

void Point::translate(double vecX, double vecY){
    Point::xP += vecX;
    Point::yP += vecY;
};