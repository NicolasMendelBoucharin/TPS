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
    Vect operator+(const Vect& U) const;
    Vect operator-(const Vect& U) const;
    void add(const Vect& A, const Vect& B);
    C scal(const Vect& B);
    ~Vect();
    void read(std::ifstream& fichiermatrice, int n);
    C get(int i) const;
    void set(int i, C value);
    int size() const;
    Vect<C> produit_externe(C);
    C difference_norme(const Vect<C>& B);
};

#endif // VECT_HPP
