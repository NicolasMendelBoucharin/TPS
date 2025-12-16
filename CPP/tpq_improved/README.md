# TPQ - Résolution de Systèmes Linéaires (Version Améliorée)

## 📖 Description

Ce projet résout des systèmes linéaires de la forme **AX = B** en utilisant trois algorithmes :
- **Élimination de Gauss** avec pivot partiel
- **Décomposition LU** avec pivot partiel  
- **Descente de Gradient** itérative

Le projet supporte deux types de nombres :
- **`double`** : nombres à virgule flottante (précision machine)
- **`qq`** : fractions exactes (rationnels p/q)

---

## 🏗️ Architecture

### Structure du Projet
```
tpq_improved/
├── Makefile                      # Compilation
├── RAPPORT_AMELIORATIONS.md      # Détail des corrections
├── README.md                     # Ce fichier
├── include/                      # Headers
│   ├── datas.hpp                # Lecture configuration
│   ├── matrice.hpp              # Classe Matrice<C>
│   ├── qq.h                     # Classe qq (rationnels)
│   └── vect.hpp                 # Classe Vect<C>
├── src/                         # Implémentations
│   ├── datas.cpp
│   ├── main.cpp
│   ├── matrice.cpp
│   ├── qq.cpp
│   └── vect.cpp
├── obj/                         # Fichiers objets compilés
└── test_files/                  # Fichiers de test
```

### Classes Principales

#### `datas`
Stocke la configuration du test :
- Type de corps (qq ou double)
- Taille de la matrice
- Algorithme à utiliser
- Tolérance (pour gradient)

#### `Vect<C>`
Vecteur dynamique template :
- Allocation/désallocation automatique
- Opérations : +, -, produit scalaire, produit externe
- Accès sécurisé avec vérification de bornes

#### `Matrice<C>`
Matrice carrée template :
- Allocation/désallocation 2D
- Opérations : +, *, déterminant
- Solveurs : Gauss, LU, Gradient
- Calcul AX - B

#### `qq`
Nombre rationnel (p/q) :
- Réduction automatique
- Opérations arithmétiques (+, -, *, /)
- Comparaisons (>, <, ==)
- Conversion en double

---

## 🛠️ Compilation

### Compiler le projet
```bash
cd tpq_improved
make all
```

Cela génère l'exécutable `resolution`.

### Options de compilation
```bash
# Compiler en mode debug avec symboles
make CXXFLAGS="-std=c++17 -Wall -Wextra -g"

# Nettoyer les fichiers compilés
make clean

# Recompilation complète
make rebuild

# Générer les dépendances
make depend

# Afficher l'aide
make help
```

---

## 📊 Utilisation

### Format des fichiers

#### Fichier de données (4 lignes)
```
<corps> <taille> <algo> <tolerance>
```
Exemple :
```
1 3 0 0.001
```
- `1` : utiliser des doubles (0 pour qq)
- `3` : matrice 3×3
- `0` : élimination de Gauss (1 pour LU, 2 pour Gradient)
- `0.001` : tolérance pour gradient (ignorée pour Gauss/LU)

#### Fichier matrice (n×n réels)
```
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0
```

#### Fichier vecteur (n réels)
```
1.0
2.0
3.0
```

#### Fichier rationnels (format: num/den)
Pour `qq`, les nombres se lisent comme deux entiers :
```
1 2
3 4
5 6
```
Représente 1/2, 3/4, 5/6.

### Exemple d'exécution

```bash
./resolution data_double_gauss.txt matrice_double.txt vecteur_double.txt
```

Output :
```
========== Résolution avec des DOUBLES ==========

Matrice lue :
Matrice (3x3):
(1, 2, 3)
(4, 5, 6)
(7, 8, 9)
Vecteur lu : (1, 2, 3)

Algorithme : Elimination de Gauss
Solution X (Gauss) : (...)
Erreur ||AX - B||² : 1.23e-15
```

---

## 🧪 Fichiers de Test

Des fichiers de test sont fournis dans `test_files/` :
- `data_100_double_gauss.txt`
- `data_100_double_grad.txt`
- `data_100_double_LU.txt`
- `data_100_qq_gauss.txt`
- `data_100_qq_grad.txt`
- `data_100_qq_LU.txt`
- `matrice_double_100.txt`, `vecteur_double_100.txt`
- `matrice_qq_100.txt`, `vecteur_qq_100.txt`

