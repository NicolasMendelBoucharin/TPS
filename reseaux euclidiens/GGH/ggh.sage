#Fonctions utilitaires pour le systeme GGH:

def random_unimodular_matrix(n):
    '''
    Entrée : un entier n
    Sortie : une matrice carrée unimodulaire de taille n
    '''
    U = matrix(ZZ, n, n)
    for r in range(n):
        for j in range(r, n):
            if random() > 0.5:
                U[r, j] = 1
            else:
                U[r, j] = -1

    L = matrix(ZZ, n, n)
    for r in range(n):
        for j in range(r+1):
            if random() > 0.5:
                L[r, j] = 1
            else:
                L[r, j] = -1

    T = L*U


    return T


def random_error_vector(n, delta=3):
        '''
        Entrée : un entier n et un entier delta
        Sortie : un vecteur d'erreur aléatoire de dimension n.
        On choisi delta = 3 comme dans le livre 
        '''
        r = vector(ZZ, n)
        for i in range(n):
            r[i] = randint(-delta, delta)
        return r


#Pour de la lecture et ecriture de fichiers
def TextToList(str):
    '''
    Entrée : une chaîne de caractères
    Sortie : une liste d'entiers
    '''
    L=[]
    for c in str:
        L.append(ord(c))
    return L

def ListToText(L):
    '''
    Entrée : une liste d'entiers
    Sortie : une chaîne de caractères
    '''
    str=""
    for i in L:
        str+=chr(i)
    return str

#Pas sûr que ça serve à quelque chose au final
def HadamardRatio(B):
    '''
    Entrée : une base B
    Sortie : le ratio d'Hadamard de B
    '''
    n = B.ncols()
    H = (abs(B.det()) / product(v.norm() for v in B))^(1/n)
    return H


#Existe déjà dans sage mais très lente
def GramSchmidtAlgorithm(B):
    '''
    Entrée : une base de L
    Sortie : une base gramschmidté 
    '''
    n = B.nrows()
    G = matrix(RR, n)
    for i in range(n):
        vi = B[i]
        for j in range(i):
            mu = (B[i]*G[j]) / G[j].norm()^2
            vi -= mu * G[j]
        G[i] = vi
    return G

#Je ne m'en sers pas à priori mais je l'ai fait au début du projet
def BabaiRoundOff(B, t):
    '''
    Entrée : Une base B d'un réseau de R^n et un vecteur cible t de R^n
    Sortie : Un élement v du réseau L tel que t-v soit dans le parallélépipède engendré par B
    '''
    z=B^(-1)*t
    w=vector([round(zi) for zi in z])
    v=B*w
    return v


def BabaiNearestPlaneAlgorithm(B, t):
    '''
    Entrée : Une base B d'un réseau de R^n et un vecteur cible t de R^n
    Sortie : Un élement v du réseau L tel que t-v soit dans D(b1*,...,bn*) 
    '''
    Bprime = GramSchmidtAlgorithm(B)
    n=B.nrows()
    v=vector(ZZ, [0]*n)
    c=t
    for i in reversed(range(n)):
        ctilde=round((c*Bprime[i])/(Bprime[i]*Bprime[i]))
        v=v+ctilde*B[i]
        c=c-ctilde*B[i]
    return v


class GGH:
    '''
    Classe d'un systeme GGH avec sa taille, sa clé privée et sa clé publique.
    '''
    def __init__(self, n):
        '''
        Crée une instance du système GGH de taille n, avec génération des clés.
        '''
        self.n = n
        self.privkey, self.pubkey = self.keygen(n)
    
    def keygen(self, n):
        l = 4 #On fait la deuxième méthode suggeré page 418 du livre
        k = round(sqrt(n)) * l
        I = matrix.identity(n)
        E = matrix(ZZ, n, n, [randint(-l, l) for _ in range(n*n)])
        B = E + I*k

        Bprime = B
        #On fait 4 produit avec des matrices unimodulaires aléatoires
        for _ in range(4):
            T = random_unimodular_matrix(n)
            Bprime = T * Bprime
        return B, Bprime
    
    def set_keypair(self, R, B):
        #Pour changer notre paire de clés après une génération
        self.privkey = R
        self.pubkey = B
        self.n = R.ncols()

    def encrypt(self, m, r=None, delta=3):
        if r == None:
            r = random_error_vector(self.n, delta)
        e = m*self.pubkey + r
        return e

    def decrypt(self, e):
        v = BabaiNearestPlaneAlgorithm(self.privkey, e)
        m = self.pubkey.solve_left(v)
        return m



