# TP5

## Partie I :

### Q1 :

Notre serveur local est : nameserver 148.60.15.109
On en a un deuxième au cas où le 1er ne marche pas, qui est : nameserver 148.60.15.106.


### Q2 :

La commande retourne :


```
; <<>> DiG 9.16.44-Debian <<>> A istic.univ-rennes.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 34631
;; flags: qr aa rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 2, ADDITIONAL: 3

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 172f0db771d91cea2a01507a67d438e25e9909fb27ebb3ee (good)
;; QUESTION SECTION:
;istic.univ-rennes.fr.		IN	A

;; ANSWER SECTION:
istic.univ-rennes.fr.	3600	IN	A	129.20.126.139

;; AUTHORITY SECTION:
istic.univ-rennes.fr.	3600	IN	NS	resone.univ-rennes1.fr.
istic.univ-rennes.fr.	3600	IN	NS	soleil.uvsq.fr.

;; ADDITIONAL SECTION:
resone.univ-rennes1.fr.	1063	IN	A	129.20.254.1
soleil.uvsq.fr.		1063	IN	A	193.51.24.1

;; Query time: 0 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:10:42 CET 2025
;; MSG SIZE  rcvd: 185
```

- Nous voyons dans la section réponse : ANSWER SECTION, que l'adresse IP associée au domaine **istic.univ-rennes.fr** est **129.20.126.139**. Le "3600" représente le temps de vie (TTL) en secondes, ce qui signifie que l'enregistrement peut être mis en cache pendant 3600 secondes (1h00).
- Nous voyons dans la section autorité : AUTHORITY SECTION, que les serveurs DNS spécifiés (**resone.univ-rennes1.fr** et **soleil.uvsq.fr**) sont responsables de la gestion des enregistrements DNS pour ce domaine (**istic.univ-rennes.fr**).
- Nous voyons dans la section additionnelle : ADDITIONAL SECTION, les addresses IP des serveurs DNS spécifiés (**resone.univ-rennes1.fr** -> **129.20.254.1** et **soleil.uvsq.fr** -> **193.51.24.1**).
- Puis à la fin nous avons des renseignements généraux : le DNS à été traité en 0 millisecondes, l'adresse IP du serveur DNS qui a répondu est : **148.60.15.109**, date et heure de la demande : **Fri Mar 14 15:10:42 CET 2025** (vendredi 14 mars 2025 à 15h 10min 42sec), taille du message de la réponse : **185** octets.


### Q3 :

La commande renvoie : 

```
; <<>> DiG 9.16.44-Debian <<>> +trace +nodnssec A istic.univ-rennes.fr
;; global options: +cmd
.			508043	IN	NS	g.root-servers.net.
.			508043	IN	NS	h.root-servers.net.
.			508043	IN	NS	a.root-servers.net.
.			508043	IN	NS	j.root-servers.net.
.			508043	IN	NS	e.root-servers.net.
.			508043	IN	NS	b.root-servers.net.
.			508043	IN	NS	d.root-servers.net.
.			508043	IN	NS	c.root-servers.net.
.			508043	IN	NS	l.root-servers.net.
.			508043	IN	NS	m.root-servers.net.
.			508043	IN	NS	i.root-servers.net.
.			508043	IN	NS	f.root-servers.net.
.			508043	IN	NS	k.root-servers.net.
;; Received 475 bytes from 148.60.15.109#53(148.60.15.109) in 12 ms

fr.			172800	IN	NS	g.ext.nic.fr.
fr.			172800	IN	NS	f.ext.nic.fr.
fr.			172800	IN	NS	d.nic.fr.
;; Received 247 bytes from 202.12.27.33#53(m.root-servers.net) in 8 ms

univ-rennes.fr.		3600	IN	NS	soleil.uvsq.fr.
univ-rennes.fr.		3600	IN	NS	ns2.uhb.fr.
univ-rennes.fr.		3600	IN	NS	ns1.uhb.fr.
univ-rennes.fr.		3600	IN	NS	resone.univ-rennes1.fr.
;; Received 247 bytes from 194.146.106.46#53(f.ext.nic.fr) in 8 ms

istic.univ-rennes.fr.	3600	IN	A	129.20.126.139
;; Received 93 bytes from 193.51.24.1#53(soleil.uvsq.fr) in 8 ms
```
On remarque que nodnssec choisi pour nous le serveur m.root-servers.net.