### Lancer un test
```bash
./resolution test_files/data_100_double_gauss.txt \
             test_files/matrice_double_100.txt \
             test_files/vecteur_double_100.txt
```

---

## 🔍 Algorithmes

### Élimination de Gauss
- **Complexité** : O(n³)
- **Stabili** : Pivot partiel
- **Précision** : Excellente pour doubles, exacte pour qq

```
Ax = b  →  [U|y]  →  x par substitution arrière
         Pivots
```

### Décomposition LU
- **Complexité** : O(n³)
- **Avantage** : Peut résoudre plusieurs systèmes rapidement
- **Formule** : A = LU → Ly = b → Ux = y

### Descente de Gradient
- **Complexité** : O(n² × iterations)
- **Meilleur pour** : Matrices creuses, grands systèmes
- **Convergence** : Garantie si A est SPD (Symétrique Définie Positive)
- **Formule** : x_{k+1} = x_k + α_k * r_k

```
α_k = <r_k, r_k> / <r_k, A*r_k>
r_{k+1} = r_k - α_k * A*r_k
```

---

## ⚠️ Gestion des Erreurs

Le programme gère les cas suivants :

### Erreurs d'ouverture fichier
```
ERREUR : Impossible d'ouvrir le fichier : data.txt
```

### Erreurs de lecture
```
ERREUR : Erreur lors de la lecture du fichier de données
```

### Matrice singulière
```
Avertissement: pivot zéro à la position 2
```

### Tailles incompatibles
```
ERREUR : Taille du vecteur incompatible avec la matrice
```

### Indice hors limites
```
ERREUR : Index hors limites
```

---

## 📝 Exemples de Code

### Utilisation de la classe `qq`
```cpp
#include "qq.h"

qq a(1, 2);      // 1/2
qq b(3, 4);      // 3/4
qq c = a + b;    // 5/4

c.reduction();   // c = 5/4
cout << c;       // Affiche : 5/4

double d = (double)c;  // Conversion : 1.25
```

### Utilisation de Vect et Matrice
```cpp
#include "vect.hpp"
#include "matrice.hpp"

Matrice<double> A(3);
Vect<double> B(3);

A.read(fichier_matrice, 3);
B.read(fichier_vecteur, 3);

Vect<double> X = A.gauss(B);
X.affiche();  // Affiche la solution

Vect<double> AX = A.produit_matrice_vecteur(X);
double erreur = AX.difference_norme(B);
```

---

## 🐛 Problèmes Corrigés

Cette version corrige **12 problèmes** de la version originale :

| Problème | Statut |
|----------|--------|
| Bug gauss() - swap incorrect | ✅ Corrigé |
| Fichiers non fermés | ✅ Corrigé |
| Pas de vérification ouverture | ✅ Corrigé |
| Bug qq::pow() | ✅ Corrigé |
| Variables inutiles | ✅ Supprimées |
| Pas de try-catch | ✅ Ajouté |
| Absence vérifications bornes | ✅ Ajouté |
| Boucle infinie possible | ✅ Limitée |
| Pas d'auto-affectation check | ✅ Ajouté |
| Type générique mal utilisé | ✅ Corrigé |
| Pas de documentation | ✅ Complète |
| Makefile minimal | ✅ Amélioré |

Voir `RAPPORT_AMELIORATIONS.md` pour les détails.

---

## 📋 Spécifications

- **Langage** : C++17
- **Compilateur** : g++ 7.0+
- **Librairies** : Standard (iostream, fstream, cmath, stdexcept)
- **OS** : Linux, macOS, Windows (avec MinGW)

---

## 👨‍💻 Améliorations Futures Possibles

1. **Matrices creuses** : Utiliser des formats compacts (CSR, COO)
2. **Parallélisation** : OpenMP pour les boucles coûteuses
3. **Tests unitaires** : Framework Google Test
4. **Validation d'entrée** : Parser robuste pour fichiers
5. **Visualisation** : Graphiques d'erreur/convergence
6. **Approx.itérative** : GMRES, Bi-CGSTAB pour matrices mal-conditionnées

---

## 📄 License

Code pédagogique - Libre d'utilisation

---

## 📞 Support

Pour questions ou problèmes :
1. Vérifier le format des fichiers d'entrée
2. Consulter les messages d'erreur du programme
3. Lire `RAPPORT_AMELIORATIONS.md` pour problèmes courants
4. Recompiler avec `make clean && make all`

---

**Version** : 2.0 (Améliorée)  
**Date** : Décembre 2025  
**Status** : Production-ready ✅
