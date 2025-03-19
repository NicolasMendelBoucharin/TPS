#Poids d'un mot
#entrée : c, sous forme de vecteur ou de liste
#sortie : poids de Hamming de c
def Poids(c):#poids d'un mot défini sous forme de vecteur ligne
	res = 0
	n = len(c)
	for i in range(n):
		if not(c[i]==0):
			res=res+1
	return(res)

#algorithme de recherche exhaustive
#entrée : un corps Fq, n, k , alpha, r
#sortie : f

def exhaustivesearch(Fq, n, k, alpha, r):
    t=floor((n-k)/2)
    Fqx.<X>=PolynomialRing(Fq)
    V=VectorSpace(Fq, k)
    for u in v:
        f=0
        for i in range(k):
            f+=u[i]*X^i
        verification=True
        for i in range(n):
            if Poids(f(alpha^i)-r[i])<t:
                verification=False
                break
        if verification:    
            return(f)
    return("pas de solution")

#algorithme de recheche exhaustive par interpolation
#entrée : Fq, n, k, alpha, r
#sortie : f

def exhaustiveinterpolation(Fq, n, k, alpha, r):
    t=floor((n-k)/2)
    return None

#algorithme de welch berlekamp
#entrée Fq, n, k, alpha, r
#sortie : f

def welchberlekamp(Fq, n, k, alpha, r):
    t=floor((n-k)/2)
    return None 


