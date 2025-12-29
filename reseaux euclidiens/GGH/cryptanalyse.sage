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

    #embedding 
    B_embed = pubkey.augment(vector(ZZ, [0]*n))
    c_aug = vector(ZZ, list(c) + [1])
    B_embed = B_embed.stack(c_aug)

    #LLL
    B_embed = B_embed.LLL()

    # récupérer l'erreur dans les n premières coordonnées du vecteur le plus court
    short_vector = B_embed[0]
    e_hack = vector(ZZ, short_vector[:n])

    # Récupérer le message:  m = (c - e_hack)B^{-1}
    v = c - e_hack
    m = pubkey.solve_left(v)
    return m


'''
def nguyen_attack(pubkey, c, sigma=3):
    """
    Attaque de Nguyen contre le système GGH.
    """
    n = pubkey.nrows()
    sigma_vec = vector(ZZ, [sigma] * n)
    new_m = vector(ZZ, [0] * n)
    new_c = c

    m_0= ((new_c + sigma_vec) * pubkey.inverse()) % (2*sigma)
    new_m += m_0
    new_c = vector(ZZ, [(new_c - m_0 * pubkey)[i] // (2*sigma) for i in range(n)])

    
    return new_m
'''