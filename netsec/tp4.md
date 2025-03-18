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

```python
conf.L3socket = L3RawSocket
req=IP(src='8.8.8.8', dst='127.0.0.1')/UDP(dport=10000)/raw(b"miaou")
send(req)
resp = sr1(req)
resp.show()

```

En modifiant légérement le code (c.f. troubleshooting), on reçoit bien "miaou" sur notre serveur udp

## Question 6. 

En changeant l'ip et le port source en ip et port distant on a bien des messages qui bouclent

```python

conf.L3socket = L3RawSocket
req=IP(src='127.0.0.1', dst='127.0.0.1')/UDP(sport= 10000, dport=10000)/raw(b"miaou")
send(req)
resp = sr1(req)
resp.show()

```
 
## Question 7.

En faisant ce code là : 

```python
conf.L3socket = L3RawSocket
req=IP(src='127.0.0.1', dst='127.0.0.1')/TCP(sport= 5000, dport=10000, flags="S")
resp = sr1(req)
resp.show()

```
On voit bien sur wireshark que on envoie un premier packet syn le serveur nous réponds un syn et un ack mais nous lui répondons un reset. Rien ne s'affiche sur notre serveur du TP2. 

## Question 8. 

En regardant la docu on corrige notre code et on reçoit bien miaou avec le serveur du tp2

```python 
conf.L3socket=L3RawSocket 
s=socket.socket() 
s.connect(("127.0.0.1", 10000))
ss=StreamSocket(s,Raw) 
ss.sr1(Raw("Miaou"))

```

## Question 9.

Comme TCP envoie un ack avant qu'on puisse envoyer notre fichier raw on ne peut pas spoofer. 

## Question 10.

```python
def testdeco(ip, por):
    req=IP(dst=ip)/TCP(sport= 5000, dport=por, flags="S")
    resp = sr1(req, verbose=0, timeout=0.1)
    if resp==None:
        return False
    #else:
       # print(resp['TCP'].flags)
    if 'S' in resp['TCP'].flags and 'A' in resp['TCP'].flags:
	return True

def testport(ip):
    L=[]
    for i in range(10000):
        if testdeco(ip, i):
            L.append(i)
    return L

```

En ayant testé seulement sur 100 ports sur google on a bien une réponse sur le port 53 qui est le seul ouvert.

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
