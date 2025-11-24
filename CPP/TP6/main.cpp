#include "TP6.h"
#include <map>
using namespace std;
int main(){
    std::vector<int> A(10, 1);
    std::vector<double> B(15, 3.14);
    affiche(B, 5);
    std::vector<double> C(10);
    std::vector<std::vector<double>> M;
    M=matricemake(4, 5, 2);
    matriceaffiche(M);
    cout<<M[2][3]<<endl;
    M[2][3]=4;
    matriceaffiche(M);


    std::map<int, string> erreurs;

    erreurs[0] = "pas assez de swag";
    erreurs[1] = "Division par zero";
    erreurs[2] = "Indice hors limites";
    erreurs[3] = "Fichier introuvable";
    erreurs[4] = "segfault";
    erreurs[5] = "fin du fichier";

    // Parcours de toutes les paires clé / message
    for (auto it = erreurs.begin(); it != erreurs.end(); ++it) {
        cout << "Erreur " << it->first << " : " << it->second << endl;
    }


}