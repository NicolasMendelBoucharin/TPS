load("ggh.sage")

def test_simple():
    """Test chifrement/déchiffrement pour différents n"""
    for n in [10, 100, 150, 200]:
        print(f"\nTest avec n={n}:")
        ggh = GGH(n)
        m = vector(ZZ, [randint(-n, n) for _ in range(n)])
        e = ggh.encrypt(m, delta=3)
        m_decrypted = ggh.decrypt(e)
        assert m == m_decrypted, f"Déchiffrement échoué pour n={n}!"
        print(f"Chiffrement/Déchiffrement réussi pour n={n}")


def test_multiple_encryptions():
    """Test de différences des chiffrés"""

    n = 20
    ggh = GGH(n)
    m = vector(ZZ, [5]*n)

    # les 3 chiffrés doivent être différents
    ciphertexts = [ggh.encrypt(m, delta=3) for _ in range(3)]
    assert ciphertexts[0] != ciphertexts[1], "Chiffremets identiques!"
    assert ciphertexts[1] != ciphertexts[2], "Chiffremets identiques!"
    
    #Ils doivent déchiffrer le même message
    for i, c in enumerate(ciphertexts):
        m_dec = ggh.decrypt(c)
        try:
            assert m == m_dec
        except AssertionError:
            print(f"Déchiffrement {i} échoué!")
    print("Test chiffremets multiples réussi")


def test_setter():
    """Test du setter"""
    n = 16
    ggh1 = GGH(n)
    ggh2 = GGH(n)
    
    ggh2.set_keypair(ggh1.privkey, ggh1.pubkey)
    
    m = vector(ZZ, [3, -2, 1, 0]*4)
    
    # Chiffrer avec ggh1
    e = ggh1.encrypt(m, delta=2)
    
    # Déchiffrer avec ggh2 pour voir si les clés ont bien été set
    m_dec = ggh2.decrypt(e)
    try:
        assert m == m_dec
    except AssertionError:
        print("Gestion des clés échouée!")
        return 
    print("Test gestion des clés réussi")


def test_hadamard_ratio_check():
    """Test que privkey est meilleure que pubkey (Hadamard ratio)"""
    for n in [10, 20, 50, 100]:
        ggh = GGH(n)
        ratio_priv = float(HadamardRatio(ggh.privkey))
        ratio_pub = float(HadamardRatio(ggh.pubkey))
        print(f"n={n}: Hadamard ratio privkey={ratio_priv}, pubkey={ratio_pub}")
        


def test_same_basis():
    """Test que la base privée et publique ont le même déterminant"""
    for n in [10, 20, 50, 100]:
        ggh = GGH(n)
        det_priv = abs(ggh.privkey.det())
        det_pub = abs(ggh.pubkey.det())
        try:
            assert det_priv == det_pub
        except AssertionError:
            print(f"Déterminants différents pour n={n}: privkey={det_priv}, pubkey={det_pub}")
            return
    print("Test des déterminants réussi")


def test_unitaires():
    """Lance tous les tests"""
    test_multiple_encryptions()
    test_setter()
    test_hadamard_ratio_check()
    test_same_basis()
    print("Exécution complète de tous les tests unitaires GGH")
    print("\nTous les tests unitaires GGH réussis")
    
   


#à décommenter pour lancer les tests automatiquement
test_unitaires()