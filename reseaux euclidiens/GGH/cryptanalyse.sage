load("ggh.sage")

def LLLattack(pubkey, c):
    # Un simple LLL suffit pour retrouver la clé privée pour des petites dimensions
    LLL_pubkey = pubkey.LLL()
    v = BabaiNearestPlaneAlgorithm(LLL_pubkey, c)
    m = pubkey.solve_left(v)
    return m



def embeding_attack(pubkey, c):
    """
    Embedding attack contre le système GGH.
    Construit un réseau augmenté contenant le chiffré et cherche l'erreur.
    """
    n = pubkey.nrows()

    #embedding de la clé publique
    B_embed = pubkey.augment(vector(ZZ, [0]*n))
    c_aug = vector(ZZ, list(c) + [1])
    B_embed = B_embed.stack(c_aug)

    # Appliquer LLL
    B_embed = B_embed.LLL()

    # récupérer l'erreur dans les n premières coordonnées du vecteur le plus court
    short_vector = B_embed[0]
    e_hack = vector(ZZ, short_vector[:n])
    
    # Récupérer le message: v = c - e
    v = c - e_hack
    m = pubkey.solve_left(v)
    return m

def nguyen_attack(pubkey, c):
    """
    Attaque de Nguyen contre le système GGH.
    """
    print("Pas encore implémenté")
    return None