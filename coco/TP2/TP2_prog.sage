#TP1 Codes Correcteurs 2025 : codes linéaires, les programmes

#calcul de la q-classe cyclotomique modulo n de s
#entrée : q, n, s
#sortie : q-classe cyclotomique modulo n de s

def cycloclass(q, n, s):
    ordremin=1
    while (s*q**ordremin%n != s):
        ordremin+=1
    return([s*q**i%n for i in range(ordremin)])

#calcul des q-classes cyclotomiques modulo n
#entrée : q, n, s
#sortie : dictionnaire des q-classes cyclotomiques modulo n

def cycloclass(q, n):
    d={}
    for s in range(n):
        d[k]=cycloclass(q, n, s)

#calcul d'une racine primitive de l'unité dans une extension de Fq
#entrée : n, q
#sortie : racine primitive n**e de l'unité dans une extension de Fq
def racineprimitive(L):
    
    
    return None


#calcul polynôme minimal de alpha**s
#entrée : alpha, s, q, n
#sortie : polynôme minimal de alpha**s

def polmin(alpha, s, q, n):
    classe= cycloclass(q,n,s)
    M=1
    alpha=racineprimitive
    for i in classe:
        M=M*(X-alpha**i)
    return M

def facteursunitaire(n,q):
    return None
