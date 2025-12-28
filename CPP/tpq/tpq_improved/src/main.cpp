#include "qq.h"
#include "vect.hpp"
#include "matrice.hpp"
#include "datas.hpp"

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Programme principal pour résoudre un système linéaire AX = B
 * 
 * Usage: ./programme <fichier_données> <fichier_matrice> <fichier_vecteur>
 * 
 * Le fichier de données contient : corps taille algo tolerance
 *   - corps : 0=qq (rationnels), 1=double
 *   - taille : dimensions n×n de la matrice
 *   - algo : 0=Gauss, 1=LU, 2=Gradient
 *   - tolerance : critère d'arrêt pour le gradient
 */
int main(int argc, char* argv[]) {

    // Vérification des arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] 
                  << " <fichier_donnees.txt> <fichier_matrice.txt> <fichier_vecteur.txt>" 
                  << std::endl;
        std::cerr << "Exemple: " << argv[0] 
                  << " data_double_gauss.txt matrice_double.txt vecteur_double.txt" 
                  << std::endl;
        return 1;
    }

    try {
        // Ouverture des fichiers
        std::ifstream fichier_data(argv[1]);
        std::ifstream fichier_matrice(argv[2]);
        std::ifstream fichier_vecteur(argv[3]);

        // Vérification que les fichiers se sont ouverts
        if (!fichier_data.is_open()) {
            throw std::runtime_error(string("Impossible d'ouvrir le fichier : ") + argv[1]);
        }
        if (!fichier_matrice.is_open()) {
            throw std::runtime_error(string("Impossible d'ouvrir le fichier : ") + argv[2]);
        }
        if (!fichier_vecteur.is_open()) {
            throw std::runtime_error(string("Impossible d'ouvrir le fichier : ") + argv[3]);
        }

        // Lecture des données de configuration
        datas d;
        d.read(fichier_data);

        int corps = d.getCorps();      // 0 = qq, 1 = double
        int taille = d.getTaille();
        int algo = d.getAlgo();        // 0 = gauss, 1 = LU, 2 = Gradient
        double tolerance = d.getTolerance();

        if (corps == 1) {  // Cas des doubles
            cout << "========== Résolution avec des DOUBLES ==========" << endl << endl;

            Matrice<double> A(taille);
            Vect<double> B(taille);
            A.read(fichier_matrice, taille);
            B.read(fichier_vecteur, taille);

            // Affichage pour les petites matrices
            if (taille < 10) {
                cout << "Matrice lue :" << endl;
                A.affiche();
                cout << "Vecteur lu : ";
                B.affiche();
                cout << endl;
            }

            Vect<double> X;
            
            if (algo == 0) {  // Gauss
                cout << "Algorithme : Elimination de Gauss" << endl;
                X = A.gauss(B);
                cout << "Solution X (Gauss) : ";
            } else if (algo == 1) {  // LU
                cout << "Algorithme : Décomposition LU" << endl;
                X = A.solveLU(B);
                cout << "Solution X (LU) : ";
            } else if (algo == 2) {  // Gradient
                cout << "Algorithme : Descente de Gradient" << endl;
                cout << "Tolérance : " << tolerance << endl;
                X = A.descente_de_gradient(B, tolerance);
                cout << "Solution X (Gradient) : ";
            } else {
                cerr << "Algorithme non reconnu : " << algo << endl;
                return 1;
            }
            
            X.affiche();
            cout << endl;

            // Vérification : calcul de AX - B
            Vect<double> AX = A.produit_matrice_vecteur(X);
            double erreur = AX.difference_norme(B);
            cout << "Erreur ||AX - B||² : " << erreur << endl;

        } else if (corps == 0) {  // Cas des rationnels
            cout << "========== Résolution avec des RATIONNELS (qq) ==========" << endl << endl;

            Matrice<qq> A(taille);
            Vect<qq> B(taille);
            A.read(fichier_matrice, taille);
            B.read(fichier_vecteur, taille);

            // Affichage pour les petites matrices
            if (taille < 10) {
                cout << "Matrice lue (qq) :" << endl;
                A.affiche();
                cout << "Vecteur lu (qq) : ";
                B.affiche();
                cout << endl;
            }

            Vect<qq> X;
            
            if (algo == 0) {  // Gauss
                cout << "Algorithme : Elimination de Gauss" << endl;
                X = A.gauss(B);
                cout << "Solution X (Gauss, qq) : ";
            } else if (algo == 1) {  // LU
                cout << "Algorithme : Décomposition LU" << endl;
                X = A.solveLU(B);
                cout << "Solution X (LU, qq) : ";
            } else if (algo == 2) {  // Gradient
                cout << "Algorithme : Descente de Gradient" << endl;
                cout << "Tolérance : " << tolerance << endl;
                X = A.descente_de_gradient(B, tolerance);
                cout << "Solution X (Gradient, qq) : ";
            } else {
                cerr << "Algorithme non reconnu : " << algo << endl;
                return 1;
            }
            
            X.affiche();
            cout << endl;

            // Vérification : calcul de AX - B
            Vect<qq> AX = A.produit_matrice_vecteur(X);
            double erreur = AX.difference_norme(B);
            cout << "Erreur ||AX - B||² : " << erreur << endl;

        } else {
            cerr << "Corps non supporté : " << corps << " (attendu 0 ou 1)" << endl;
            return 1;
        }

        // Fermeture des fichiers
        fichier_data.close();
        fichier_matrice.close();
        fichier_vecteur.close();

    } catch (const std::exception& e) {
        std::cerr << "ERREUR : " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Erreur inconnue" << std::endl;
        return 1;
    }

    return 0;
}
