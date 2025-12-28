load("ggh.sage")

def test_simple():
    """Test simple avec delta=3 et n=150, 200"""
    for n in [150, 200]:
        print(f"\nTest avec n={n}:")
        ggh = GGH(n)
        m = vector(ZZ, [randint(-n, n) for _ in range(n)])
        e = ggh.encrypt(m, delta=3)
        m_decrypted = ggh.decrypt(e)
        assert m == m_decrypted, f"Déchiffrement échoué pour n={n}!"
        print(f"Chiffrement/Déchiffrement réussi pour n={n}")


def test_multiple_encryptions():
    """Test chiffrement multiple du même message"""
    n = 18
    ggh = GGH(n)
    m = vector(ZZ, [5]*n)
    
    # Chiffrer le même message 3 fois
    ciphertexts = [ggh.encrypt(m, delta=3) for _ in range(3)]
    assert ciphertexts[0] != ciphertexts[1], "Chiffremets identiques!"
    assert ciphertexts[1] != ciphertexts[2], "Chiffremets identiques!"
    
    # Mais tous doivent déchiffrer au même message
    for i, c in enumerate(ciphertexts):
        m_dec = ggh.decrypt(c)
        assert m == m_dec, f"Déchiffrement {i} échoué!"
    print("Test chiffremets multiples réussi")


def test_keypair_management():
    """Test gestion des clés (set_keypair)"""
    n = 16
    ggh1 = GGH(n)
    ggh2 = GGH(n)
    
    # Copier les clés de ggh1 vers ggh2
    ggh2.set_keypair(ggh1.privkey, ggh1.pubkey)
    
    # Créer un message
    m = vector(ZZ, [3, -2, 1, 0]*4)
    
    # Chiffrer avec ggh1
    e = ggh1.encrypt(m, delta=2)
    
    # Déchiffrer avec ggh2 (qui a les mêmes clés)
    m_dec = ggh2.decrypt(e)
    assert m == m_dec, "Gestion clés échouée!"
    print("Test gestion des clés réussi")


def test_hadamard_ratio_check():
    """Test que privkey est meilleure que pubkey (Hadamard ratio)"""
    n = 35
    ggh = GGH(n)
    
    ratio_priv = float(HadamardRatio(ggh.privkey))
    ratio_pub = float(HadamardRatio(ggh.pubkey))
    
    # La clé privée doit avoir un meilleur ratio (plus proche de 1)
    assert ratio_priv >= ratio_pub * 0.9, f"Privkey ratio {ratio_priv} pas meilleur que pubkey {ratio_pub}"
    print(f"test Hadamard ratio réussi (priv={ratio_priv:.4f}, pub={ratio_pub:.4f})")


def test_determinant_preserved():
    """Test que det(privkey) ≈ det(pubkey) (même réseau)"""
    n = 15
    ggh = GGH(n)
    
    det_priv = abs(ggh.privkey.det())
    det_pub = abs(ggh.pubkey.det())
    
    # Les déterminants doivent être égaux (même réseau)
    assert det_priv == det_pub, f"Déterminants différents: {det_priv} vs {det_pub}"
    print(f"Test déterminant préservé réussi (det={det_priv})")


def test_unitaires():
    """Lance tous les tests"""
    test_multiple_encryptions()
    test_keypair_management()
    test_hadamard_ratio_check()
    test_determinant_preserved()
    print("Exécution complète de tous les tests unitaires GGH")
    print("\nTous les tests unitaires GGH réussis")
    
   


#à décommenter pour lancer les tests automatiquement
test_unitaires()