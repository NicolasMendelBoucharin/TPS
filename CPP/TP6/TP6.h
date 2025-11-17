#include <iterator>
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
        void affiche(vector<double> &V, int n);
        void affiche(vector<double> &V );
        //Vec(const Vec&);
        //Vec& operator=(const Vec&);
        //friend int getlg(const Vec& U);
        Vec operator+(const Vec& U);
        //void add(const Vec& A, const Vec& B);
        //~Vec();
        vector<double> readfromfile(std::ifstream& fichierentree);
        vector<double> readfromfile2(std::ifstream& fichierentree);
        void somme(vector<double> A, vector<double> B, vector<double> C);
};

