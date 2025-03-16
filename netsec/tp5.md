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

On observe :

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
nodnssec choisi pour nous le serveur m.root-servers.net.

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

dig +short istic.univ-rennes.fr nous renvoie :

```
129.20.126.139
```

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
dig -x IPAddress.ReturnedBy.Previous.Command nous renvoie :

```
; <<>> DiG 9.16.44-Debian <<>> -x IPAddress.ReturnedBy.Previous.Command
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 38132
;; flags: qr rd ra ad; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 4096
; COOKIE: 9068c5ab72271b9de85a037967d43d81a587c690835499b7 (good)
;; QUESTION SECTION:
;Command.Previous.ReturnedBy.IPAddress.in-addr.arpa. IN PTR

;; AUTHORITY SECTION:
in-addr.arpa.		3600	IN	SOA	b.in-addr-servers.arpa. nstld.iana.org. 2024122522 1800 900 604800 3600

;; Query time: 1179 msec
;; SERVER: 148.60.15.109#53(148.60.15.109)
;; WHEN: Fri Mar 14 15:30:25 CET 2025
;; MSG SIZE  rcvd: 175

```


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

### Q8 :




### Q9 :

dig AXFR . @f.root-servers.net | grep -Ev 'NSEC|DS|RRSIG' est un serveur racine central qui nous donne tout ce qu'il sait sur les entrées qu'il connaît (toutes les informations mondiales, donc une très grande partie d'internet) :

```

```


### 10 :


## Partie II :

### Q11 :



