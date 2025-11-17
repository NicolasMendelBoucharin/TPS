#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Vec : public std::vector<double>{
    public:
        void init(double d);
        void affiche();
        void modif(int i, double r);
        Vec(int n) : std::vector<double>(n){}
        //Vec(const Vec&);
        //Vec& operator=(const Vec&);
        //friend int getlg(const Vec& U);
        Vec operator+(const Vec& U);
        //void add(const Vec& A, const Vec& B);
        //~Vec();
};
