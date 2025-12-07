#include "qq.h"
#include "datas.hpp"

/*Get pour accéder à la donnée membre corps*/
int datas::getCorps(){
    return corps;
}

/*Get pour accéder à la donnée membre taille*/
int datas::getTaille(){
    return taille;
}

/*Get pour accéder à la donnée membre du type d'algo choisi*/
int datas::getAlgo(){
    return algo;
}

/*Get pour accéder à la donnée membre de la tolérance*/
double datas::getTolerance(){
    return tolerance;
}

/*fonction de lecture du fichiers avec les données qui stocke dans la classe*/
void datas::read(std::ifstream& fichierdatas){
    fichierdatas>>corps;
    fichierdatas>>taille;
    fichierdatas>>algo;
    fichierdatas>>tolerance;
}
