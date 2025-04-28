# TP6-7 - Mounir Yamout - Nicolas Mendel-Boucharin :

## Partie I : 

### Question 1 

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

### Question 2

On ne reconnait rien de spécial sinon. 


## Partie II.A : 

### Question 1.

Wireshark regarde les ports et en déduit le protocole : Si il voit "port:80" il en déduit que c'est du http et si voit "port:443" il en déduit que c'est du https.

### Question 2. 

La ressource principale demandé est le document de la page à la racine (la page principale). (2 paquets sur firefox et 4 sur wireshark)

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


WWW-Authenticate: Basic realm="Salade de fruits". Pour proposer au client de se connecter avec un login et un mot de passe. 

### Question 8. 

Le header est :

Authorization: Basic Zm9vYmFyOkkgbGlrZSBhcHBsZXM=\r\n
Credentials: foobar:I like apples

### Question 9.

Zm9vYmFyOkkgbGlrZSBhcHBsZXM= est l'identifiant et le mot de passe séparé par deux points en base 64. Il n'y a aucun chiffrement. N'importe qui sur le même réseau peut y accéder.

### Question 10.

On sait déjà que c'est sécurisé mais sur wireshark on voit que les paquets sont illisibles car chiffrés.

## Partie II.B



### Question 2.1.

Linux regarde tout seul dans /etc/services et fait lui même le lien entre http et son port alloué

### Question 2.2. 

telnet mgoessen.istic.univ-rennes1.fr http
Trying 148.60.11.246...
Connected to mgoessen.istic.univ-rennes1.fr.
Escape character is '^]'.
GET / HTTP/1.1
HOST: mgoessen.istic.univ-rennes1.fr

HTTP/1.1 200 OK
Date: Fri, 25 Apr 2025 13:16:16 GMT![alt text](image.png)
Server: Apache/2.4.62 (Debian)
Last-Modified: Sun, 19 Jan 2025 15:54:20 GMT
ETag: "f7-62c11282b3025"
Accept-Ranges: bytes
Content-Length: 247
Vary: Accept-Encoding
Content-Type: text/html

<html><head><title>Vous Etes Perdu ?</title></head><body><h1>Perdu sur l'Internet ?</h1><h2>Pas de panique, on va vous aider</h2><strong><pre>    * <----- vous &ecirc;tes ici</pre></strong></body></html>

<!-- Original content from perdu.com -->

Connection closed by foreign host.


### Question 2.3

Le résultat de la requête est stockée dans index.html

### Question 2.4 

Les paquets correspondant aux requêtes de mozilla contiennent plus d'informations que ceux
correspondants aux requêtes de wget. Elles contiennent en plus le nom de l'hôte et  langages acceptés. 

On constate aussi qu'on peut voir que l'user-agent est donné comme étant Mozilla/5.0 dans le cas de Mozilla, tandis que dans le cas de wget, celui-ci est noté Wget/1.21. Ainsi, un serveur pourrait filtrer toutes les requêtes contenant la donnée User-Agent : Wget/1.21, pour refuser spécifiquement les requête envoyée par Wget. 

### Question 2.5 

Il y'a une option de wget qui permet de customiser le user-agent par le nom que l'on veut. En tapant la commande 

wget --user-agent="Firefox/5.0" http://mgoessen.istic.univ-rennes1.fr, on peut tout à fait se faire passer pour firefox auprès du serveur ciblé

### Question 2.6 
curl n'enregistre pas les requête par lui même, il ne fait qu'afficher la requête sur un terminal. C'est à nous de l'enregistrer dans un fichier en ajoutant toto2.html à la fin  notre requête dans le terminal si besoin d'enregistrer. 


### Question 2.7 et 8 :

curl a encore moins d'information que wget vu qu'il ne donne pas d'information sur la connexion et l'accept-encoding. De la même manière, les serveurs peuvent filtrer tous les paquets qui ont en nom e User-Agent curl/7.74.0 pour refuser les paquets des requêtes curl. Et pareillement, on peut modifier le nom de l'user agent mais cette fois-ci avec la commande : curl 'http://example.org/' -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8' -H 'Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3' -H 'Accept-Encoding: gzip, deflate' -H 'Connection: keep-alive' -H 'Upgrade-Insecure-Requests: 1' -H 'If-Modified-Since: Mon, 13 Jan 2025 20:11:20 GMT' -H 'If-None-Match: "84238dfc8092e5d9c0dac8ef93371a07:1736799080.121134". On atteint un tel degré de précision en fouillant dans les outils de Firefox lui-même. 

