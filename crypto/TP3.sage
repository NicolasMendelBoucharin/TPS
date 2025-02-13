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

print("Avec sage on a n(P) =", poltoint(Q), "\n")

### c)

def poltohex(P):
    return hex(poltoint(P))

def hextopol(h):
    l=list(bin(h))
    l=l[2:]
    l.reverse()
    P=R(l)
    return(P)

print(Q, "est converti en", poltohex(Q), "\n")
print(0x57, "est converti en", hextopol(0x57), "\n")

### d)

def sommehex(hex1, hex2):
    return(poltohex(hextopol(hex1)+hextopol(hex2)))
print("On a bien en faisant une addition polynômiale que ", 0x57, "+", 0x83, "=", sommehex(0x57, 0x83), "\n")

### e)

#fonction auxiliaire pour faire une multiplication par X
def foisX(P):
    plist=P.list()
    #pour mettre en liste de bonne taille
    if len(plist)<8:
        plist += [0 for i in range(8-len(plist)+1)]
        
       
    #si a7 est nul on fait juste un bit shift
    if plist[7]==0:
        for i in range(len(plist)-1):                
            plist[len(plist)-(i+1)]=plist[len(plist)-(i+2)]
        plist[0]=0
        return(R(plist))
    #si a7 est non nul on fait un bit shift et un xor
    if plist[7]==1:
        for i in range(len(plist)-1):
            plist[len(plist)-(i+1)]=plist[len(plist)-(i+2)]
        plist[0] = 1
        plist[1] += 1
        plist[3] += 1
        plist[4] += 1
        return(R(plist))
   

def multiplicationpol(P, Q):
    qlist=Q.list()
    #pour mettre en liste de bonne taille
    if len(qlist)<8:
        qlist += [0 for i in range(8-len(qlist)+1)]
    t=0
    S=P
    #comme dans le td
    for i in range(8):
        if qlist[i]==1:
            t += S
        S=foisX(S)    
    return t

def multiplicationhexa(hex1, hex2):
    return(poltohex(multiplicationpol(hextopol(hex1), hextopol(hex2))))

### f)

print("Avec l'algorithme du TD on trouve :", multiplicationhexa(0x57, 0x83), "\n")

### g)

S = R.quotient(P)
print("en utilisant directement la définition de quotient on trouve aussi :", poltohex((hextopol(0x57)*hextopol(0x83))%P), "\n")

### h)

F256.<Y>=GF(2**8, modulus=P)
H=Y+1
print("L'ordre multiplicatif de X+1 est : ", H.multiplicative_order(), "il est donc bien primitif \n")

### i)

pol2exp=[0 for i in range(256)]
for i in range(1,256):
    pol2exp[poltoint(H**i)]=i

print("La liste des exposants est :", pol2exp, "\n")

### j)

exp2pol=[0 for i in range(256)]
exp2pol[0]=1
for i in range(1, 255):
    exp2pol[i]=poltohex(H**i)

print("La liste inverse est: ", exp2pol, "\n")

### k )


    

