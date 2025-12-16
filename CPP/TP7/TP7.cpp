#include "TP7.hpp"
using namespace std;
template class Vec<double>;
template class Vec<int>;
template class Vec<std::string>;


template<class C>
void Vec<C>::init(C d){
    for(int i=0; i<this->size(); i++){
        (*this)[i]=d;
    }
}

template<class C>
void Vec<C>::modif(int i, C d){
    (*this)[i] = d;
}

template<class C>
void Vec<C>::affiche(){
    cout<<"( ";
    for(int i=0; i<this->size(); i++){
        cout<<(*this)[i]<< " ";
    }
    cout<<")"<<endl;
}

template<class C>
Vec<C> Vec<C>::operator+(const Vec& U){
    int taille=U.size();
    if (taille<(this->size())){
        cout<<"Warning : Le vecteur de gauche était plus long que celuide droite"<<endl;
    }
    if (taille>(this->size())){
        cout<<"Warning : Le vecteur de droite était plus long que celui de gauche"<<endl;
    }
    Vec<C> Res = Vec<C>(taille);
    for(int i=0; i<taille; i++){
        Res[i]=(*this)[i]+U[i];
    }
    return Res;
}

Integ::Integ(methode met){
    this->met = met;
}

double Integ::computerec(double a, double b, int nbsub, double (*f)(double)){
    double res;
    res = 0;
    double x=a;
    double dx=(b-a)/nbsub;
    for (int k=0; k<nbsub; k++){
        res += f(x) * dx;
        x+=dx;
    }
    return res;
}

double Integ::computetrap(double a, double b, int nbsub, double (*f)(double)){
    double res;
    res = ((b-a)/nbsub) * (f(a) + f(b)) /2 ;
    double somme = 0; 
    for(int k=1; k<nbsub; k++){
        somme += f(a+k*(b-a)/nbsub);
    }
    res += ((b-a)/nbsub) * somme;
    return res;
}

double Integ::compute(double a, double b, int nbsub, double (*f)(double)){
    double res;
    switch (met)
    {
    case trapezes:{
        res = ((b-a)/nbsub) * (f(a) + f(b)) /2 ;
        double somme = 0; 
        for(int k=1; k<nbsub; k++){
            somme += f(a+k*(b-a)/nbsub);
        }
        res += ((b-a)/nbsub) * somme;

        break;
    }
    case rectangles:{
        res = 0;
        double x=a;
        double dx=(b-a)/nbsub;
        for (int k=0; k<nbsub; k++){
            res += f(x) * dx;
            x+=dx;
        }
        break;
    }
    default:
        break;
    }
    return res;
};



double puissance4(double x){
        return pow(x, 4);
    }