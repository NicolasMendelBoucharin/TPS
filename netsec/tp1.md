---
title: "TP1"
output: pdf_document
---

## Question 1 : 

La commande **ip addr** rend le retour suivant :

1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether 08:00:27:da:dd:9f brd ff:ff:ff:ff:ff:ff
    altname enp0s3
    inet **148.60.12.167/24** brd 148.60.12.255 scope global dynamic eth0
       valid_lft 578sec preferred_lft 578sec
    inet6 fe80::a00:27ff:feda:dd9f/64 scope link 
       valid_lft forever preferred_lft forever
 
L'adresse IP de notre interface reseau est celle en gras

## Question 2 : 

La commande **ip route** retourne : 

default via 148.60.12.254 dev eth0 
148.60.12.0/24 dev eth0 proto kernel scope link src 148.60.12.167 
*169.254.0.0/16 dev eth0 scope link metric 1000*

Commme dit dans l'énoncé on peut ignorer la route 169.254.0.0/16
On commence par atteindre le routeur, puis on atteint notre interface réseau principale. 

## Question 3 : 

La commande **ip neigh** retourne :

148.60.12.254 dev eth0 lladdr d4:76:a0:53:44:e3 REACHABLE
148.60.12.252 dev eth0 lladdr 50:9a:4c:82:50:7e STALE

On peut ignorer l'IP finissant par 252 (machine fantôme sur le réseau).
Celle finissant en 254 c'est le routeur (on peut le confirmer avec la commande traceroute)


## Question 4 :

Après avoir supprimé mes voisins, la commande **ip neigh** ne rend rien mais après un ping on a à nouveau notre routeur comme voisin.

## Question 5 :

Si je ping <google.com> la première ligne affiché dans l'invité de commande est :

PING google.com (172.217.20.174) 56(84) bytes of data.

L'adresse IP de google.com est donc 172.217.10.174

## Question 6 :

Pour atteindre le localhost on n'a pas besoin de passer par le routeur dès lors on atteint directement le local host.

Pour atteindre le site de l'istic on passe par les adresses suivantes (avec la commande **traceroute -I**) :

1  vlan12-gw.istic.univ-rennes1.fr (148.60.12.254)  0.341 ms  0.317 ms  0.368 ms
2  gw-ri-ifsic.univ-rennes1.fr (148.60.240.254)  0.462 ms  0.455 ms  0.447 ms
3  nfrontaldrupal.univ-rennes.fr (129.20.126.134)  1.610 ms  1.247 ms  1.238 ms

Comme on est sur le réseau de l'université (univ-rennes1.fr) on ne passe pas par beaucoup d'adresses.

Pour atteindre le site <cyber.gouv.fr> ce n'est pas aussi facile : 

1  vlan12-gw.istic.univ-rennes1.fr (148.60.12.254)  0.809 ms  0.786 ms  0.778 ms
2  gw-ri-ifsic.univ-rennes1.fr (148.60.240.254)  1.864 ms  1.857 ms  1.851 ms
3  10.0.7.1 (10.0.7.1)  1.814 ms  1.805 ms  1.798 ms
4  vl1825-be3-ren-nr-rennes-rtr-091.noc.renater.fr (193.51.184.26)  2.812 ms  2.801 ms  2.793 ms
5  et-5-2-1-ren-nr-paris1-rtr-131.noc.renater.fr (193.51.177.174)  8.480 ms  8.472 ms  8.464 ms
6  et-2-0-0-ren-nr-lyon1-rtr-131.noc.renater.fr (193.51.180.167)  12.424 ms  12.807 ms  12.780 ms
7  zayo-6461.lyn.franceix.net (77.95.71.77)  17.210 ms  17.547 ms  17.521 ms
8  v3.ae5.tcr1.itx.mrs.as8218.eu (64.125.22.139)  17.164 ms  17.158 ms  17.152 ms
9  ae6.tcr1.th2.par.core.as8218.eu (83.167.56.162)  17.145 ms  16.801 ms  16.775 ms
10  et-1-0-0.tcr2.th2.par.core.as8218.eu (83.167.55.47)  16.764 ms  20.449 ms  20.429 ms
11  mediactive-gw5.tcr2.th2.par.cust.as8218.eu (213.152.0.223)  17.965 ms  17.897 ms  18.000 ms
12  178.248.212.123 (178.248.212.123)  19.050 ms  18.763 ms  19.050 ms
13  * * *
14  185.231.164.136 (185.231.164.136)  18.632 ms  18.591 ms  18.520 ms

