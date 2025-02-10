## Exercice 1 :

### a)

F=GF(2)
R.<X> = PolynomialRing(F)

### b)

P = X^8 + X^4 + X^3 + X + 1
Q=X^6 + X^4 + X^2 + X + 1

def poltoint(P):
    l=P.list() 
    intp=0
    for k, i in enumerate(l):
       i=int(i)
       intp+=i*2**k
    return intp

print(poltoint(Q))

### c)

def poltohex(P):
    return hex(poltoint(P))

def hextopol(h):
    l=list(bin(h))
    l=l[2:]
    l.reverse()
    P=R(l)
    return(P)

print(poltohex(Q))
print(hextopol(0x57))

### d)

print(hex(0x57+0x83))

### e)

### f)

### g)

S = R.quotient(P)
print(poltohex((hextopol(0x57)*hextopol(0x83))%P))

### h)

### i)



