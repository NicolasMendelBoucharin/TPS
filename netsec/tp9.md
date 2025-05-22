# Partie 1 :

### Question 1 : 

Pour Nicolas : `192.168.1.20/24`, pour Julie : `192.168.1.24/24`,  pour Elouan : `192.168.1.23/24`, pour Emmy : `192.168.1.13/24`

### Question 2 : 

J'ai pu changer mon adresse en `192.168.1.34/24` avec la commande 

```
ip addr add 192.168.1.34/24 dev wlp2s0
```

### Question 3 :

Comme partout c'est `192.168.1.1`

### Question 4 :

Une interface de connexion, mais il faut un mot de passe qu'on a trouvé

### Question 5 : 

fait

### Question 6 : 

fait

### Question 7 :

On a réussi à faire une redirection de port vers ma machine (le changement de port au début n'a servi à rien)


```
__________			 connexion       _________________	    firewall       ___________________
|visiteur| <-------------------> |box:192.168.1.1| <-----------------> |192.168.1.80:8080|
|________|	   sur le port 80    |_______________|     redirection     |_________________|

```


## Partie II : 


### Question 8 :

`dig ns netsec2223.eu.org` nous dit que le fournisseur est dynv6 sur les machines ns1,2,3.dynv6.com

### Question 9 :

Il demande d'abord à celui qui a .org puis .eu.org puis... 

### Question 10 :

On tape la commande suivante : 

```
curl \
    -H "Authorization: Bearer XCqXvdqJMWY1GEyCdcBZZWnwm4F6Ub" \
    -H "Accept: application/json" \
    https://dynv6.com/api/v2/zones
```

Et on a le retour suivant :

```
[{"name":"hackme.goessens.fr","ipv4address":"148.60.11.246","ipv6prefix":"","id":4507942,"createdAt":"2024-11-27T14:24:02+01:00","updatedAt":"2024-11-27T14:24:02+01:00"},
{"name":"netsec2223.eu.org","ipv4address":"148.60.11.246","ipv6prefix":"2001:db8:85a3::8a2e:370:7334","id":3582646,"createdAt":"2022-11-15T14:24:17+01:00","updatedAt":"2022-11-15T14:24:17+01:00"},
{"name":"tp10.goessens.fr","ipv4address":"","ipv6prefix":"","id":3941821,"createdAt":"2023-11-29T20:19:03+01:00","updatedAt":"2023-11-29T20:19:03+01:00"}]
```

L'id pour netsec2223.eu.org est 3582646

### Question 11 :

On tape la commande suivante : 


```
curl \
    -H "Authorization: Bearer XCqXvdqJMWY1GEyCdcBZZWnwm4F6Ub" \
    -H "Accept: application/json" \
    https://dynv6.com/api/v2/zones/3582646/records | jq '[ .[] | { name: .name, data: .data} ]'
```

Et on a le retour suivant :

```
[
  {
    "name": "foobar",
    "data": "8.8.8.8"
  },
  {
    "name": "demo",
    "data": "142.250.201.163"
  },
  {
    "name": "kcallac",
    "data": "83.197.137.105"
  },
  {
    "name": "ttma",
    "data": "176.174.230.157"
  },
  {
    "name": "nemo-and-the-submarines",
    "data": "82.64.134.167"
  },
  {
    "name": "salade2fruits",
    "data": "80.67.171.37"
  },
  {
    "name": "etlabeau",
    "data": "176.143.122.228"
  },
  {
    "name": "truc2zinzin",
    "data": "2.10.189.39"
  },
  {
    "name": "shadocks",
    "data": "176.188.248.135"
  },
  {
    "name": "bob_love_volleyball",
    "data": "92.131.141.180"
  },
  {
    "name": "frahmani",
    "data": "80.67.171.50"
  },
  {
    "name": "cyberschool2077",
    "data": "88.127.189.78"
  },
  {
    "name": "gingerbreadman-team",
    "data": "91.165.120.232"
  },
  {
    "name": "tptrdo",
    "data": "86.215.155.236"
  },
  {
    "name": "testtp",
    "data": "80.67.171.40"
  },
  {
    "name": "ntkd",
    "data": "80.67.171.46"
  },
  {
    "name": "ntkd",
    "data": "2001:910:802:2::100c"
  },
  {
    "name": "padamalgam",
    "data": "91.175.62.238"
  },
  {
    "name": "padamalgam",
    "data": "91.175.62.238"
  },
  {
    "name": "unsiteinternet",
    "data": "92.162.233.76"
  },
  {
    "name": "wallaceetgromit",
    "data": "88.140.179.190"
  },
  {
    "name": "goodbyeworld",
    "data": "82.65.77.52"
  },
  {
    "name": "lastchance",
    "data": "83.197.116.46"
  },
  {
    "name": "padamalgam",
    "data": "2a01:e0a:3cf:bbb0::1"
  },
  {
    "name": "mimichelaqueen",
    "data": ""
  },
  {
    "name": "iloveonepiece",
    "data": "80.67.171.49"
  },
  {
    "name": "mimiche",
    "data": "80.67.171.37"
  },
  {
    "name": "foobar2324",
    "data": "8.8.8.8"
  },
  {
    "name": "touloooonnnn",
    "data": ""
  },
  {
    "name": "example.com",
    "data": "80.67.171.14"
  },
  {
    "name": "defaultmodel",
    "data": "146.70.194.3"
  },
  {
    "name": "rat.io",
    "data": "83.205.70.93"
  },
  {
    "name": "pedro",
    "data": "83.199.11.226"
  },
  {
    "name": "la.moula",
    "data": "80.67.171.29"
  },
  {
    "name": "alifabio",
    "data": "80.67.165.110"
  },
  {
    "name": "rat.io",
    "data": "83.205.70.93"
  },
  {
    "name": "controlecontinue",
    "data": "83.205.70.93"
  },
  {
    "name": "dinostore",
    "data": "80.67.165.124"
  },
  {
    "name": "e.e",
    "data": "92.131.192.217"
  },
  {
    "name": "e.t",
    "data": "92.131.192.217"
  },
  {
    "name": "guettelautomoncousin",
    "data": "80.67.165.96"
  },
  {
    "name": "guettelaspifouette",
    "data": "83.205.1.3"
  },
  {
    "name": "lesbgdlastreet",
    "data": "80.67.171.50"
  },
  {
    "name": "lesbgdecyber",
    "data": "80.67.171.50"
  },
  {
    "name": "lolkey",
    "data": "80.67.165.100"
  },
  {
    "name": "subdomain",
    "data": "192.168.1.1"
  },
  {
    "name": "cake",
    "data": "83.205.36.97"
  },
  {
    "name": "lesbgdelanight",
    "data": "80.67.165.107"
  },
  {
    "name": "lowkeybg",
    "data": "80.67.165.69"
  },
  {
    "name": "eniemetest",
    "data": "80.67.165.71"
  },
  {
    "name": "cosmiclink",
    "data": "176.188.240.17"
  },
  {
    "name": "pepitedechocolat",
    "data": "83.205.36.97"
  },
  {
    "name": "*",
    "data": "letsencrypt.org"
  },
  {
    "name": "kombatfriedchiken",
    "data": "80.67.171.37"
  },
  {
    "name": "toto",
    "data": "80.67.165.107"
  },
  {
    "name": "hakmounino",
    "data": "80.67.165.119"
  },
  {
    "name": "alannnnn",
    "data": "80.67.165.117"
  },
  {
    "name": "alloooo",
    "data": "80.67.171.44"
  },
  {
    "name": "neeetttsec2324",
    "data": "80.67.171.59"
  },
  {
    "name": "test2024",
    "data": "80.67.171.53"
  },
  {
    "name": "inbusiness",
    "data": "82.67.88.131"
  },
  {
    "name": "example",
    "data": "8.8.8.8"
  },
  {
    "name": "jesuismalade",
    "data": "80.67.171.34"
  },
  {
    "name": "noinspiration",
    "data": "80.67.165.99"
  },
  {
    "name": "kanareservor",
    "data": "176.188.226.164"
  },
  {
    "name": "lereveildetom",
    "data": "92.139.98.10"
  },
  {
    "name": "example",
    "data": "8.8.8.8"
  },
  {
    "name": "example4",
    "data": "80.67.171.20"
  },
  {
    "name": "waiat",
    "data": "80.67.171.40"
  },
  {
    "name": "example22",
    "data": "80.67.171.48"
  },
  {
    "name": "merland",
    "data": "80.67.171.51"
  },
  {
    "name": "ec87dd24",
    "data": "80.67.171.61"
  },
  {
    "name": "ecl7dd24",
    "data": "80.67.165.100"
  },
  {
    "name": "bergamot",
    "data": "109.223.45.96"
  },
  {
    "name": "blacktea",
    "data": "90.40.245.18"
  },
  {
    "name": "mgo202412",
    "data": "80.67.171.43"
  },
  {
    "name": "c1ph3rc0d3",
    "data": "80.67.171.15"
  },
  {
    "name": "tabouret",
    "data": "80.67.171.60"
  },
  {
    "name": "bisouslaoutusais",
    "data": "78.113.74.28"
  },
  {
    "name": "uwu",
    "data": "86.229.222.114"
  },
  {
    "name": "c1ph3rc0d3",
    "data": "2001:910:802:2::100d"
  },
  {
    "name": "necliquezsurtoutpas",
    "data": "80.67.171.59"
  },
  {
    "name": "m4n4k",
    "data": "192.0.2.0"
  },
  {
    "name": "uwu",
    "data": "2a01:cb08:828f:4600:3581:607c:7c54:49c8"
  },
  {
    "name": "melbcom",
    "data": "86.223.122.73"
  },
  {
    "name": "raph-juju",
    "data": "80.67.171.35"
  },
  {
    "name": "raph-juju",
    "data": "80.67.165.89"
  },
  {
    "name": "raph-juju",
    "data": "80.67.165.89"
  },
  {
    "name": "raph-juju",
    "data": "80.67.165.118"
  },
  {
    "name": "raph-juju2",
    "data": "80.67.165.118"
  },
  {
    "name": "raph-juju3",
    "data": "80.67.171.33"
  },
  {
    "name": "raph-juju4",
    "data": "80.67.171.26"
  },
  {
    "name": "sabrelaser",
    "data": "1.2.3.4"
  },
  {
    "name": "netsec-mon-tho-rahe",
    "data": "176.188.224.189"
  },
  {
    "name": "dangerous-mother-fucker",
    "data": "80.67.165.120"
  },
  {
    "name": "site",
    "data": "80.67.165.115"
  },
  {
    "name": "newrecord",
    "data": "2001:910:802:2::1020"
  },
  {
    "name": "dontbemad",
    "data": "85.68.149.140"
  },
  {
    "name": "melb.com",
    "data": "81.53.192.128"
  },
  {
    "name": "netsec-mon-tho-rahe",
    "data": "176.188.224.189"
  },
  {
    "name": "may2025",
    "data": "148.60.11.246"
  },
  {
    "name": "may2025-2",
    "data": "148.60.11.246"
  }
]

```

### Question 12

``` (pas sûr du tout)
curl \
    -H "Authorization: Bearer XCqXvdqJMWY1GEyCdcBZZWnwm4F6Ub" \
    -H "Accept: application/json" \
    -H "Content-Type: application/json" \
    -d '{"name":"piedsouaisselles", "data":"90.19.119.32","type":"A","port": 80}' \
     -X POST https://dynv6.com/api/v2/zones/3582646/records


```

### Question 13



### Question 14

```
__________			 connexion       ___________________________	         
|visiteur| <-------------------> |foobar.netsec22223.eu.org|
|________|	   sur le port 80    |_________________________|     

  regarde dans le record   _______________________               _________________
<------------------------->|data=ip.addr, port=80| <-----------> |box=192.168.1.1|
      où name=foobar       |_____________________|  redirection  |_______________|

    firewall      ___________________
<---------------> |192.168.1.80:8080|
   redirection    |_________________|

```


# Partie 3