## Question 7 : 

On atteint moins facilement le site <istic.univ-rennes1.fr> en passant par un autre réseau : 

1  193.17.192.50 (193.17.192.50) [AS34019]  0.414 ms
2  po11-808-er01-lyn.bb.hivane.net (193.164.153.180) [AS34019]  0.359 ms
3  xe-0-1-1-0-er02-th2.bb.hivane.net (193.164.153.162) [AS34019]  7.279 ms
4  renater-ix1.sfinx.tm.fr (194.68.129.102) [*]  6.572 ms
5  hu0-4-0-40-ren-nr-rennes-rtr-091.noc.renater.fr (193.51.177.175) [AS2200]  12.642 ms
6  u-1-rennes-cri-vl1825-be3-ren-nr-rennes-rtr-091.noc.renater.fr (193.51.184.25) [AS2200]  12.520 ms

On atteint plus facilement le site <cyber.gouv.fr> (ce qui peut s'expliquer par le fait qu'on n'ait pas besoin de passer par le réseau de l'istic) :

1  193.17.192.50 (193.17.192.50) [AS34019]  0.405 ms
2  po11-808-er01-lyn.bb.hivane.net (193.164.153.180) [AS34019]  0.315 ms
3  po12.807-er02-lyn.bb.hivane.net (193.164.153.183) [AS34019]  0.569 ms
4  xe-2-0-6-3006-er01-vty.bb.hivane.net (193.164.153.158) [AS34019]  7.026 ms
5  xe-4-4-0-0-er02-vty.bb.hivane.net (193.164.153.251) [AS34019]  6.820 ms
6  mediactive-network.par.franceix.net (37.49.236.121) [AS57734]  7.078 ms
7  178.248.212.123 (178.248.212.123) [AS197133]  7.877 ms

## Question 8 :

Il y a des similarités avec les chemins que la machine de l'ISTIC emprunte. Cela peut s'expliquer par le fait que si on ne part du même endroit on arrive au même et que par exemple on doit passer par plusieurs hébérgeurs du site.

## Question 9 :

Après être allé sur partage regarder mes mails j'ai les connections TCP ouvertes suivantes :

State                 Recv-Q                 Send-Q                                   Local Address:Port                                                                           Peer Address:Port                  Process                 
ESTAB                 0                      0                                        148.60.12.167:33476                                                                        151.101.129.91:https                                         
ESTAB                 0                      0                                        148.60.12.167:42220                                               209.100.149.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:44644                                                          nfrontalhttp.univ-rennes1.fr:https                                         
ESTAB                 0                      0                                        148.60.12.167:44556                                               166.188.117.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:60746                                                  80.54.36.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:56970                                                76.237.120.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:47922                                                                         172.64.149.23:http                                          
ESTAB                 0                      0                                        148.60.12.167:34610                                                          nfrontalhttp.univ-rennes1.fr:https                                         
ESTAB                 0                      0                                        148.60.12.167:55324                                                       univ-rennes1.partage.renater.fr:https                                         
ESTAB                 0                      0                                        148.60.12.167:55078                                                       univ-rennes1.partage.renater.fr:https                                         
ESTAB                 0                      0                                        148.60.12.167:43698                                                              par21s17-in-f3.1e100.net:http                                          
ESTAB                 0                      0                                        148.60.12.167:48016                                                93.243.107.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:33824                                    a23-200-86-80.deploy.static.akamaitechnologies.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:48022                                                93.243.107.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:36698                                   a23-200-86-121.deploy.static.akamaitechnologies.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:43696                                                              par21s17-in-f3.1e100.net:http                                          
ESTAB                 0                      0                                        148.60.12.167:33820                                    a23-200-86-80.deploy.static.akamaitechnologies.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:44180                                    a23-200-86-97.deploy.static.akamaitechnologies.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:38322                                                82.221.107.34.bc.googleusercontent.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:33798                                    a23-200-86-80.deploy.static.akamaitechnologies.com:http                                          
ESTAB                 0                      0                                        148.60.12.167:36664                                               191.144.160.34.bc.googleusercontent.com:https                                         
ESTAB                 0                      0                                        148.60.12.167:47936                                                                         172.64.149.23:http                                          
ESTAB                 0                      0                                        148.60.12.167:38880                                                82.221.107.34.bc.googleusercontent.com:http 

## Question 10 : 

ireshark. Here it is
already installed, however, we will first need to ensure we have the permission to run it