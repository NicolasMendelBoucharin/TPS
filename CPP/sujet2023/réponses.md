## Partie I 

### 1)

La commande est utile. L'opérateur :: s'appelle opérateur de résolution de portée.

Oui c'est un appel à la librairie

### 2) 

non par défaut les classes ont toutes leurs données en privé.

```bash
g++ p12.c++
```

Aucune idée

### 3)

```bash
g++ p13.c++ trajet.cpp
```
Il va chercher notre fonction trajet(nom, machin , truc) plutot que celui par défaut q'uil faut alors redéfinir en public

### 9) 

impossible sans le fichier 

### 10) 

pareil

### 11)

je fais un constructeur qui transforme un float en "" 0 float


## Partie II

### 2)

Le destructeur est nécessaire car sur le tableau la mémoire est alloué dynamiquement.

### 3) 

J'ai un message free(): double free detected in tchache 2
abandoncoredumped

il faut créer un constructeur par copie car là on ne faisiat pas une copie en profondeur et on essayait de détruire de fois la même chose.

### Partie III

### 1)

