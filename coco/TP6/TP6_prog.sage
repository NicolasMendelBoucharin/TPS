#Poids d'un mot
#entrée : c, sous forme de vecteur ou de liste
#sortie : poids de Hamming de c

def Poids(c):
	res = 0
	n = len(c)
	for i in range(n):
		if not(c[i]==0):
			res=res+1
	return(res)


#chiffrement de Niederreiter
#entrée : un mot e, t une puissance plus grande que le poids du mot et T la clé publique
#sortie : le mot chiffré S

def chiffrement(e, m, t, T):
    if Poids(e)>t:
        raise ValueError("Le poids du mot e est supérieur à t")
    
    k=m*t
    I=identity_matrix(k)
    H=block_matrix([[I, T]])
    S=e*H.transpose()
    return S

#algorithme d'euclide étendu jusqu'à un certain degré
#entrée : deux polynômes P, Q  un degré t
#sortie : sigma et w

def euclidedecodagebch(P, S, t):
    R0=P
    R1=S
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


#dechiffrement de Niederreiter
#entrée : c le mot chiffré, n la taille du code, g le polynôme générateur, L les racines de g et t la distance
#sortie : le mot décodé e

def dechiffrement(c, n, g, L, t):

    c=c.list()
    while len(c)<n:
        c.append(0)
    c=vector(GF(2), c)
    S = sum([c[i]*inverse_mod((x-L[i]), g**2) for i in range(n)])
    sigma, _ = euclidedecodagebch(g**2, S, t)
    print(sigma)
    racines= sigma.roots(multiplicities=False)
    print(f"Les {len(racines)} racines : {racines}")
    e=[0]*n
    
    for r in racines:
        if r in L:
            i=L.index(r)
            e[i]=1
        else:
            print("prout")
    
    return vector(GF(2),e)


    