load("cryptanalyse.sage")

class BAD_GGH:
    '''
    Classe d'un mauvais systeme GGH avec sa taille, sa clé privée et sa clé publique mais avec une mauvaise génération d'erreur.
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

    def bad_random_error_vector(self, delta=3):
        '''
        Entrée : un entier delta
        Sortie : un vecteur d'erreur aléatoire de dimension n.
        On choisi delta = 3 comme dans le livre 
        '''
        n=self.n
        r = vector(ZZ, n)
        for i in range(n):
            if random() < 0.5:
                r[i] = -delta
            else:
                r[i] = delta
        return r
        
    def encrypt(self, m, r=None, delta=3):
        if r == None:
            r = self.bad_random_error_vector(delta)
        e = m*self.pubkey + r
        return e

    def decrypt(self, e):
        v = BabaiNearestPlaneAlgorithm(self.privkey, e)
        m = self.pubkey.solve_left(v)
        return m


def test_LLL_attack():
    """Test attaque LLL sur un chiffrement GGH"""
    n = [10, 20, 50, 100]
    for size in n:
        ggh = GGH(size)
        pubkey = ggh.pubkey

        # Créer un message aléatoire
        m = vector(ZZ, [randint(-size, size) for _ in range(size)])
        c = ggh.encrypt(m, delta=3)

        m_decrypted = LLLattack(pubkey, c)

        try:
            assert m == m_decrypted
        except AssertionError:
            print(f"Déchiffrement échoué avec un LLL pour un code de taille {size}")
        else:
            print(f"Chiffrement/Déchiffrement réussi après un LLL pour un code de taille {size}")



def test_embeding_attack():
    """Test attaque par emboîtement sur un chiffrement GGH"""
    n = [10, 20, 50, 100]
    for size in n:
        ggh = GGH(size)
        pubkey = ggh.pubkey

        
        m = vector(ZZ, [randint(-size, size) for _ in range(size)])
        c = ggh.encrypt(m, delta=3)

        m_decrypted = embeding_attack(pubkey, c)

        try:
            assert m == m_decrypted
        except AssertionError:
            print(f"Déchiffrement échoué avec une attaque par emboîtement pour un code de taille {size}")
        else:
            print(f"Chiffrement/Déchiffrement réussi après une attaque par emboîtement pour un code de taille {size}") 


def test_nguyen_attack():
    n=100
    badggh= BAD_GGH(n)
    pubkey= badggh.pubkey
    m= vector(ZZ, [randint(-n, n) for _ in range(n)])
    c= badggh.encrypt(m, delta=3)
    m_decrypted= nguyen_attack(pubkey, c, sigma=3)
    try:
        assert m == m_decrypted
    except AssertionError:
        print(f"Déchiffrement échoué avec une attaque de Nguyen pour un code de taille {n}")
    else:
        print(f"Chiffrement/Déchiffrement réussi après une attaque de Nguyen pour un code de taille {n}")

test_LLL_attack()
test_embeding_attack()
#test_nguyen_attack()

