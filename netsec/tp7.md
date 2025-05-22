# TP 7 - Mounir Yamout - Nicolas Mendel-Boucharin

## Partie 1 : Simple routing

### Question 1 :

L’adresse ip du routeur est : 148.60.12.134/24

### Question 2 : 

L’adresse ip du client est : 148.60.12.131/24

### Question 3 :

Pour remplacer la default route du client par celle du routeur on commence par trouver cette adresse avec
la commande ip route. On obtient default via 148.60.12.254 dev eth0. On tape donc sudo ip route del
default via 148.60.12.254 dev eth0, puis sudo ip route add 148.60.12.134 dev eth0.

### Question 4 :

On ne peut pas accéder à internet. Le routeur reçoit bien du trafic mais ne le transmet pas à internet pour
des raisons de sécurité. L’addresse 254 s’occupait elle même de filtrer les paquets afin d’éviter les
problème de surcharge ou de sécurité, mais maintenant qu’on l’a remplacé par l’adresse du routeur, il n’ya
plus de travail de filtrage donc le routeur ne transmet plus rien à Internet.
La commande sysctl net.ipv4.ip_forward=1 modifie la valeur de ip_forward à 1. chaque valeur
correspond à des directives que prend le routeur pour laisser passer ou non des paquets. La valeur était à
0 donc ne laissez rien passer. 1 (et toute autre valeur non-nulle) laisse tout passer.

## Partie 2 : 

### Question 5 :

Le filtre marche très bien pour le routeur. 


### Question 6 :

En revanche, on arrive tout de même a ping 8.8.8.8 avec le client. C’est parce que les paquet envoyé
depuit le routeur passe par input puis outpout avant d’être transferré, tandis que tout ce qui passe par le
routeur mais vient d’ailleurs va passer par forward.

### Question 7 : 

En remplaçant le outpout de la commande par un forward, le filtrage devient operationnel pour le client

## Partie 3 :

### Question 8 :

Avant éxecution des commandes, l’adresse ip par laquelle on se connecte est celle du client ?
Après execution, l’adresse ip devient celle du routeur. Donc cette commande permet de modifier l’adresse
avec laquelle on se conncete.

## Partie 4 : 

## Partie 5 : 

### Question 11 :

Avec le DROP on n'atteint pas et avec le REJECT on se fait refuser le ping 

```
From 192.168.1.3 icmp_seq=3 Destination Port Unreachable
ping: sendmsg: Opération non permise
```

### Question 12 : 

On a le retour suivant à la commande 

```
Chain INPUT (policy ACCEPT 0 packets, 0 bytes)
 pkts bytes target     prot opt in     out     source               destination         

Chain FORWARD (policy ACCEPT 0 packets, 0 bytes)
 pkts bytes target     prot opt in     out     source               destination         

Chain OUTPUT (policy ACCEPT 386 packets, 117K bytes)
 pkts bytes target     prot opt in     out     source               destination         
    4   336 REJECT     0    --  *      *       0.0.0.0/0            8.8.8.8              reject-with icmp-port-unreachable

```
On voit une règle de rejet de 8.8.8.8 (reject-with-icmp-port-unreachable)

### Question 13 :

Elle a mit dans un fichier texte les filtres de iptables.

### Question 14 : 

La commande nous a permis de reprendre notre fichier txt comme liste de règles

### Partie 6 :

### Question 15 : 

Ce script permet de mettre ou d'enlever la règle de filtrage de 8.8.8.8

### Question 16 (et procedure):

On modifie le fichier en annexe pour rajouter au "start" les lignes : 

```
ip46tables -A INPUT -i lo -j ACCEPT
ip46tables -A OUTPUT -o lo -j ACCEPT
ip46tables -A INPUT --src people.irisa.fr -j ACCEPT

```


### Question 17 :


On rajoute aussi une ligne :

```
ip46tables -A INPUT -m conntrack --ctstate RELATED,ESTABLISHED -j
ACCEPT
```

### Question 18 :

fait (voir annexe)

Par contre on a aussi rajouté une ligne au stop pour enlever après


### Question 19 :

fait (voir annexe)

### Question 20 :

On ajoute les lignes suivantes à start:

```
iptables -A OUTPUT -d www.facebook.com -j LOGDROP
```


### Question 21 :

Sur mon réseau ça ne fait rien, j'ai essayé de remplacer tout mes iptables par un ip46tables mais j'ai eu une erreur de segmentation donc je suis repassé sur le truc de avant.

### Question 22 :

fait(voir annexe)

### Question 23 :

Pour moi tout marche encore mais ce doit être à cause(grâce à) de IPV6

### Question 24 : 

fait (voir annexe) (je l'ai mis avant le drop des trucs dans input)



## Annexe :

```
#!/bin/bash
set -e
# set -x Uncomment for debug (or launch me with bash -x)



start (){

	#Acceptation des trucs dans loopback
	iptables -A INPUT -i lo -j ACCEPT
	iptables -A OUTPUT -o lo -j ACCEPT

	#Drop de google
	iptables -A OUTPUT --dst 8.8.8.8 -j DROP

	#Acceptation de tout ce qui viens de people.irisa.fr
	iptables -A INPUT --src people.irisa.fr -j ACCEPT

	#acceptation de tout ce qu'on a déjà contacté
	iptables -A INPUT -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT
	
	#création de la chaine LOGDROP
	iptables -N LOGDROP
	
	#Log des paquest avec le prefix [LOGDROP] puis drop
	iptables -A LOGDROP -j LOG --log-prefix '[LOGDROP]'
	iptables -A LOGDROP -j DROP

	#envoie dans logdrop de facebook
	iptables -A OUTPUT --dst www.facebook.com -j LOGDROP
	ip6tables -A OUTPUT --dst www.facebook.com -j LOGDROP

	#acceptation de http(port 80)
	iptables -A INPUT -p tcp --dport 80 -j ACCEPT
	iptables -A INPUT -p udp --dport 80 -j ACCEPT

	#envoie dans logdrop de tout ce qui reste 
	iptables -A INPUT -j LOGDROP
}

stop (){
	iptables -F LOGDROP
	iptables -X LOGDROP
	iptables -F
	iptables -X
}

case $1 in

"start")
	start
	;;
"stop")
	stop
	;;
"restart"|"reload")
	stop
	start
	;;
"status")
	iptables -L -v -n
	;;
"help"|*)
	echo "Usage: $(basename $0) start|stop|restart|reload|status|help"
	exit 1
esac



```