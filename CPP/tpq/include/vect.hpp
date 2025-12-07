#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>
#include <fstream>

template<class C>
class Vect{

    private:
    int lg;
    C* val;

    public:

    void init(C d);
    void affiche();
    void modif(int i, C r);
    explicit Vect(int n=0);
    Vect(const Vect&);
    Vect& operator=(const Vect&);
    Vect operator+(const Vect& U);
    void add(const Vect& A, const Vect& B);
    void scal(const Vect& A, const Vect& B);
    ~Vect();
    void read(std::ifstream& fichiermatrice, int n);
};

#endif // VECT_HPP