### Q4 :

La commande renvoie :


```
usertp@debian-VM-TP:~$ dig A google.fr

; <<>> DiG 9.16.44-Debian <<>> A google.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 8481
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 4, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 9dc67d6601f1029c6b33cd4267d43bd1f8f6f30e6e12cda0 (good)
;; QUESTION SECTION:
;google.fr.			IN	A

;; ANSWER SECTION:
google.fr.		173	IN	A	142.250.201.163

;; AUTHORITY SECTION:
google.fr.		247	IN	NS	ns4.google.com.
google.fr.		247	IN	NS	ns1.google.com.
google.fr.		247	IN	NS	ns3.google.com.
google.fr.		247	IN	NS	ns2.google.com.

;; ADDITIONAL SECTION:
ns2.google.com.		162085	IN	A	216.239.34.10
ns4.google.com.		162085	IN	A	216.239.38.10
ns1.google.com.		162085	IN	A	216.239.32.10
ns3.google.com.		162085	IN	A	216.239.36.10

;; Query time: 12 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:23:13 CET 2025
;; MSG SIZE  rcvd: 228

usertp@debian-VM-TP:~$ dig A google.fr

; <<>> DiG 9.16.44-Debian <<>> A google.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 35311
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 4, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 4cede864c98eec8d96adeb7767d43bd4c0a6f924ff4740ed (good)
;; QUESTION SECTION:
;google.fr.			IN	A

;; ANSWER SECTION:
google.fr.		170	IN	A	142.250.201.163

;; AUTHORITY SECTION:
google.fr.		244	IN	NS	ns1.google.com.
google.fr.		244	IN	NS	ns3.google.com.
google.fr.		244	IN	NS	ns2.google.com.
google.fr.		244	IN	NS	ns4.google.com.

;; ADDITIONAL SECTION:
ns2.google.com.		162082	IN	A	216.239.34.10
ns4.google.com.		162082	IN	A	216.239.38.10
ns1.google.com.		162082	IN	A	216.239.32.10
ns3.google.com.		162082	IN	A	216.239.36.10

;; Query time: 12 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:23:16 CET 2025
;; MSG SIZE  rcvd: 228

usertp@debian-VM-TP:~$ dig A google.fr

; <<>> DiG 9.16.44-Debian <<>> A google.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 12227
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 4, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 52353834b0954c73c891445f67d43bd748441c0da118d69c (good)
;; QUESTION SECTION:
;google.fr.			IN	A

;; ANSWER SECTION:
google.fr.		167	IN	A	142.250.201.163

;; AUTHORITY SECTION:
google.fr.		241	IN	NS	ns4.google.com.
google.fr.		241	IN	NS	ns3.google.com.
google.fr.		241	IN	NS	ns2.google.com.
google.fr.		241	IN	NS	ns1.google.com.

;; ADDITIONAL SECTION:
ns2.google.com.		162079	IN	A	216.239.34.10
ns4.google.com.		162079	IN	A	216.239.38.10
ns1.google.com.		162079	IN	A	216.239.32.10
ns3.google.com.		162079	IN	A	216.239.36.10

;; Query time: 8 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:23:19 CET 2025
;; MSG SIZE  rcvd: 228

```

Le numéro affiché avant l'adresse IP (par exemple : 173, 170, 167) dans ANSWER SECTION de la réponse DNS représente le "time to live". Il baisse donc naturellement entre chaque moment où on tape la commande 



### Q5 :

dig SOA univ-rennes.fr nous renvoie :
```
; <<>> DiG 9.16.44-Debian <<>> SOA univ-rennes.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 55479
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 3, ADDITIONAL: 4

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: cfeeed265f0f86a48043ae7167d43c6179f7502ebf1e0393 (good)
;; QUESTION SECTION:
;univ-rennes.fr.			IN	SOA

;; ANSWER SECTION:
univ-rennes.fr.		1800	IN	SOA	resone.univ-rennes1.fr. hostmaster.univ-rennes1.fr. 2014067456 1800 1800 2419200 900

;; AUTHORITY SECTION:
fr.			161940	IN	NS	d.nic.fr.
fr.			161940	IN	NS	g.ext.nic.fr.
fr.			161940	IN	NS	f.ext.nic.fr.

;; ADDITIONAL SECTION:
d.nic.fr.		172116	IN	A	194.0.9.1
f.ext.nic.fr.		172116	IN	A	194.146.106.46
g.ext.nic.fr.		172116	IN	A	194.0.36.1

;; Query time: 28 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:25:37 CET 2025
;; MSG SIZE  rcvd: 242
```

