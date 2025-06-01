# AES

## Description : 

Programme permettant de déchifrer ou chiffrer en ECB avec une clé fixée

### Utilisation : 

- une fois le fichier compilé le binaire est dans le dossier bin et peut être exécuté avec les commandes make et AES
- on peut afficher une aide avec AES --help 
- on peut faire un test avec AES --test
 

## Difficultés rencontrés : 

**GROS PROBLEME :** Je m'y suis pris vraiment tard avec les partiels/rendus/projet et le retour chez mes parents ce week-end ça a été compliqué... et je pense que j'ai vraiment mal fait ma fonction KeyExpension et que mon chiffrement n'est pas bon. Néanmoins ce que je chiffre je peux toujours le déchiffrer et revenir au bloc initial.

Je pense que j'aurais du faire autre chose que une liste de byte pour le "w" dans Key_Extension

J'ai également un gros problème avec mon parser d'argument je n'arrive pas à lui faire lire les fichiers en paramètre. En tout cas il crée bien un fichier mais vide quand je chiffre ou déchiffre

On m'a honnetement beaucoup aidé pour le parsing de fichier pour avoir un padding qui fonctionne 

25 secondes ça me parait long pour le test

Au début j'avais mis mes "states" non pas comme des matrices 4,4 mais comme une 16-list et c'était beaucoup plus compliqué au final pour pas mal de fonctions.

(C'est ma faute de m'y être pris si tard et j'entends que ma note sera celle du travail rendu pour la deadline. Cependant si pour vous il est nécessaire que je finisse mieux le projet pour le m2 je peux m'en occuper plus tard pendant l'été.)