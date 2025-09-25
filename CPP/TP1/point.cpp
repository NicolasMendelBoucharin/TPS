#include "point.h"

Point Point::PointRef(3.14, 3.14); //initialisation d'un point de référence

Point::Point(double entier1, double entier2){
    xP= entier1;
    yP=entier2;
}; //constructeur

Point::Point(){
    xP = 1;
    yP=2;
}; //constructeur surchargé sans argument

double Point::fonc1(){
    return Point::xP;
};//donne la première coordonnée

double Point::fonc2(){
    return Point::yP;
};//donne la deuxième coordonnée

void Point::affiche(){
    cout<<"("<<Point::xP<<","<<Point::yP<<")"<<endl;
};//affiche les coordonnées

void Point::affichePointRef(){
    double xRef = Point::PointRef.xP;
    double yRef= Point::PointRef.yP;
    cout<<"("<<xRef<<","<<yRef<<")"<<endl;
};

void Point::modPointRef(double newX, double newY){
    Point::PointRef.xP=newX;
    Point::PointRef.yP=newY;
    assert(Point::ok());
};

void Point::translate(double vecX, double vecY){
    Point::xP += vecX;
    Point::yP += vecY;
    assert(Point::ok());
};

bool Point::ok(){
    return Point::xP >= 0 and Point::yP >= 0;
};

double Point::distance(Point point1, Point point2){
    return sqrt(pow((point1.yP - point2.yP),2)+ pow((point1.xP - point2.xP),2));
};

Bipoint::Bipoint(Point pointt1, Point pointt2){
    point1 = pointt1;
    point2 = pointt2;
};



void Bipoint::affiche(){
    Bipoint::point1.affiche();
    Bipoint::point2.affiche();
}



