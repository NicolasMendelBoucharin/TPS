## Exercice 1.
print("Exercice 1 :\n")

### a)
print("a) \n")

def chiffrementrsa(m, e, n):
    return power_mod(m, e, n)

print("Le chiffrement de 9 avec e=5 et n=85 est", chiffrementrsa(9, 5, 85), "\n")

### b)
print("b) \n")

def dechiffrementrsa(c, d, n):
    return power_mod(c, d, n)

print(f"le déchiffrement de 59 avec d={inverse_mod(5,64)} et n=85 est", dechiffrementrsa(59, inverse_mod(5,64), 85), "\n")

### c)
print("c) \n")

def dechiffrementrsachinois(c, d, n, p, q):
    dp = d % (p-1)
    dq = d % (q-1)
    
    cdp=power_mod(c, dp, p)
    cdq=power_mod(c, dq, q)

    nq=inverse_mod(p, q)
    np=inverse_mod(q, p)
    #on applique le CRT
    return (cdp*q*np + cdq*p*nq) % n
    
print("Le déchiffrement de 59 avec d=29, n=85, p=5 et q=17 est", dechiffrementrsachinois(59, 29, 85, 5, 17), "\n")

### d)
print("d) \n")

def generationcléaleatoire(t):
    p=1
    q=1
    
    while not is_pseudoprime(p):
        p=randint(2^(t/2), 2^(t/2+1)-1)
    while not is_pseudoprime(q):
        q=randint(2^(t/2), 2^(t/2+1)-1)
    n=p*q
    #on trouve un d premier avec (p-1)(q-1)
    d=2
    while not gcd(d, (p-1)*(q-1))==1:
        d=randint(3, (p-1)*(q-1))
    #on s'en sert pour trouver e
    e=inverse_mod(d, (p-1)*(q-1))
    return(n, p, q, e, d)

### e)
print("e) \n")

n, p, q, e, d = generationcléaleatoire(30)
print(f"On a généré les clés e={e} et d={d} pour n={n}, p={p}, q={q} \n")

### f)
print("f) \n")

m=randint(2^30, 2^31-1) #on génère un message de 30 bits
t=cputime()
chiffrementrsa(m, e, n)
print(f"Le chiffrement a pris {cputime()-t} secondes \n")

### g,h)
print("g,h) \n")

n, p, q, e, d = generationcléaleatoire(1024)
m=randint(1, n) #on génère un message de 1024 bits
t=cputime()
c=chiffrementrsa(m, e, n)
print(f"Le message m={m} a été chiffré en c={c} en {cputime()-t} secondes \n")
t=cputime()
m=dechiffrementrsa(c, d, n)
print(f"Le message c={c} a été déchiffré en m={m} en {cputime()-t} secondes avec le déchiffrement naif \n")
t=cputime()
m=dechiffrementrsachinois(c, d, n, p, q)
print(f"Le message c={c} a été déchiffré en m={m} en {cputime()-t} secondes avec le déchiffrement chinois \n")

print("On voit que le déchiffrement chinois va plus vite d'un facteur 3(pas de 4 comme dans le cours par contre)")

## Exercice 2.
print("Exercice 2 :\n")

### a)
print("a) \n")

def square_and_multiply(g,a,n):
    h=1
    b=bin(a)[2:]
    for i in range(len(b)):
        h=power_mod(h, 2, n)
        if b[i]=="1":
            h=(h*g)%n
    return h
# Pour la suite on l'a pas fait en alba

## Exercice 3.
print("Exercice 3 :\n")

#J'ai complétement copié collé les fonctions de quelqu'un d'autre comme je suis jamais allé en alba

def decomposition(n):
    v=0
    q=n-1
    while q%2==0:
        v+=1
        q=q/2
    return (v,q)

def temoin_miller_rabin(n,a,v,q):
    x=Integer(a).powermod(q,n)
    if x==1%n or x==-1%n:
        return False
    for j in range(v):
        x=x^2%n
        if x==-1%n:
            return False
    return True
    
def miller_rabin_composite_test(n,k):
    (v,q)=decomposition(n)
    for i in range(k):
        a=randrange(n)+1
        if temoin_miller_rabin(n,a,v,q):
            return print("n is composite")
    return print("n is probably prime")

### a)
print("a) \n")

def generationcléaleatoirebis(t):
    p=1
    q=1
    nbtests=2
    while not is_pseudoprime(p):
        nbtests+=1
        p=randint(2^(t/2), 2^(t/2+1)-1)
    while not is_pseudoprime(q):
        nbtests+=1
        q=randint(2^(t/2), 2^(t/2+1)-1)
    n=p*q
    #on trouve un d premier avec (p-1)(q-1)
    d=2
    nbtests+=1
    while not gcd(d, (p-1)*(q-1))==1:
        nbtests+=1
        d=randint(3, (p-1)*(q-1))
    #on s'en sert pour trouver e
    e=inverse_mod(d, (p-1)*(q-1))
    return(n, p, q, e, d, nbtests)
t=cputime()
n, p, q, e, d, nbtests = generationcléaleatoirebis(1024)
t=cputime()-t
print(f"On a généré les clés e={e} et d={d} pour n={n}, p={p}, q={q} avec {nbtests} tests en {t} secondes \n")


### d)
print("d) \n")

