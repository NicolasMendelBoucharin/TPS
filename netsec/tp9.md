# Partie 1 :

### Question 1 : 

Pour Nicolas : 192.168.1.20/24, pour Julie : 192.168.1.24/24,  pour Elouan : 192.168.1.23/24, pour Emmy : 192.168.1.13/24

### Question 2 : 

J'ai pu changer mon adresse en 192.168.1.34/24 avec la commande 

```
ip addr add 192.168.1.34/24 dev wlp2s0
```

### Question 3 :

Comme partout c'est 192.168.1.1

### Question 4 :

Une interface de connexion, mais il faut un mot de passe qu'on a trouvé

### Question 5 : 

fait

### Question 6 : 

fait

### Question 7 :

TODO : faire un diagramme 

On a réussi à faire une redirection de port vers ma machine (le changement de port au début n'a servi à rien)


## Partie II : 


### Question 8 :

dig ns  netsec2223.eu.org nous dit que le fournisseur est dynv6 sur les machines ns1,2,3.dynv6.com

### Question 9 :

Il demande d'abord à celui qui a .org puis .eu.org puis... 

### Question 10 :

On tape la commande suivante : 

```
curl \
    -H "Authorization: Bearer XCqXvdqJMWY1GEyCdcBZZWnwm4F6Ub" \
    -H "Accept: application/json" \
    https://dynv6.com/api/v2/zones
```

Et on a le retour suivant :

```
[{"name":"hackme.goessens.fr","ipv4address":"148.60.11.246","ipv6prefix":"","id":4507942,"createdAt":"2024-11-27T14:24:02+01:00","updatedAt":"2024-11-27T14:24:02+01:00"},
{"name":"netsec2223.eu.org","ipv4address":"148.60.11.246","ipv6prefix":"2001:db8:85a3::8a2e:370:7334","id":3582646,"createdAt":"2022-11-15T14:24:17+01:00","updatedAt":"2022-11-15T14:24:17+01:00"},
{"name":"tp10.goessens.fr","ipv4address":"","ipv6prefix":"","id":3941821,"createdAt":"2023-11-29T20:19:03+01:00","updatedAt":"2023-11-29T20:19:03+01:00"}]
```

L'id pour netsec2223.eu.org est 3582646

### Question 11 :