Cette commande nous permet de récupérer l'enregistrement Start of Authority pour le domaine **univ-rennes.fr.** L'enregistrement SOA contient des informations sur la zone DNS (Non du serveur primiaire, email de l'administrateur, numéro de série du domaine, etc.).


dig NS univ-rennes.fr nous renvoie :
```
; <<>> DiG 9.16.44-Debian <<>> NS univ-rennes.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 38079
;; flags: qr rd ra; QUERY: 1, ANSWER: 4, AUTHORITY: 0, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: c2a3ae3343bde22a5ff2b43567d43cafddbf5a00ae575dd9 (good)
;; QUESTION SECTION:
;univ-rennes.fr.			IN	NS

;; ANSWER SECTION:
univ-rennes.fr.		1800	IN	NS	soleil.uvsq.fr.
univ-rennes.fr.		1800	IN	NS	ns2.uhb.fr.
univ-rennes.fr.		1800	IN	NS	resone.univ-rennes1.fr.
univ-rennes.fr.		1800	IN	NS	ns1.uhb.fr.

;; ADDITIONAL SECTION:
resone.univ-rennes1.fr.	2838	IN	A	129.20.254.1
ns1.uhb.fr.		172038	IN	A	193.52.64.43
ns2.uhb.fr.		172038	IN	A	193.52.64.44
soleil.uvsq.fr.		85638	IN	A	193.51.24.1

;; Query time: 8 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:26:55 CET 2025
;; MSG SIZE  rcvd: 235

```
Cette commande nous permet de récuperer les noms des serveurs associé à istic.univ-rennes.fr (ici univ-rennes.fr,soleil.uvsq.fr., ns2.uhb.fr., resone.univ-rennes1.fr. et ns1.uhb.fr.)
 



dig MX gmail.com nous renvoie :
```
; <<>> DiG 9.16.44-Debian <<>> MX gmail.com
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 58292
;; flags: qr rd ra; QUERY: 1, ANSWER: 5, AUTHORITY: 4, ADDITIONAL: 5

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 763240bafbcefb9817d05c5967d43cda5941511c296fa2cf (good)
;; QUESTION SECTION:
;gmail.com.			IN	MX

;; ANSWER SECTION:
gmail.com.		3600	IN	MX	10 alt1.gmail-smtp-in.l.google.com.
gmail.com.		3600	IN	MX	5 gmail-smtp-in.l.google.com.
gmail.com.		3600	IN	MX	30 alt3.gmail-smtp-in.l.google.com.
gmail.com.		3600	IN	MX	20 alt2.gmail-smtp-in.l.google.com.
gmail.com.		3600	IN	MX	40 alt4.gmail-smtp-in.l.google.com.

;; AUTHORITY SECTION:
gmail.com.		162259	IN	NS	ns4.google.com.
gmail.com.		162259	IN	NS	ns1.google.com.
gmail.com.		162259	IN	NS	ns3.google.com.
gmail.com.		162259	IN	NS	ns2.google.com.

;; ADDITIONAL SECTION:
ns2.google.com.		161820	IN	A	216.239.34.10
ns1.google.com.		161820	IN	A	216.239.32.10
ns3.google.com.		161820	IN	A	216.239.36.10
ns4.google.com.		161820	IN	A	216.239.38.10

;; Query time: 24 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:27:38 CET 2025
;; MSG SIZE  rcvd: 325

```

Cette commande nous indiques les serveurs responsables des echanges de mails (ici : alt1.gmail-smtp-in.l.google.com, gmail-smtp-in.l.google.com, alt3.gmail-smtp-in.l.google.com, *alt2.gmail-smtp-in.l.google.com et alt4.gmail-smtp-in.l.google.com)

dig +short istic.univ-rennes.fr nous renvoie :
```
129.20.126.139
```

Cette commande renvoie l'adresse IP associée au nom de domaine istic.univ-rennes.fr, qui est 129.20.126.139.


### Q6 :

dig A istic.univ-rennes.fr nous renvoie :
```
; <<>> DiG 9.16.44-Debian <<>> A istic.univ-rennes.fr
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 95
;; flags: qr aa rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 2, ADDITIONAL: 3

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: c4d7f46ceece2b36fac70c5567d43d3010c2940373134084 (good)
;; QUESTION SECTION:
;istic.univ-rennes.fr.		IN	A

;; ANSWER SECTION:
istic.univ-rennes.fr.	3600	IN	A	129.20.126.139

;; AUTHORITY SECTION:
istic.univ-rennes.fr.	3600	IN	NS	resone.univ-rennes1.fr.
istic.univ-rennes.fr.	3600	IN	NS	soleil.uvsq.fr.

;; ADDITIONAL SECTION:
resone.univ-rennes1.fr.	2709	IN	A	129.20.254.1
soleil.uvsq.fr.		85509	IN	A	193.51.24.1

;; Query time: 4 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:29:04 CET 2025
;; MSG SIZE  rcvd: 185

```

La commande nous dit que l'adresse IPV4 de istic.univ-rennes.fr est 129.20.126.139


Et dans l'autre sens

dig -x 129.20.126.139 nous renvoie :

```
; <<>> DiG 9.18.30-0ubuntu0.24.04.2-Ubuntu <<>> -x 129.20.126.139
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 48042
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 13, ADDITIONAL: 27

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;139.126.20.129.in-addr.arpa.	IN	PTR

;; ANSWER SECTION:
139.126.20.129.in-addr.arpa. 1341 IN	PTR	nfrontaldrupal9.univ-rennes.fr.

;; AUTHORITY SECTION:
.			253356	IN	NS	m.root-servers.net.
.			253356	IN	NS	b.root-servers.net.
.			253356	IN	NS	e.root-servers.net.
.			253356	IN	NS	d.root-servers.net.
.			253356	IN	NS	a.root-servers.net.
.			253356	IN	NS	i.root-servers.net.
.			253356	IN	NS	l.root-servers.net.
.			253356	IN	NS	c.root-servers.net.
.			253356	IN	NS	f.root-servers.net.
.			253356	IN	NS	j.root-servers.net.
.			253356	IN	NS	k.root-servers.net.
.			253356	IN	NS	h.root-servers.net.
.			253356	IN	NS	g.root-servers.net.

;; ADDITIONAL SECTION:
k.root-servers.net.	480238	IN	A	193.0.14.129
i.root-servers.net.	480238	IN	A	192.36.148.17
c.root-servers.net.	513375	IN	A	192.33.4.12
e.root-servers.net.	480238	IN	A	192.203.230.10
l.root-servers.net.	480238	IN	A	199.7.83.42
m.root-servers.net.	188330	IN	A	202.12.27.33
f.root-servers.net.	393821	IN	A	192.5.5.241
b.root-servers.net.	480238	IN	A	170.247.170.2
j.root-servers.net.	480238	IN	A	192.58.128.30
g.root-servers.net.	525089	IN	A	192.112.36.4
d.root-servers.net.	480238	IN	A	199.7.91.13
h.root-servers.net.	480238	IN	A	198.97.190.53
a.root-servers.net.	299206	IN	A	198.41.0.4
k.root-servers.net.	480238	IN	AAAA	2001:7fd::1
i.root-servers.net.	480238	IN	AAAA	2001:7fe::53
c.root-servers.net.	480238	IN	AAAA	2001:500:2::c
e.root-servers.net.	480238	IN	AAAA	2001:500:a8::e
l.root-servers.net.	480239	IN	AAAA	2001:500:9f::42
m.root-servers.net.	480239	IN	AAAA	2001:dc3::35
f.root-servers.net.	480238	IN	AAAA	2001:500:2f::f
b.root-servers.net.	480238	IN	AAAA	2801:1b8:10::b
j.root-servers.net.	480238	IN	AAAA	2001:503:c27::2:30
g.root-servers.net.	480238	IN	AAAA	2001:500:12::d0d
d.root-servers.net.	480238	IN	AAAA	2001:500:2d::d
h.root-servers.net.	480238	IN	AAAA	2001:500:1::53
a.root-servers.net.	592196	IN	AAAA	2001:503:ba3e::2:30

;; Query time: 43 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Tue Apr 01 12:01:05 CEST 2025
;; MSG SIZE  rcvd: 883

```

Et on observe que l'ip qui gère le site est nfrontaldrupal9.univ-rennes.fr



### Q7 :

dig +short SOA mozfr.org nous renvoie :
```
ns1.mozfr.org. admins.mozfr.org. 2024122201 300 300 604800 3600
```

dig +short NS mozfr.org nous renvoie :
```
ns1.he.net.
ns2.he.net.
ns3.he.net.
ns5.he.net.
ns1.mozfr.org.
ns6.gandi.net.
ns4.he.net.

```

dig AXFR mozfr.org @ns1.mozfr.org nous renvoie :
```
; <<>> DiG 9.16.44-Debian <<>> AXFR mozfr.org @ns1.mozfr.org
;; global options: +cmd
mozfr.org.		300	IN	SOA	ns1.mozfr.org. admins.mozfr.org. 2024122201 300 300 604800 3600
mozfr.org.		300	IN	TXT	"v=spf1 a mx ip4:95.142.174.97 ip6:2001:4b98:dc0:51:216:3eff:fe8e:a45a"
mozfr.org.		300	IN	AAAA	2001:4b98:dc0:51:216:3eff:fe8e:a45a
mozfr.org.		300	IN	NS	ns1.he.net.
mozfr.org.		300	IN	NS	ns1.mozfr.org.
mozfr.org.		300	IN	NS	ns2.he.net.
mozfr.org.		300	IN	NS	ns3.he.net.
mozfr.org.		300	IN	NS	ns4.he.net.
mozfr.org.		300	IN	NS	ns5.he.net.
mozfr.org.		300	IN	NS	ns6.gandi.net.
mozfr.org.		300	IN	MX	10 mail.mozfr.org.
mozfr.org.		300	IN	A	95.142.174.97
_dmarc.mozfr.org.	300	IN	TXT	"v=DMARC1; p=quarantine; pct=100;"
gandi.2021051001._domainkey.mozfr.org. 300 IN TXT "v=DKIM1; k=rsa; " "p=MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCrWfRf6ATFpEqRDQQjZ+IYg3Zt2K9xKnfUJv7yW1Bq9Awko+mnWhuYyh3nJg4J9ryPS6VvY8wGoZ8yzy+4VqtvZL4ThL0TRrCVC/a2isbkHN5CvFtf6rNg+35/C412fiv6UixMa2g29wDOFe1hto09uUOkYDhiYNkrcDDr7lkkVQIDAQAB"
aide.mozfr.org.		300	IN	CNAME	gandi.mozfr.org.
blog.mozfr.org.		300	IN	CNAME	gandi.mozfr.org.
bugzilla.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
demos.mozfr.org.	300	IN	CNAME	diplo.mozfr.org.
diplo.mozfr.org.	300	IN	AAAA	2001:41d0:2:bd5c::1
diplo.mozfr.org.	300	IN	A	188.165.242.92
firefoxos.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
beta.firefoxos.mozfr.org. 300	IN	CNAME	diplo.mozfr.org.
builds.firefoxos.mozfr.org. 300	IN	CNAME	diplo.mozfr.org.
forum.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
forums.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
gandi.mozfr.org.	300	IN	AAAA	2001:4b98:dc0:51:216:3eff:fe8e:a45a
gandi.mozfr.org.	300	IN	A	95.142.174.97
imap.mozfr.org.		300	IN	CNAME	mail.mozfr.org.
listes.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
mail.mozfr.org.		300	IN	AAAA	2001:4b98:dc0:51:216:3eff:fe8e:a45a
mail.mozfr.org.		300	IN	A	95.142.174.97
nightly.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
notreinternet.mozfr.org. 300	IN	CNAME	gandi.mozfr.org.
ns0.mozfr.org.		300	IN	AAAA	2001:41d0:2:bd5c::1
ns0.mozfr.org.		300	IN	A	188.165.242.92
ns1.mozfr.org.		300	IN	AAAA	2001:4b98:dc0:51:216:3eff:fe8e:a45a
ns1.mozfr.org.		300	IN	A	95.142.174.97
piwik.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
planet.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
planete.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
pop.mozfr.org.		300	IN	CNAME	mail.mozfr.org.
smtp.mozfr.org.		300	IN	CNAME	mail.mozfr.org.
tech.mozfr.org.		300	IN	CNAME	gandi.mozfr.org.
transvision.mozfr.org.	300	IN	CNAME	gandi.mozfr.org.
transvision-beta.mozfr.org. 300	IN	CNAME	gandi.mozfr.org.
videos-meetup2013.mozfr.org. 300 IN	A	212.71.252.116
wiki.mozfr.org.		300	IN	CNAME	gandi.mozfr.org.
www.mozfr.org.		300	IN	AAAA	2001:4b98:dc0:51:216:3eff:fe8e:a45a
www.mozfr.org.		300	IN	A	95.142.174.97
mozfr.org.		300	IN	SOA	ns1.mozfr.org. admins.mozfr.org. 2024122201 300 300 604800 3600
;; Query time: 12 msec
;; SERVER: 95.142.174.97#53(95.142.174.97)
;; WHEN: Fri Mar 14 15:33:21 CET 2025
;; XFR size: 50 records (messages 1, bytes 1547)

```

@adress spécifie le serveur DNS de la réquête

Ici on voit que l'utiliser dans une commande nous donne beaucoup plus d'informations sur l'architecture DNS du réseau. Je pense que ça doit se géréraliser et permettre de pouvoir attaquer plus spécifiquement des serveurs qu'on aurait pas trouvé sans.


### Q8 :

Le script permet de faire un mapping de l'architecture DNS 

Un attaquant pourrait récupérer des informations sur les hôtes et les services présents dans le réseau.

Là on est sûr de couvrir toutes les ip possibles.



### Q9 :

La commande renvoie presque la totalité d'internet


### Q10 :

Les enregistrement RRSIG contienent une signature cryptographique

Les enregistrement DS contiennet le hachage d'un enregristrement avec une clé de signature publique

Les enregistrements NSEC spécifient un déni implicite d'enregistrement DNS

En regardant la liste de la question 9 j'ai l'impression que beaucoup de serveur n'ont rien de tout ça et que très peu ont une signature cryptographique


## Partie II :


### Q11 :

On complete le code ainsi : 

```python
import dns
import dns.message
import socket
DNS_RESOLVER = ("9.9.9.9", 53)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # XXX Complete Here
req = dns.message.make_query(input("Enter domain name to resolve:"), "A")
print("............................................")
print(req.to_text())
print("............................................")
print("You can compare it to wireshark: ")
print(req.to_wire())
print("............................................")
sock.sendto(req.to_wire(), DNS_RESOLVER)
data, addr = sock.recvfrom(1024)
resp = dns.message.from_wire(data)
print(resp)
sock.close()
print("............................................")
```

Et le programme nous retourne : 

```
............................................
id 18642
opcode QUERY
rcode NOERROR
flags RD
;QUESTION
google.fr. IN A
;ANSWER
;AUTHORITY
;ADDITIONAL
............................................
You can compare it to wireshark: 
b'H\xd2\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00\x06google\x02fr\x00\x00\x01\x00\x01'
............................................
id 18642
opcode QUERY
rcode NOERROR
flags QR RD RA
;QUESTION
google.fr. IN A
;ANSWER
google.fr. 12 IN A 142.250.180.3
;AUTHORITY
;ADDITIONAL
............................................

```
Le record est de type A

### Q12 :

Le script nous retourne :

```
............................................
dig example.org @127.0.0.1
id 40685
opcode QUERY
rcode NOERROR
flags RD AD
edns 0
payload 1232
option COOKIE 02a8ea26aee5c966
;QUESTION
example.org. IN A
;ANSWER
;AUTHORITY
;ADDITIONAL
............................................
id 40685
opcode QUERY
rcode SERVFAIL
flags QR RD
edns 0
payload 8192
;QUESTION
example.org. IN A
;ANSWER
;AUTHORITY
;ADDITIONAL
............................................

```

C'est le script d'un serveur DNS

### Q13 :

```python

import dns
import dns.message
import socket

DNS_LOCALRSL = ("127.0.0.1", 53)
DNS_RESOLVER = ("9.9.9.9", 53)

print("............................................")

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)
print("Please execute the following command:\ndig example.org @127.0.0.1")
data, addr = s.recvfrom(1024)
req = dns.message.from_wire(data)
print (req)

print("............................................")

s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s2.sendto(data, DNS_RESOLVER)
data2, addr2 = s2.recvfrom(1024)
resp = dns.message.from_wire(data2)
print(resp)

print("............................................")

s.sendto(data2, addr)
s.close()
s2.close()

print("............................................")

```

Les messages passent par une autre adresse et sont donc moins traçable

### Q14 :


On observe (Je ne suis pas à l'istic je fais tout sur ma machine perso) :

```
136	1.968661777	127.0.0.1	127.0.0.53	DNS	89 Standard query 0x2506 A qlf-doh.inria.fr OPT
137	1.968675453	127.0.0.1	127.0.0.53	DNS	89	Standard query 0x1b02 AAAA qlf-doh.inria.fr OPT
138	1.968797602	192.168.1.3	192.168.1.254	DNS	89	Standard query 0x1f1a A qlf-doh.inria.fr OPT
139	1.968852114	192.168.1.3	192.168.1.254	DNS	89	Standard query 0xdc2a AAAA qlf-doh.inria.fr OPT
140	2.001211428	192.168.1.254	192.168.1.3	DNS	105	Standard query response 0x1f1a A qlf-doh.inria.fr A 128.93.162.64 OPT
141	2.001213852	192.168.1.254	192.168.1.3	DNS	140	Standard query response 0xdc2a AAAA qlf-doh.inria.fr SOA dns.inria.fr OPT
142	2.001515700	127.0.0.53	127.0.0.1	DNS	105	Standard query response 0x2506 A qlf-doh.inria.fr A 128.93.162.64 OPT
143	2.001601741	127.0.0.53	127.0.0.1	DNS	140	Standard query response 0x1b02 AAAA qlf-doh.inria.fr SOA dns.inria.fr OPT

```

### Q15 :

On voit que le programme fait bien passer les messages par http :

```
384	7.591562979	192.168.1.3	128.93.162.64	TLSv1.2	585	Client Hello (SNI=qlf-doh.inria.fr)
387	7.605251029	128.93.162.64	192.168.1.3	TLSv1.2	5604	Server Hello, Certificate, Server Key Exchange, Server Hello Done
389	7.607555458	192.168.1.3	128.93.162.64	TLSv1.2	194	Client Key Exchange, Change Cipher Spec, Encrypted Handshake Message
390	7.621095841	128.93.162.64	192.168.1.3	TLSv1.2	310	New Session Ticket, Change Cipher Spec, Encrypted Handshake Message
391	7.621608423	192.168.1.3	128.93.162.64	TLSv1.2	326	Application Data
392	7.623576570	192.168.1.3	128.93.162.64	TLSv1.2	120	Application Data
395	7.635732953	128.93.162.64	192.168.1.3	TLSv1.2	379	Application Data, Application Data
396	7.635733074	128.93.162.64	192.168.1.3	TLSv1.2	99	Encrypted Alert
```

Il y a aussi beaucoup de paquet DNS.

### Q16 :

```python

import dns
import dns.message
import socket
import urllib.request

DNS_LOCALRSL = ("127.0.0.1", 53)
DNS_RESOLVER = ("9.9.9.9", 53)
DOH_RESOLVER = "https://qlf-doh.inria.fr/dns-query"

print("............................................")

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)
print("Please execute the following command:\ndig example.org @127.0.0.1")
data, addr = s.recvfrom(1024)
req = dns.message.from_wire(data)

print (req)

print("............................................")
req2 = urllib.request.Request(
DOH_RESOLVER, headers={"Accept": "application/dns-json"}, data=req.to_wire()
)
print(req2)


print("............................................")

resp = urllib.request.urlopen(req2)
data2 = resp.read()
print(dns.message.from_wire(data2))

print("............................................")

s.sendto(data2, addr)
s.close()

print("............................................")

```

### Q17 :

Comme on peut le voir sur cette page : https://www.nlnetlabs.nl/projects/unbound/security-advisories/ il y a un certain nombre d'attaques possibles 


