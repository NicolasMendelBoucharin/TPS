#include<iostream>
#include<cassert>
#include<cmath>
#include <fstream>
#include <iostream>
#include <string>



class Matrice{

protected:
    bool sym;
    double **val;

public:
    virtual void affiche(std::string nom);
    virtual void init(double d);
    virtual Matrice operator+(const Matrice&);
    virtual Matrice& operator=(const Matrice& mat);
    // void read(std::ifstream& fichierentree);
    // void write(std::ofstream& fichiersorite);
    double operator()(int i, int j); 
};



class MatFull:public Matrice{
private:
    int nbl;
    int nbc;
public:
    void affiche(std::string nom);
    void init(double d);
    MatFull(int nl, int nc);
    MatFull();
    MatFull(const MatFull& mat);
    ~MatFull();
    MatFull operator+(const MatFull&);
    MatFull& operator=(const MatFull& mat);
    double* operator[](int i);
};

class MatSym:public Matrice{
private:
    int taille;
public:
    MatSym(int n);
    MatSym(const MatSym&);
    MatSym();
    void affiche(std::string nom);
    void init(double d);
    ~MatSym();
    MatSym operator+(const MatSym&);
    MatSym& operator=(const MatSym& mat);
};