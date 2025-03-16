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