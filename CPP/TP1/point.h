#include<iostream>
#include<cassert>
#include<cmath>

using namespace std;

class Point{
    private:
        double xP;
        double yP;
        static Point PointRef;
    public:
        Point(double entier1, double entier2);
        Point();
        double fonc1();
        double fonc2();
        void affiche();
        void affichePointRef();
        void modPointRef(double newX, double newY);
        void translate(double vecX, double vecY);
        bool ok();
        double distance(Point point1, Point point2);


};

class Bipoint{
    private:
        Point point1;
        Point point2;
    public:
        Bipoint(Point pointt1, Point pointt2);
        void affiche();
};


