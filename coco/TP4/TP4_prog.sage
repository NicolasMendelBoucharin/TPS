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
    for u in V:
        f=0
        for i in range(k):
            f+=u[i]*X^i
        L=[]
        for i in range(n):
            L.append(f(alpha^i)-r[i])
        L=vector(L)
        if Poids(L)<=t:
            return(f)
    return("pas de solution")

#algorithme de recheche exhaustive par interpolation
#entrée : Fq, n, k, alpha, r
#sortie : f

def exhaustiveinterpolation(Fq, n, k, alpha, r):
    t=floor((n-k)/2)
    L=set(range(n))
    Fqx.<X>=PolynomialRing(Fq)
    Parts=L.subsets(n-t)
    for I in Parts:
        points=[(alpha^i, r[i]) for i in I]
        f=Fqx.lagrange_polynomial(points)
        L=[]
        for i in range(n):
            L.append(f(alpha^i)-r[i])
        L=vector(L)
        if f.degree() < k and Poids(L)<=t:
            return(f)    
    return("pas de solution")



# Algorithme de Welch-Berlekamp    
#  entrée : Fq, n, k, alpha, r
# sortie : f

def welch_berlekamp(Fq, n, k, alpha, r):
    Fqx.<X> = PolynomialRing(Fq)
    t = floor((n - k) / 2)

    # Construction de la matrice C
    A = Matrix(Fq, n, n - t, [[alpha^(i * j) for j in range(n - t)] for i in range(n)])
    B = Matrix(Fq, n, t + 1, [[r[i] * alpha^(i * j) for j in range(t + 1)] for i in range(n)])
    C = block_matrix([[A, B]])

    # Calcul du noyau de la matrice C
    ker = C.right_kernel().basis_matrix()

    # Extraction des polynômes Q0 et Q1
    Q = ker[0].list()
    Q0 = Fqx(Q[0:n - t])
    Q1 = Fqx(Q[n - t:n+1])
    f = -Q0 / Q1
    return f

