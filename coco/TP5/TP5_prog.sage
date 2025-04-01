#Constructeur de polynôme aléatoire unitaire de degré t
#entrée: t, m la puissance de 2 de F2m
#sortie: polynôme irréductible de degré t

def random_poly(m, t):
    F2m.<X> = PolynomialRing(GF(2^m))
    f=X**t
    g=F2m.random_element(degree=t-1)
    while (f+g).is_irreducible()==False:
        g=F2m.random_element(degree=t-1)
    return(f+g)

#constructeur de n-uplet aléatoire de F2m distincts deux à deux
#entrée : n, m
#sortie : L
def random_uplet(n,m):
    F2m = GF(2^m)
    L = []
    while len(L) < n:
        elem = F2m.random_element()
        if elem not in L:
            L.append(elem)
    return L

# Constructeur de la matrice génératrice sous forme échelonnée réduite G
# d'un code de Goppa(gamma, g) de support de Goppa L et de polynôme de Goppa g
# entrée : L (support de Goppa), g (polynôme de Goppa)
# sortie : G (matrice génératrice sous forme échelonnée réduite)

def goppa_generator_matrix(L, g, F):
    n=len(L)
    r=g.degree()
    V=[[a^i for a in L] for i in range(r)]
    V=matrix( V)
    D=diagonal_matrix([g(a)**(-1) for a in L])
    Htilde=V*D
    #on passe dans F2m
    M=[]
    for c in Htilde.columns():
        L=[]
        for b in c:
            L + F2m.vector_space(map=False)(b)
        M.append(L)
    H=Matrix(M).transpose()
    # Construction de la matrice génératrice G
    G = H.right_kernel().basis_matrix()
    return G.echelon_form()