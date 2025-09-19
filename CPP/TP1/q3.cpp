#include "point.h"

int main(){
    Point MonPoint(2, 3);
    Point MonPoint2(4,5);
    Point* coordos=&MonPoint;

    int coordo1=coordos->fonc1();
    int coordo2=coordos->fonc2();
    MonPoint.affiche();//affichage de mon point
    MonPoint.affichePointRef();//affichage point réf
    MonPoint.modPointRef(3.14, 3.15);//modification du point
    MonPoint.affichePointRef();//affichage du nouveau point réf
    MonPoint.translate(1, 1);//translation
    MonPoint.affiche();//affichage après translation
    double distance = MonPoint.distance(MonPoint, MonPoint2);
    cout<<distance<<endl;
}

