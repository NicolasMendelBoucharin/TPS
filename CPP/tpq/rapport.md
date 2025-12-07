# README 

## Que fait le programme 

## Utilisation :


# Rapport 

## Ordre du travail

D'abord j'ai fait la classe qq en faisant en sorte que "tout fonctionne". C'est à dire les opérations de base, les affectations, les copies... Mais le gros de la classe j'ai du la remplir au fur et à mesure en fonction des besoins des autres classes. J'ai aussi dès le début fait en sorte que mes rationnels soient réduits à chaque opérations et que le signe soit uniquement porté par le numérateur

Après il a fallu une classe matrice que j'ai directement fait avec des fonctions de base et tout ce qu'il faut pour que la classe soit templaté intégralement. 

J'ai ensuite adapté ma classe vecteur des tps précédents pour la templater. Aux fonctions de base, j'ai aussi ajouté une fonction produit scalaire (qui ne m'a malheureusement pas servi).

Ensuite j'ai fait une fonction determinant avec les comatrices. J'ai eu des difficultés avec ce determinant car il a fallu templater le 0 ce qui m'a pris du temps.

J'ai fait le choix de préferer faire les fonctions de lecture de fichier avant de faire les algos. J'ai fait le choix de faire 3 classes pour les données vecteur et matrices quitte à devoir faire des get partout pour pouvoir les utiliser ailleurs. En faisant ainsi j'ai pu bien découper tout le travail et faire un code plus propre (j'espère).

J'ai ensuite fait les algos de gauss et LU avant de me concentrer sur le dernier car je voulais faire mon parser dans le Main et le tester avant de me lancer dans le dernier algo. 

Pour l'algorithme de gauss j'ai eu quelques problèmes décrits dans la section d'après (notamment le besoin de créer des getters et setters).

Une fois le pivot de gauss déjà fait, il suffisait de l'adapter pour le determinant, j'ai donc fait une autre fonction determinant qui utilise elle le pivot de gauss.

Comme les getters et les setters étaient déjà crées je les ai réutilisé pour certaines fonctions pour avoir un code plus propre.

J'ai donc ensuite fait un parser d'argument dans le main pour pouvoir selectionner les trois fichiers données, matrices et vecteur pour la résolution (pour l'instant j'ai choisi de faire en sorte que le résultat s'affiche simplement dans la console).

Une fois le parser fait, j'ai rajoué au makefile une option test qui va juste faire les tests avec des fichiers déjà dans mon dossier test_tiles.

## Difficulté :

J'ai du surchargé le abs et faire un "0" dans ma classe qq pour les determinants. De même pour le pivot de Gauss

De la même façon pour bien pouvoir lire et écrire les fichiers j'ai du surcharger les opérateur << et >> pour pouvoir bien faire l'écriture. J'ai par ailleurs du mettre ces surcharges en "friend" et je ne suis pas sûr que cela soit le mieux.

J'ai aussi du créer beaucoup de getter et setter pour simplifier les interactions entre les classes, notamment pour l'algorithme de Gauss qui avait besoin de beaucoup des données de deux classes différentes.


## Outils :

J'ai utilisé l'IA pour les algorithmes du determinant, de gauss, de LU, et pour la création du makefile.

## Amélioration possibles :

J'ai fait mes getters et setters après la majoritée de mes fonctions. Dès lors j'ai encore des fonctions qui utilisent plutot des accès directs aux valeurs. Corriger cela pourrait être interessant. Ce changement mériterait d'ailleurs d'être étendu aux vecteurs.

Il doit surement y avoir un moyen de surcharger les "<<" ">>" sans avoir à utiliser de friends.

On pourrait aussi rajouter un verbose et une option de output pour ne pas afficher simplement le résultat dans le terminal. 

Toujours dans cette optique de verbose on pourrait la vouloir partielle ou complete : Si la matrice est énorme on pourrait souhaiter de n'afficher que le resultat dans le terminal. 


