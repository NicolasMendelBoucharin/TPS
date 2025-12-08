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

    int corps = d.getCorps(); // 0 = qq, 1 = double
    int taille = d.getTaille();
    int algo = d.getAlgo(); // 0 = gauss, 1 = LU, 2=Gradient
    double tolerance = d.getTolerance();

    if (corps == 1) { //cas des doubles
        //ecritures des fichiers dans des matrices vect et datas
        Matrice<double> A(taille);
        Vect<double> B(taille);
        A.read(fichier_matrice, taille);
        B.read(fichier_vecteur, taille);
        
        if(taille<10){
            cout << "Matrice lue :" << endl;
            A.affiche(); //J'ai fait ça sinon c'est horrible dans le terminal
            cout << "Vecteur lu : ";
            B.affiche();
        }
        
        Vect<double> X;
        if (algo == 0) {//cas de l'algo de gauss
            X = A.gauss(B);
            cout << "Solution X (Gauss) : ";
        } else if (algo == 1) { //cas de l'algo LU
            X = A.solveLU(B);
            cout << "Solution X (LU) : ";
        } else { //cas gradient
            X = A.descente_de_gradient(B, tolerance);
            cout << "Solution X (Gradient) : ";
        }
        X.affiche();
        // Vérification d'erreur de AX - B
        Vect<double> AX = A.produit_matrice_vecteur(X);
        double erreur = AX.difference_norme(B);
        cout << "Erreur ||AX - B||² : " << erreur << endl;
    } else if (corps == 0) { //cas des rationnels
        //ecritures des fichiers dans des matrices vect et datas
        Matrice<qq> A(taille);
        Vect<qq> B(taille);
        A.read(fichier_matrice, taille);
        B.read(fichier_vecteur, taille);
        
        if(taille<10){
            A.affiche(); //J'ai fait ça sinon c'est horrible dans le terminal
            cout << "Matrice lue (qq) :" << endl;
            cout << "Vecteur lu (qq) : ";
            B.affiche();
        }
       
        Vect<qq> X;
        if (algo == 0) { //cas gauss
            X = A.gauss(B);
            cout << "Solution X (Gauss, qq) : ";
        } else if (algo == 1) { //cas LU
            X = A.solveLU(B);
            cout << "Solution X (LU, qq) : ";
        } else { //cas gradient
            
            X = A.descente_de_gradient(B, tolerance);
            cout << "Solution X (gradient, qq) : ";
        }
        X.affiche();
        // Vérification d'erreur de AX - B
        Vect<qq> AX = A.produit_matrice_vecteur(X);
        double erreur = AX.difference_norme(B);
        cout << "Erreur ||AX - B||² : " << erreur << endl;
        
    } else {
        cout << "Corps non supporté." << endl;
    }

    
}