p=next_prime(2^100)
t0=cputime()
miller_rabin_composite_test(p, 10)
t0=cputime()-t0
print(f"Le test de Miller-Rabin a pris {t0} secondes pour {p}\n")
t1=cputime()
is_prime(p)
t1=cputime()-t1
print(f"Le test de primalité de sage a pris {t1} secondes pour {p}\n")
t2=cputime()
is_pseudoprime(p)
t2=cputime()-t2
print(f"Le test de pseudo primalité a pris {t2} secondes pour {p} \n")

p=next_prime(2^1024)
t0=cputime()
miller_rabin_composite_test(p, 10)
t0=cputime()-t0
print(f"Le test de Miller-Rabin a pris {t0} secondes pour {p}\n")
t1=cputime()
is_prime(p)
t1=cputime()-t1
print(f"Le test de primalité de sage a pris {t1} secondes pour {p}\n")
t2=cputime()
is_pseudoprime(p)
t2=cputime()-t2
print(f"Le test de pseudo primalité a pris {t2} secondes pour {p} \n")

## Exercice 4.
print("Exercice 4 :\n")

#par contre j'ai fait avec le truc de wikipédia pas le cours
def pmoins1methode(n):
    #on prend un grand B
    B=100000
    M=1
    for q in range(2, B):
        if is_prime(q):
            M*=power_mod(q, floor(log(B, q)), n)
    a=randint(2, n-1)
    while gcd(a, n)!=1:
        a=randint(2, n-1)
    g=gcd(power_mod(a, M, n)-1, n)
    if g!=1 and g!=n:
        return g
    else: 
        print("pas de facteur avec ce B")

n = 117827681420271584017432903522327303325344948050665323956545863
q=pmoins1methode(n)
p=n//q
print(f"On a trouvé une factorisation de n={n} avec p={p} et q={q} \n")

## Exercice 5.
print("Exercice 5 :\n")

n=4433634977317959977189716351978918572296527677331175210881861

x=ceil(sqrt(n))
print(x)
y=x**2-n
y=sqrt(y)
p=x+y
q=x-y
print(p*q==n)
print(f"On a trouvé une factorisation de n={n} avec p={p} et q={q} \n")



## Exercice 6 : 
print("Exercice 6 :\n")

n1=2828397017089907131052840387106128713282514421195726109593859
n2=3093736383172883855913466918447482558463408826373170329533707
n3=4495119919511106064205284407123143309601197579854381074387973

c1=161340658484276930595607630148167439628632052300968205657282
c2=2920025432866783050696766042954529191133978814738805935291595
c3=742851878532958654303493521961761568283962501737283926134034

m3=crt([c1, c2, c3], [n1, n2, n3])
m=m3**(1/3)
print(f"Le message est {m} \n")

## Exercice 7 :
print("Exercice 7 :\n")

### a)


def fractionscontinues(a,n):
    L=[]
    for i in range(2, n+2):
        if a is Integer:
            L.append(a)
            return L
        b=floor(a)
        L.append(b)
        a=1/(a-b)
    return L

### c)

def fractionscontinuesbis(a,n):
    L=[]
    p=[0, 1]
    q=[1, 0]
    for i in range(2, n+2):
        if a.is_integer():
            L.append(a)
            return L
        b=floor(a)
        L.append(b)
        a=1/(a-b)
        p.append(b*p[i-1]+p[i-2])
        q.append(b*q[i-1]+q[i-2])
    return L, p, q

### d)

#Si la clé privée d choisie est trop petite on peut faire une attaque de wiener

### e)
print("e) \n")

n = 2630048851947048265274043876774585976831617720728227254753421
e = 60177566799353897687038964037333604046539474788802464201235
_, _, q = fractionscontinuesbis(e/n, 50)
d=-1
for qi in q:
    if power_mod(17, e*qi, n) == 17:
        d=qi
        
print(f"Avec l'attaque de Wiener on trouve d={d} \n")

### f)

#Je sais pas comment faire
  
## Exercice 8 :
print("Exercice 8 :\n")

### a)

def marchealea(a,b,g, h,w):
    if w%3==0:
        return (h*w, a, b+1)
    elif w%3==1:
        return(w**2, 2*a, 2*b)
    else:
        return (g*w, a+1, b)
    
def pollard1(h, g, p):
    l=GF(p)(g).multiplicative_order()
    w, a, b = g, 1, 1
    W=[]
    A=[]
    B=[]
    compteur=0
    while not w in W:
        W.append(w)
        A.append(a)
        B.append(b)
        w, a, b = marchealea(a, b, g, h, w)
        w=w%p
        compteur+=1
    n = (a -A[compteur]/b[compteur] - b)
    return n%l

### b)

### c)

def pollard2(h, g, p):
    l=GF(p)(g).multiplicative_order()
    w, a, b = g, 1, 1
    z, c, d =  g, 1, 1
    
    w, a, b = marchealea(a, b, g, h, w)
    z, c, d = marchealea(c, d, g, h, z)
    w=w%p
    z=z%p
    
    while not w==z:
        w, a, b = marchealea(a, b, g, h, w)
        z, c, d = marchealea(c, d, g, h, z)
        w=w%p
        z=z%p
    
    return (a-c)/(b-d) %l

###d)
print("d) \n")
p=next_prime(2^30)
h=randint(1, p-1)
g=randint(1, p-1)
print(f"On a choisi p={p}, h={h} et g={g} \n")

