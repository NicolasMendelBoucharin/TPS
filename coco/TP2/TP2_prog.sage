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


#calcul des q-classes cyclotomiques modulo n
#entrée : q, n, s
#sortie : dictionnaire des q-classes cyclotomiques modulo n

def cycloclassset(q, n):
    d={}
    
    for s in range(0,n):
        c=cycloclass(q,n,s)
        if c not in d.values():
            d[s]=c
    return(d)


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


#calcul des facteurs unitaires de X^n-1 dans Fq[X]
#entrée : n, q
#sortie : ensemble des facteurs unitaires irréductibles de X^n-1 dans Fq[X]

def ma_factorisation(n,q):
    L=[]
    for value in cycloclassset(q,n):
        L.append(polmin(racineprimitive(q,n), value, q, n))
    return set(L)

#factorisation de X^n-1 dans Fq[X]
#entrée : n, q
#sortie : polynôme factorisé

def factorisationjoli(n,q):
    L=ma_factorisation(n,q)
    L=list(L)
    chaine=f"({L[0]})"
    for i in range(1,len(L)):
        chaine=chaine+" * "+f"({L[i]})"
    return chaine