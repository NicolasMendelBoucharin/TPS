# TP4 - Nicolas Mendel-Boucharin - Marilou Le Bricon

## Question 1.

De base la commande IP().show() donne :

```
###[ IP ]### 
  version= 4
  ihl= None
  tos= 0x0
  len= None
  id= 1
  flags= 
  frag= 0
  ttl= 64
  proto= hopopt
  chksum= None
  src= 127.0.0.1
  dst= 127.0.0.1
  \options\

```

On voit que de base on a comme source et comme destination 127.0.0.1
On crée après un paquet avec juste IP
Quand on crée le paquet pkt on lui change la source en 192.0.2.1 mais sa destination ne change pas 
Ensuite on voit que on peut rajouter à un paquet avec un header IP un protocole ICMP, UDP, Raw...


## Question 2.

On tape les commandes suivantes :

```{python}
req=IP(dst='148.60.12.254')/ICMP()
send(req)
resp = sr1(req)
resp.show()
```

Qui nous confirme que on a bien envoyé un paquet et reçu un paquet de réponse (on utilise seulement le protocole ICMP() qui nous permet de faire un contact avec une réponse). :

```python
Sent 1 packets.
Begin emission:
Finished sending 1 packets.
*
Received 1 packets, got 1 answers, remaining 0 packets
###[ IP ]### 
  version= 4
  ihl= 5
  tos= 0x0
  len= 28
  id= 25538
  flags= 
  frag= 0
  ttl= 255
  proto= icmp
  chksum= 0x1605
  src= 148.60.12.254
  dst= 148.60.12.163
  \options\
###[ ICMP ]### 
     type= echo-reply
     code= 0
     chksum= 0xffff
     id= 0x0
     seq= 0x0
###[ Padding ]### 
        load= '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

```

## Question 3.

On mets en annexe le code du traceroute

## Question 4.

On peut simplement changer la source dans le paquet avec scipy:

```{python}
req=IP(src='8.8.8.8', dst='148.60.12.155')/ICMP()
send(req)
resp = sr1(req)
resp.show()
```

Ici on voit sur le wireshark du pc voisin que j'ai pingé qu'il a répondu à google pong 

## Question 5.



## Annexes : 


- Code du traceroute : 

```python

def tracerouteperso(adressip):
    req = IP(dst=adressip)/ICMP()
    tétéel=1
    while True:
	req.ttl=tétéel
	resp=sr1(req, verbose=0, timeout=0.1)
	tétéel +=1	
	if (resp==None):
	    continue
	euxsource=resp.src
	print(euxsource)
	if(euxsource==adressip) or (tétéel==1000):
            break
        
```
