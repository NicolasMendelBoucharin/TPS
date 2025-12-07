#ifndef DATAS_HPP
#define DATAS_HPP

#include <fstream>

class datas{
    private:
    int corps;
    int taille;
    int algo;
    double tolerance;
    
    public:
    int getCorps();
    int getTaille();
    int getAlgo();
    double getTolerance();
    void read(std::ifstream& fichierdatas);
};

#endif // DATAS_HPP
