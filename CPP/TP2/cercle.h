#include "point.h"

class Cercle{
    private:
    Point centre;
    float rayon;
    public:
    Cercle(Point c, float r);
    Cercle(float xc, float yc, float r);
    void translate_(float x1, float y1);
    Cercle& translateR(float x1, float y1);
    Cercle translateN(float x1, float y1);
    void affiche();
};


