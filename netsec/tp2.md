#TP2 - Nicolas Mendel-Boucharin - Marilou Le Bricon

## Question 1. 

Dans le terminal si on écrit un message sur le client on le recoit sur le serveur (l'inverse n'est pas vrai)
Cependant wireshark enregistre les messages qu'ils soit écrit sur le client ou sur le serveur. 

## Question 2. 

Pour être sûr que il ne soit pas déjà utilisé par quelque chose d'autre. 

## Question 3.

Il faut réassigner le UDP_PORT à 10000 au lieu de 5005

## Question 4.

La même chose qu'à la question 3 

## Question 5.

On rajoute au fichier seveur les lignes suivantes : 

> if data !=b"": \
>        reponse = b"j'ai recu un truc"  
>        sock.sendto(reponse, addr)  

On rajoute au fichier client les lignes suivantes :

> data, _ =sock.recvfrom(1024)
print(data)

## Question 6.

En lançant le client sans que le serveur soit lancé on le paquet suivant sur wireshark :

> 13	2337.590371380	127.0.0.1	127.0.0.1	ICMP	83	Destination unreachable (Port unreachable)

Et les types et codes sont les suivants :
> Type: 3 (Destination unreachable)  
> Code: 3 (Port unreachable)

Il contient quand même le message envoyé par le client qui est donc transmis deux fois (contient notre ancien paquet).

## Question 7.

Quand on n'active pas IP_RECVERR le programme python continu de tourner sans afficher d'erreur alors que quand on l'active il nous renvoie : 

> ConnectionRefusedError: [Errno 111] Connection refused

## Question 8. 

La fregmentation est gérée par le layer Network. Et il y a un flag "More fragments" au début de IP, et des bouts de UDP dans la data des paquets. 

## Question 9. 

1514 octets dont 1500 de ip

La commande ip addr show rend : 

> 2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> **mtu 1500** qdisc pfifo_fast state UP group default qlen 1000

On voit que les 1500 octets correspondent à mtu (maximum transmission unit)

## Question 10.

Pour ne plus seulement être en localhost qui permets des paquets beaucoup plus gros (65536): 

> 1: lo: <LOOPBACK,UP,LOWER_UP> **mtu 65536** qdisc noqueue state UNKNOWN group default qlen 1000 


### annexe : 

le code en python du client :

> import socket   

> UDP_IP = "127.0.0.1"  
> UDP_PORT= 10000  
> IP_RECVERR=11  
> MESSAGE = b"Hello, World !"  
> print("UDP target IP: %s"% UDP_IP)  
> print("UDP target PORT: %s"% UDP_PORT)  
> print("message: %s" %MESSAGE)  

> sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
> sock.setsockopt(socket.IPPROTO_IP, IP_RECVERR, 1)  
> sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))  
> data, _ =sock.recvfrom(1024)  
> print(data)  



le code en python du serveur : 

> import socket   

> UDP_IP = "127.0.0.1"  
> UDP_PORT= 10000  
> sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
> sock.bind((UDP_IP, UDP_PORT))  
> reponse = "j'ai recu un truc"  
> while True:  
>     data, addr = sock.recvfrom(1024)  
>     print("received message: %s" %data)  
>     if data !=b"":  
>         reponse = b"j'ai recu un truc"  
>         sock.sendto(reponse, addr)  

