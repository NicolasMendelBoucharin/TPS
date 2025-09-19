#include <iostream>
using namespace std;

int main(){
    cout<<"Bonjour"<<endl;
    double reel;
    int entier;
    cout<<"Donne moi un reel a manger"<<endl;
    cin>>reel;
    cout<<"Donne moi un entier a manger"<<endl;
    cin>>entier;
    double produit; 
    double somme;
    somme = entier + reel;
    produit = entier * reel;
    cout<<"La somme donne "<<somme<<" et le produit "<< produit<<endl;
}

