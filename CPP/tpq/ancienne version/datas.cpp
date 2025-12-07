#include "qq.h"

int datas::getCorps(){
    return corps;
}

int datas::getTaille(){
    return taille;
}

int datas::getAlgo(){
    return algo;
}

double datas::getTolerance(){
    return tolerance;
}

void datas::read(std::ifstream& fichierdatas){
    fichierdatas>>corps;
    fichierdatas>>taille;
    fichierdatas>>algo;
    fichierdatas>>tolerance;
}

