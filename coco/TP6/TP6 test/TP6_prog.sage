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

def euclidedecodagebch(S, g, t):
   
    R0, R1 = g(z), S
    V0, V1 = 0, 1
    while R1.degree()>=t:
        q=R0//R1
        R0, R1 = R1, R0 - q*R1
        V0, V1 = V1, V0 - q*V1
        
    return (V1/V1(0), R1/V1(0))


#dechiffrement de Niederreiter
#entrée : c le mot chiffré, n la taille du code, g le polynôme générateur, L les racines de g et t la distance
#sortie : le mot décodé e

def dechiffrement(c, n, g, L, t):

    c=c.list()
    while len(c)<n:
        c.append(0)
    c=vector(GF(2), c)
    
    S = sum([c[i]*inverse_mod((z-L[i]), g**2) for i in range(n)])
    
    sigma, _ = euclidedecodagebch(S, g**2, t)
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


    