#calcul de la q-classe cyclotomique modulo n de s
#entrée : q, n, s
#sortie : q-classe cyclotomique modulo n de s

def cycloclass(q, n, s):
    ordremin=1
    L=[s]
    while (s*q**ordremin%n not in L):
        L.append(s*q**ordremin%n)
        ordremin+=1
    return(set(L))


#calcul d'une racine primitive de l'unité dans une extension de Fq
#entrée : n, q
#sortie : racine primitive n**e de l'unité dans une extension de Fq

def racineprimitive(q,n):
#donne une racine primitive n**e de l'unité dans une extension de Fq
    m=len(cycloclass(q,n,1))
    F=GF(q**m)
    g=F.gen()
    return(g**Integer((q**m-1)/n))


#calcul polynôme minimal de alpha**s
#entrée : alpha, s, q, n
#sortie : polynôme minimal de alpha**s

def polmin(alpha, s, q, n):
    classe= cycloclass(q,n,s)
    M=1
    for i in classe:
        M=M*(x-alpha**i)
    return M

#calcul du polynôme générateur
#entrée : alpha, d la distance préscrite, n, q
#sortie : polynôme générateur

def polgen(alpha, d):
    L=[]
    for i in range (1, d):
        L.append((alpha**i).minimal_polynomial())
    L=set(L)
    g=lcm(L)
    return g

#décodage avec algorithme d'euclide étendu jusqu'à un certain degré
#entrée : deux polynômes P, Q  un degré t
#sortie : sigma et w

def euclidedecodagebch(P, Q, t):
    R0=P
    R1=Q
    v0=0
    v1=1
    while R1.degree()>=t:
        q=R0.quo_rem(R1)[0]
        R2=R0-R1*q
        R0=R1
        R1=R2
        v2=v0-v1*q
        v0=v1
        v1=v2
    return (v1/v1(0), R1/v1(0))

#donne les Y_i
#entrée : sigma le polynôme générateur
#sortie : liste des Y_i


def trouverlesy(alpha, omega, indices):   
    X_=[alpha**i for i in indices]
    Y_=[0 for i in range(len(X_))]
    for i in range(len(X_)):
        Y_[i]=(X_[i]**(-1))*omega(X_[i]**(-1))
        partiedroite=1
        for Xj in X_ :
            if Xj!=X_[i]:
                partiedroite=partiedroite*(1-(X_[i])**(-1)*Xj)
        Y_[i]=Y_[i]*partiedroite**(-1)
    return Y_

            
#décodage d'un mot de code
#entrée : alpha, d la distance préscrite, n la taille du code, y le mot codé
#sortie : le mot décodé 

def decodage(n, d, alpha, y):
    
    R=y.parent()
    x=R.gen()
    
    g=polgen(alpha, d)
    
    F=alpha.parent()
    Fz.<z>=PolynomialRing(F)
    
    t=floor((d-1)/2)
    
    P=z**(2*t)
    S=[]
    for i in range(2*t):
        S.append(y(alpha**(i+1)))
    s=0
    for i in range(2*t):
        s+=S[i]*z**i
    sigma, omega = euclidedecodagebch(P, s, t)
    
    racines=sigma.roots(multiplicities=false)
    indices=[(raci**(-1)).log(alpha) for raci in racines]
   
    Y_=trouverlesy(alpha, omega, indices)
    
    erreur=0
   
    for i in range(len(indices)):
        erreur=erreur+Y_[i]*x**indices[i]
    
    motdecode=(y-erreur)/g
    
    return (motdecode)
    
    






