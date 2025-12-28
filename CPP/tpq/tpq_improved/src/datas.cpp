#include "datas.hpp"
#include <iostream>

/**
 * @brief Getter pour le type de corps
 * @return 0 = qq (rationnels), 1 = double
 */
int datas::getCorps() const {
    return corps;
}

/**
 * @brief Getter pour la taille de la matrice
 */
int datas::getTaille() const {
    return taille;
}

/**
 * @brief Getter pour l'algorithme à utiliser
 * @return 0 = Gauss, 1 = LU, 2 = Gradient
 */
int datas::getAlgo() const {
    return algo;
}

/**
 * @brief Getter pour la tolérance
 */
double datas::getTolerance() const {
    return tolerance;
}

/**
 * @brief Lit les données depuis un fichier
 * @details Lecture : corps, taille, algo, tolerance
 * @throws std::runtime_error si la lecture échoue
 */
void datas::read(std::ifstream& fichierdatas) {
    if (!fichierdatas.is_open()) {
        throw std::runtime_error("Fichier de données non ouvert");
    }
    
    if (!(fichierdatas >> corps >> taille >> algo >> tolerance)) {
        throw std::runtime_error("Erreur lors de la lecture du fichier de données");
    }
    
    // Validation basique des données
    if (taille <= 0) {
        throw std::invalid_argument("La taille doit être positive");
    }
    if (tolerance < 0) {
        throw std::invalid_argument("La tolérance doit être positive");
    }
}
