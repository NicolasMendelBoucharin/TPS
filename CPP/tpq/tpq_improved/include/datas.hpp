#ifndef DATAS_HPP
#define DATAS_HPP

#include <fstream>
#include <stdexcept>

/**
 * @class datas
 * @brief Classe pour lire et stocker les paramètres de configuration d'un test
 * 
 * Stocke : type de corps (qq ou double), taille, algo (Gauss, LU, Gradient), tolérance
 */
class datas {
private:
    int corps;           ///< Type de corps : 0 = qq, 1 = double
    int taille;          ///< Taille de la matrice
    int algo;            ///< Algorithme : 0 = Gauss, 1 = LU, 2 = Gradient
    double tolerance;    ///< Tolérance pour convergence

public:
    /**
     * Constructeur par défaut
     */
    datas() : corps(0), taille(0), algo(0), tolerance(0.0) {}

    /**
     * @brief Lit les données depuis un fichier
     * @param fichierdatas Flux de fichier ouvert
     * @throws std::runtime_error si la lecture échoue
     */
    void read(std::ifstream& fichierdatas);

    // Getters
    int getCorps() const;
    int getTaille() const;
    int getAlgo() const;
    double getTolerance() const;
};

#endif // DATAS_HPP