### Question 2.9 : 

Lorsque l'on s'authentifie sur le site https://people.irisa.fr/Mathieu.Goessens/netsec-2425/.playground/TP6-auth/,on a vu que  la requête envoie est : Authorization: Basic Zm9vYmFyOkkgbGlrZSBhcHBsZXM=\r\n avec le mot de passe en base 64. Vu que l'on peut écrire ce que l'on veut avec l'option -H de curl, il suffit alors de taper la commande : curl 'https://people.irisa.fr/Mathieu.Goessens/netsec-2425/.playground/TP6-auth/' -H 'Authorization: Basic Zm9vYmFyOkkgbGlrZSBhcHBsZXM=', afin que le serveur reçoive ce qu'il est censé recevoir pour une authentification exacte. 

### Question 2.10 : 

L'option --libcurl foo.c permet d'enregistrer l'équivalent de la commande que l'on execute, traduite dans le langage c.

### Question 2.11

Ces commandes font comme telnet, à la différence qu'elles affichent également le contenu du site. La première commande affiche les certificats contrairement à la seconde. 


## Partie III :

### Question 3.1 : 

En tapant netcat -l -p 8080 dans le terminal, puis en se connectant et en écrivant Hello, Hello apparait sur la page du navigateur. On peut même envoyer des réponses aux requêtes manuellement. Par exemple,en tapant HTTP/1.1 401 Unauthorized manuellement, on bloque l'accès au site en forçant l'utilisateur à entrer son mot de passe comme nous l'avais fait le site étudié auparavant. 
 
### Question 3.5 : 

La commande crée un serveur HTTP local via python sur le port 8080. On peut se connecter ensuite au serveur local depuis le même ordinateur via le lien http://localhost:8080/. On constate une fois sur le site que l'ensemble du répertoire à partir duquel a été tapé la commande sur le terminal est à présent présent sur le site.

### Question 3.6 : 

En exécutant le code et en se connectant à http://localhost:8080/, on peut voir le message Hello World affiché. En regardant les requêtes affiché dans l'onglet réseau des outils développement web de Firefox, on peut voir qu'un paquet envoie des réponses avec le code 200 OK et si l'on clique sur le paquet et que l'on va dans l'onglet réponses, on retrouve le message Hello World. EN actualisant, le paquet est toujours la. Ainsi, on peut en déduire que le code fait envoyer continuellement au client des réponses 200 OK contenant le message Hello World

### Question 3.7 : 

La commande fait exactement la même chose que la commande python3 -m http.server 8080, elle crée le serveur http sur le port désiré et y envoie tous les répertoire sur lequel le terminal est. Vu que la commande a été entièrement écrite sur python, on pourrait rendre plus beau l'interface et ajouter plusieurs fonctionnalité comme obliger le client à se connecter avec un mot de passe etc... On peut personnaliser le site.

### Question 3.8 : 

Après éxecution du code en entrant seulement l'URL http://localhost:8080/ dans le navigateur, on obtient une erreur 501:Not implemented, et c'est normal car n'ayant rien spécifier dans l'URL, on n'entre dans aucun bloc conditionnels des if, et par conséquent, on execute seulement les commandes après les if, qui nous disaient de répondre au client avec l'erreur 501. Par ailleurs, tous les mots clés que l'on entrerait après un / après l'URL qui ne sont reconnus par aucun des if nous emmène aussi sur cette erreur ce qui est logique. 

En entrant /.+?debug après l'url on voit que dans le if correspondant, on parcourt à l'aide d'un for les headers. Et on  voit effectivement affiché sur le site les Host, User-Agent... de la requête. 
On voit également affiché tout en bas HTTP/1.0 501 Not implemented Server: SimpleHTTP/0.6 Python/3.12.3 Date: Sat, 26 Apr 2025 10:21:14 GMT Error 501: Not implemented, et c'est dû au fait qu'il n'y a aucun return dans ce bloc conditionnel. Donc une fois sorti du if, le serveur va executer les commandes suivantes. Cependant, on peut également constater qu'il n'y a pas non plus de paquet contenant l'erreur 501, contrairement au cas ou l'on entrait pas dans le if, et cela est sûrement dû au fait qu'on a déja envoyé un paquet réponse de code 200, et que le serveur considère qu'il ne faut pas envoyer d'autre paquet après celui-ci. 

