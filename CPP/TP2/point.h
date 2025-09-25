#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Point{
    public :
        Point(float x=1., float y=2.);
        void affiche();
        ~Point();
        void translate(double vecX, double vecY);
    private : 
        float xP, yP;
};  