# TP6-7 - Marilou Le Bricon - Nicolas Mendel-Boucharin :

## Partie I : 

todo : 

[]

### Question 1. 

- pour http le port réservé est 80 
- pour https le port réservé est 443
- pour DNS le port réservé est 53
- pour SSH le port réservé est 22
- SMTP : 25
- POP3 : 110
- POP3S :  995
- IMAP : 143
- IMAPS : 993
- File Transfert Protocol : 21 

### Question 2.

On ne reconnait rien de spécial sinon. 


## Partie II.A : 

### Question 1.

Wireshark regarde les ports et en déduit le protocole : Si il voit "port:80" il en déduit que c'est du http et si voit "port:443" il en déduit que c'est du https.

### Question 2. 

La ressource principale demandé est le document de la page à la racine (la page principale). 

### Question 3. 

On voit que la ligne de requête principale est le get en gras (beaucoup plus facile à visualiser sur wireshark que sur firefox).

19	5.682125819	148.60.12.147	148.60.11.246	HTTP	531	**GET / HTTP/1.1** 

### Question 4. 

On voit que la réponse principale est le corps de la page cf truc en gras 

21	5.684435678	148.60.11.246	148.60.12.147	HTTP	594	**HTTP/1.1 200 OK  (text/html)**


### Question 5.

Les trois headers principaux sont :  

Host: mgoessen.istic.univ-rennes1.fr
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8

Host donne l'adresse du serveur 
User-Agent donne le programme qui envoie la requete
Accept c'est qu'on ce que le client est prêt à accepter

### Question 6. 

Les headers principaux sont en gras :

Date: Tue, 18 Mar 2025 16:03:46 GMT
Server: Apache/2.4.62 (Debian)
Last-Modified: Sun, 19 Jan 2025 15:54:20 GMT
ETag: "f7-62c11282b3025-gzip"
Accept-Ranges: bytes
Vary: Accept-Encoding
Content-Encoding: gzip
**Content-Length: 192**
Keep-Alive: timeout=5, max=100
Connection: Keep-Alive
**Content-Type: text/html**

Content-Length donne le nombre de bytes chargés
Content-Type donne le type du paquet (ici du text en html basique)

### Question 7.

Le header est :

WWW-Authenticate: Basic realm="Salade de fruits"\r\n

### Question 8. 

Le header est :

Authorization: Basic Zm9vYmFyOkkgbGlrZSBhcHBsZXM=\r\n
    Credentials: foobar:I like apples

### Question 9.

N'importe qui sur le même réseau que nous pourrait voir les paquet et en extraire le header plus haut. 

### Question 10.

On sait déjà que c'est sécurisé mais sur wireshark on voit que les paquets sont illisibles car chiffrés.

## Partie II.B

### Question 2.1.

Linux regarde tout seul dans /etc/services et fait lui même le lien entre http et son port alloué

### Question 2.2. 



