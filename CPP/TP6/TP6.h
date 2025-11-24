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
        
        //Vec(const Vec&);
        //Vec& operator=(const Vec&);
        //friend int getlg(const Vec& U);
        Vec operator+(const Vec& U);
        //void add(const Vec& A, const Vec& B);
        //~Vec();   
};

void affiche(std::vector<double> &V, int n);
void affiche(std::vector<double> &V );
std::vector<double> readFromFile(std::ifstream& fichierentree);

template <class L, class I>
void somme(const std::vector<L> &A, const std::vector<I> &B, std::vector<L> &C);

std::vector<std::vector<double>> matricemake(int n, int m, double d=0);
void matriceaffiche(std::vector<std::vector<double>> &M);