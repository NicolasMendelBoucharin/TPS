## Exercice 1.

print("Exercice 1 \n")

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

print("Exercice 2 \n")

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

### Exercice 3.
print("Exercice 3 \n")

### a)

print("a) \n")

