#include "qq.h"
#include "vect.hpp"
#include "matrice.hpp"
#include "datas.hpp"

using namespace std;

//parser d'arguments pour le programme final
int main(int argc, char* argv[]){
    
    // --- Vérification des arguments de ligne de commande ---
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <fichier_donnees.txt> <fichier_matrice.txt> <fichier_vecteur.txt>" << std::endl;
        std::cerr << "Exemple: " << argv[0] << " data_double_gauss.txt matrice_double.txt vecteur_double.txt" << std::endl;
        return 1;
    }
    
    //leture des fichiers
    std::ifstream fichier_data(argv[1]);
    std::ifstream fichier_matrice(argv[2]);
    std::ifstream fichier_vecteur(argv[3]);
    datas d;
    d.read(fichier_data);

    int corps = d.getCorps(); // 0 = double, 1 = qq
    int taille = d.getTaille();
    int algo = d.getAlgo(); // 0 = gauss, 1 = LU

    if (corps == 0) { //cas des doubles
        //ecritures des fichiers dans des matrices vect et datas
        Matrice<double> A(taille);
        Vect<double> B(taille);
        A.read(fichier_matrice, taille);
        B.read(fichier_vecteur, taille);
        cout << "Matrice lue :" << endl;
        A.affiche();
        cout << "Vecteur lu : ";
        B.affiche();
        Vect<double> X;
        if (algo == 0) {//cas de l'algo de gauss
            X = A.gauss(B);
            cout << "Solution X (Gauss) : ";
        } else { //cas de l'algo LU
            X = A.solveLU(B);
            cout << "Solution X (LU) : ";
        }
        X.affiche();
    } else if (corps == 1) { //cas des rationnels
        //ecritures des fichiers dans des matrices vect et datas
        Matrice<qq> A(taille);
        Vect<qq> B(taille);
        A.read(fichier_matrice, taille);
        B.read(fichier_vecteur, taille);
        cout << "Matrice lue (qq) :" << endl;
        A.affiche();
        cout << "Vecteur lu (qq) : ";
        B.affiche();
        Vect<qq> X;
        if (algo == 0) { //cas gauss
            X = A.gauss(B);
            cout << "Solution X (Gauss, qq) : ";
        } else { //cas LU
            X = A.solveLU(B);
            cout << "Solution X (LU, qq) : ";
        }
        X.affiche();
    } else {
        cout << "Corps non supporté." << endl;
    }

    
}

