#Constructeur de polynôme aléatoire unitaire de degré t
#entrée: t, m la puissance de 2 de F2m
#sortie: polynôme irréductible de degré t

def random_poly(m, t):
    f=x**t
    g=R.random_element(degree=t-1)
    while (f+g).is_irreducible()==False:
        g=R.random_element(degree=t-1)
    return(f+g)

#constructeur de n-uplet aléatoire de F2m distincts deux à deux
#entrée : n, m
#sortie : L
def random_uplet(n,m):
    L = []
    while len(L) < n:
        elem = F2m.random_element()
        if elem not in L:
            L.append(elem)
    return L

# Constructeur de la matrice génératrice sous forme échelonnée réduite G d'un code de Goppa
# entrée : L (support de Goppa), g (polynôme de Goppa)
# sortie : G (matrice génératrice sous forme échelonnée réduite)

def goppa_gen(L, g, m, ev):
    n=len(L)
    r=g.degree()
    V=[[a^i for a in L] for i in range(r)]
    V=matrix( V)
    D=diagonal_matrix([g(a)**(-1) for a in L])
    Hbarre=V*D
    
    #on passe dans F2m
    M=[[0 for i in range(n)] for j in range(r*m)]
    
    for i in range(r):
        for j in range(n):
            Mij = ev.coordinate_vector(Hbarre[i][j])
            for k in range(m):
                M[i*m +k][j]= Mij[k]
    H = matrix(GF(2), M)
    return H.right_kernel().basis_matrix().rref()

# nouvelle fonction 

def goppa_gen2(m, n, t, ev):
    L = random_uplet(n, m)
    g = random_poly(m, t)
    r=g.degree()
    Hcirc=[]
    for i in range(t):
        Hcirc.append([(L[j]**i)*(g(L[j]))**(-1) for j in range(n)])
    
    M=[[0 for i in range(n)] for j in range(t*m)]
    
    for i in range(t):
        for j in range(n):
            Mij = ev.coordinate_vector(Hcirc[i][j])
            for k in range(m):
                M[i*m +k][j]= Mij[k]
    H = matrix(GF(2), M).rref()
    return H, L, g



