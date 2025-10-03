9.b) 

La façon la plus simple me semble être la surcharge d'opérateur car la plus intuitive on peut directement déclarer 

```{
    Vect W=U+V
}

Alors que avec la méthode add il faut d'abord déclarer un vecteur auquel on va ensuite asssigner les valeurs de la somme.

9.c)

Quand on fait l'opération le programme convertit le int n en vecteur de taille n. Parce que il appelle le constructeur qui mange un int.

Pour contrer ça on met un explicit.