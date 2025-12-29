# README - GGH

## Motivation

Le cryptosystème est défini ainsi :

$L$  est un réseau de rang plein en dimension n
La clé secrete est une "bonne" base $R$ de $L$ et la clé publique une "mauvaise" base $B$ de $L$

Un message $m\in Z^n$ est chiffré en posant $c=Bm+e$ où $e$ est aléatoire et suffisamment petit pour qu'on puisse le retrouver avec CVP dans la bonne base R.

Il faut que la mauvaise base soit trop peu orthogonale pour qu'on puisse résoudre correctement CVP.

## Utilisation

- On peut modifier le fichier /messages/message.txt pour y mettre un message court (moins de 200 caractères) et ensuite lancer le fichier messagecypher.sage pour le chiffrer puis le déchiffrer dans le même dossier
- Il y a aussi un fichier avec des tests pour les fonctions de base de mon fichier ggh.sage qui s'appelle ggh_test.sage
- Pareillement il y a un fichier cryptanalyse_test.sage
- On peut aussi changer en False le paramètre de sauvegarde des clés dans un fichier si on ne veux pas les sauvegarder.

## Construction du répertoire

- Un fichier ggh.sage avec une classe GGH pour le cryptosytème et des fonctions auxilliaires pour keygen, encrypt, decrypt.
- Un fichier gghIntoFile.sage pour les fonctions de lecture, sauvegarde et écriture de messages/clés
- Un fichier messagecypher.sage pour lire message.txt, le chiffrer et le déchiffrer.
- Un fichier cryptanalyse.sage avec des méthodes de cryptanalyse.
- des fichiers *_test.sage pour les tests.

## Choix et limitations

- Les papiers se contredisent un peu sur la dimension alors dans le doute j'ai prix le plus large c'est à dire $n=200$. Pareillement la documentation recommande de prendre sigma = 3, et de choisir la borne $M$ des messages comme $M=n$
- Pour la matrice unimodulaire de multiplication je fais "4 rounds" c'est ce que j'ai trouvé de plus optimal sur internet pour ne pas avoir des calculs qui explosent
- Il aurait sans doute fallu modifier mes fonctions TextToList et ListToText pour faire en sorte de respecter $M=200$ mais en ascii les caractères les plus utilisés en français sont de toute façon entre 0 et 200.
- On pourrait également faire un chiffrement "par blocs" pour les messages trop long et ne faire le padding que sur le dernier bloc du coup.
- J'ai voulu mettre le moins possible de fonctions dans la classe GGH pour pouvoir les appeler sans "tricher" dans la section cryptanalyse.
- On pourrait choisir de faire des "generate" en boucle jusqu'à avoir des bases avec les meilleurs ratio d'hadamard possible mais j'ai très rarement des erreurs sans.
- J'ai choisi de faire mon vecteur d'erreur d'une façon qui empèche l'attaque de Nguyen du livre directement (voir section problèmes.)

## Difficultés rencontrées

J'ai mis du temps à trouver comment faire les matrices unimodulaires suffisament complexes pour ne pas qu'on puisse faire LLL trop facilement et en même temps pas trop complexes pour que les calculs soient faisable

J'ai commencé par utiliser la fonction gram_schmidt() de sage et rien ne marchait en dimension grande. Avec ma version, plus de problème. Les temps de calculs sont beaucoup plus faible.

Une autre difficulté à été la lecture/écriture de fichier avec sagemath qui demande de tout passer en list avant de faire quoi que ce soit. J'ai utilisé une LLM pour cette partie estimant que ce n'était pas là l'essentiel du projet.

J'ai aussi mis beaucoup de temps à débugger ma cryptanalyse par embedding. Au final j'avais stack avant de augment...

Plus généralement c'était dûr de savoir sur quel papier se baser quand, j'ai donc préféré me concentrer uniquement sur le livre de cours plutot que la vrai documentation de 30 pages.

J'ai mis beaucoup de temps à comprendre comment fonctionnait l'attaque de NGuyens car elle ne s'applique pas dans ma version de GGH que j'avais déjà corrigé pour avoir une erreur à valeur dans $[-\sigma; \sigma]$ et pas dans $\{-\sigma;\sigma\}$.

En conséquence de la remarque précédente j'ai du créer une nouvelle classe BAD_GGH dans mon fichier cryptanalyse_test.sage avec le vecteur d'erreur corrigé. Malgré cela je n'ai pas eu le temps de faire l'attaque.