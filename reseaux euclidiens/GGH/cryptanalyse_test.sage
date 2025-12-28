load("cryptanalyse.sage")

def test_embeding_attack():
    """Test attaque par emboîtement sur un chiffrement GGH"""
    n = [10, 20, 50, 100]
    for size in n:
        ggh = GGH(size)
        pubkey = ggh.pubkey

        # Créer un message aléatoire
        m = vector(ZZ, [randint(-size, size) for _ in range(size)])
        c = ggh.encrypt(m, delta=3)

        m_decrypted = embeding_attack(pubkey, c)

        try:
            assert m == m_decrypted
        except AssertionError:
            print(f"Déchiffrement échoué avec une attaque par emboîtement pour un code de taille {size}")
        else:
            print(f"Chiffrement/Déchiffrement réussi après une attaque par emboîtement pour un code de taille {size}") 

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

test_LLL_attack()
test_embeding_attack()
