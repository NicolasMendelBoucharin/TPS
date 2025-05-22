# TP 8 - Mounir Yamout - Nicolas Mendel-Boucharin

## Partie 1.

### Question 1 :

Mon adresse ip est "148.60.12.108/24"
Marc a 148.60.12.120, Mounir a 148.60.12.131

Il passe par les protocoles ethernet ip ip et icmp

## Partie 2. 

### Question 2 :

Mon adresse ip est toujours 148.60.12.108

Quand aux routes : 

```
default via 148.60.12.254 dev eth0 
148.60.12.0/24 dev eth0 proto kernel scope link src 148.60.12.108 
169.254.0.0/16 dev eth0 scope link metric 1000 

```

Pour aller à 8.8.8.8 :

```
raceroute to 8.8.8.8 (8.8.8.8), 30 hops max, 60 byte packets
 1  vlan12-gw.istic.univ-rennes1.fr (148.60.12.254)  0.634 ms  0.515 ms  0.461 ms
 2  gw-ri-ifsic.univ-rennes1.fr (148.60.240.254)  0.633 ms  0.556 ms  0.505 ms
 3  10.0.7.1 (10.0.7.1)  0.731 ms  0.788 ms  0.849 ms
 4  * vl1825-be3-ren-nr-rennes-rtr-091.noc.renater.fr (193.51.184.26)  1.665 ms *
 5  et-5-2-1-ren-nr-paris1-rtr-131.noc.renater.fr (193.51.177.174)  7.709 ms  7.586 ms  7.536 ms
 6  et-5-0-1-ren-nr-paris2-rtr-131.noc.renater.fr (193.55.204.195)  7.520 ms et-4-0-1-ren-nr-paris2-rtr-131.noc.renater.fr (193.55.204.193)  7.575 ms *
 7  * 192.178.70.144 (192.178.70.144)  7.531 ms  9.334 ms
 8  * * *
 9  dns.google (8.8.8.8)  29.498 ms  7.500 ms  14.396 ms
```
### Question 3 : 

Mes adresses ip avec "ip a" sont :

```
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether 08:00:27:4d:ae:d5 brd ff:ff:ff:ff:ff:ff
    altname enp0s3
    inet 148.60.12.108/24 brd 148.60.12.255 scope global dynamic eth0
       valid_lft 1565sec preferred_lft 1565sec
    inet6 fe80::a00:27ff:fe4d:aed5/64 scope link 
       valid_lft forever preferred_lft forever
3: tunl0@NONE: <NOARP> mtu 1480 qdisc noop state DOWN group default qlen 1000
    link/ipip 0.0.0.0 brd 0.0.0.0
8: tap0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UNKNOWN group default qlen 1000
    link/ether 82:31:b7:67:90:c6 brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.15/24 scope global tap0
       valid_lft forever preferred_lft forever
    inet6 fe80::5c37:2ff:fe1a:e52a/64 scope link 
       valid_lft forever preferred_lft forever

```

Mon adresse (sur le site) est 148.60.11.246

Les routes sont désormais : 

```
0.0.0.0/1 via 10.42.0.1 dev tap0 
default via 148.60.12.254 dev eth0 
10.42.0.0/24 via 10.42.0.1 dev tap0 
128.0.0.0/1 via 10.42.0.1 dev tap0 
129.20.128.0/24 via 148.60.12.254 dev eth0 
148.60.11.246 via 148.60.12.254 dev eth0 
148.60.12.0/24 dev eth0 proto kernel scope link src 148.60.12.108 
148.60.15.0/24 via 148.60.12.254 dev eth0 
169.254.0.0/16 dev eth0 scope link metric 1000  
```


Et le traceroute donne :

```
 1  10.42.0.1 (10.42.0.1)  1.283 ms  1.688 ms  1.987 ms
 2  vlan11-gw.istic.univ-rennes1.fr (148.60.11.254)  1.908 ms  2.461 ms  1.824 ms
 3  gw-ri-ifsic.univ-rennes1.fr (148.60.240.254)  2.176 ms  2.118 ms  2.056 ms
 4  10.0.7.1 (10.0.7.1)  2.251 ms  2.124 ms *
 5  vl1825-be3-ren-nr-rennes-rtr-091.noc.renater.fr (193.51.184.26)  13.209 ms  12.417 ms  12.209 ms
 6  et-5-2-1-ren-nr-paris1-rtr-131.noc.renater.fr (193.51.177.174)  12.250 ms  9.879 ms  9.673 ms
 7  et-4-0-1-ren-nr-paris2-rtr-131.noc.renater.fr (193.55.204.193)  11.228 ms et-5-0-1-ren-nr-paris2-rtr-131.noc.renater.fr (193.55.204.195)  11.175 ms  11.093 ms
 8  * 192.178.70.144 (192.178.70.144)  10.568 ms *
 9  * * *
10  dns.google (8.8.8.8)  9.954 ms  10.628 ms  10.570 ms
```

tap0 fait un tunnel entre mon ordi et le vpn
La route 10.42.0.1 est l'adresse du vpn 
Mais quand on parle au vpn direct on doit passer par mgoessen.istic.univ-rennes1.fr (148.60.11.246/32) pour ne pas boucler

### Question 4 : 

On voit les communications entre notre machine et le serveur comme pour les tunnels de la question 1 par contre on a un chiffrement maintenant. 

### Question 5:

On a vu au TP 6 que les informations de connexions étaient gérés par le navigateur. 

### Question 6 : 

TODO : faire le schéma
Tout n'est pas chiffré, le traffic qui va du vpn à 8.8.8.8 le n'est pas chiffré

### Question 7: 

Dans le wireshark de eth0 on ne voit rien

### Question 8 :

TODO : recopier le schéma