En entrant /hello/, on observe simplement écrit Hello World ! sur la page, et c'est normal, car on reconnait dans cette partie du if, le code qu'on a utilisé précedemment. 

En entrant /htmllo, on observe le même texte, mais écrit en html. 

Ensuite en créeant un dossier /www/ dans le répertoire ou l'on est, et en entrant /www/, on voit sur le site le contenu de notre dossier www, et c'est normal car on reconnait encore une fois une commande utilisé précedemment. Si il n'y a pas le dossier www dans le répertoire envoyé par python, on constate qu'il y'a une erreur 404, sûrement dû au fait que le serveur à chercher une donnée précise en vain car elle était introuvable. 

### Question 3.9 : 

On pourrait rajouter un if re.match("/www/restricted/, self.path) : et y mettre à l'intérieur self.send_response(403), pour lui envoyer une réponse de code 403, qui correspond à accès refusé dans le protocole de communication HTTP.  Il faut bien mettre le if AVANT le if re.match("/www/?.*, self.path) car sinon, le serveur enverrait d'abord le répertoire www avec une réponse 200, et donc premièrement n'enverrait pas la réponse 403 car il ne peut pas le faire ,après la réponse 200, et deuxièmement, le client aurait tout à fait accès au répertoire envoyé. 

### Question 3.10 : 

On constate sur la documentation fournie que l'on peut accéder à l'adresse ip du client via client_address. On y aura alors accès sous la forme d'un couple (addresse,port). Il suffit donc d'ajouter and self.client_address[0] not in ["127.0.0.1","192.168.1.42"] à notre condition initiale pour n'autoriser que les addresse ip concernée à accéder à restricted. 


### Question 3.11 : 

On a vu question 1.7 que le header envoyé pour demander au client de se connecter est WWW-Authenticate: Basic realm="Salade de fruits".
On a vu question 1.8 que celui envoyé par le client lorsqu'il donne le bon mot de passe est : Authorization: Basic Zm9vYmFyOkkgbGlrZSBhcHBsZXM=

On peut donc rajouter un if re.match("/www/restricted2/, self.path) dans lequel on rajoute un deuxième if pour vérifier si le client a déja rentré le bon mot de passe en vérifiant qu'il a envoyé le header correspondant, auquel cas on le laisse accéder au repertoire, et dans l'autre cas, on lui demande de s'authentifier en lui envoyant l'erreur 401 avec le  header correspondant : 

```{python}

if re.match("/www/restricted2/?.*",self.path):

    if self.headers["Authorization"] == "Basic Y2xpZW50c2F0aXNmYWl0OmNldHBhw6l0w6lmYWl0cGFydW5ib2dvc3M=" : 
        return SimpleHTTPRequestHandler.do_GET(self)
    self.send_response(401)
    self.send_header('WWW-Authenticate','Basic realm="You shall not pass"')
    self.end_headers()
    return
```  

### Question 3.12 : 

La même chose ce produit avec wireshark que précedemment, identifiant et mot de passe sont accessibles en base 64 sans chiffrement. 

### Question 3.13 : 

Nous n'avons pas eu le temps de faire cette question. 

### Question 3.14 : 

La première commande crée une clé publique RSA et la stocke dans un fichier nommé key.pem ainsi qu'un certificat dans un fichier cert.pem
La seconde écoute permet de créer un proxy qui écouter sur le port 8443 des données chiffrées, et les transmet au port 8080 ou les données ne sont pas chiffrés. 


### Question 3.15 : 

Ce code permet de chiffrer toute les données echangée grâce à la clé RSA et au certificat. Ainis, l'identifiant et le mot de passe sont chiffrés et le processus est bien plus sécurisé. 

### Question 3.16 : 

Firefox nous dit que la connexion n'est pas sûre et l'on doit lui confirmer qu'on est sûr d'avancer avant de continuer. C'est nous qui avons crée et signé le certificat, comme il est ainsi méconnu du grand public, Firefox nous précise qu'il peut être dangereux. 

### Question 3.17 : 

La sécurité de l'authentification dépend désormais entièrement du type de chiffrement. Le chiffrement étant RSA, on peut dire que la connexion est sécurisée. 


























