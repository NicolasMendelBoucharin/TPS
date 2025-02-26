# TP 3 - Nicolas Mendel-Boucharin - Marilou Le Bricon

## Partie I 

### Question 1.1.

On utilise la commande : 

> netcat -l -p 10000

### Question 1.2.

On utilise la commande :

> netcat localhost 10000

### Question 1.3.

Il y a un flag d'acknowledgment (le premier push aussi)

### Question 1.4.

Le premier paquet envoie un push de data et un ack
Le deuxième ne renvoie qu'un ack

On fait un schéma plus complet pour la question 1.5.

### Question 1.5.

[ordinateur1] -> packet1(seq:y, ack:x, len:n)-> [ordinateur2]
[ordinateur2] -> packet2(seq:x, ack:y+n, len:l) -> [ordinateur1]
[ordinateur1] -> packet3(seq:y+n, ack:x+l, len:m) -> [ordinateur2]
[ordinateur2] -> packet4(seq:x+l, ack:y+n+m, len:0) -> [ordinateur1]

avec n, l, m $\neq 0$

## Partie II : 

### Question 2.1.

Comme dans le TP2 on remplace le TCP_PORT qu'on met à 10000

On a mainteant un message de syn du serveur au début auquel le client repond avec un syn et un ack, puis le serveur renvoie un ack et là seulement on refait tout comme avant

> 1	0.000000000	127.0.0.1	127.0.0.1	TCP	74	48104 → 10000 [SYN] Seq=0 Win=65495 Len=0 MSS=65495 SACK_PERM=1 TSval=1933337289 TSecr=0 WS=128  
> 2	0.000007262	127.0.0.1	127.0.0.1	TCP	74	10000 → 48104 [SYN, ACK] Seq=0 Ack=1 Win=65483 Len=0 MSS=65495 SACK_PERM=1 TSval=1933337289 TSecr=1933337289 WS=128   
> 3	0.000012796	127.0.0.1	127.0.0.1	TCP	66	48104 → 10000 [ACK] Seq=1 Ack=1 Win=65536 Len=0 TSval=1933337289 TSecr=1933337289  
> 4	0.000055803	127.0.0.1	127.0.0.1	TCP	80	48104 → 10000 [PSH, ACK] Seq=1 Ack=1 Win=65536 Len=14 TSval=1933337289 TSecr=1933337289  
> 5	0.000059085	127.0.0.1	127.0.0.1	TCP	66	10000 → 48104 [ACK] Seq=1 Ack=15 Win=65536 Len=0 TSval=1933337289 TSecr=1933337289  

### Question 2.2.

On a encore du changer le TCP_PORT à 10000. 

On a maintenat un message de fin de connexion qui doit aussi être ack par les machines :

> 8	0.000187587	127.0.0.1	127.0.0.1	TCP	66	48604 → 10000 [FIN, ACK] Seq=15 Ack=15 Win=65536 Len=0 TSval=1933898386 TSecr=1933898386  
> 9	0.000199862	127.0.0.1	127.0.0.1	TCP	66	10000 → 48604 [FIN, ACK] Seq=15 Ack=16 Win=65536 Len=0 TSval=1933898386 TSecr=1933898386  
> 10	0.000202163	127.0.0.1	127.0.0.1	TCP	66	48604 → 10000 [ACK] Seq=16 Ack=16 Win=65536 Len=0 TSval=1933898386 TSecr=1933898386  

(tout ça bien entendu après les paquets de message et de réponse)

### Question 2.3.

Si c'est avec le même conn ça ne marche pas. Il faut que les bons numéros seq et ack pour que quelqu'un réponde à la place du serveur.


### Question 2.4.


