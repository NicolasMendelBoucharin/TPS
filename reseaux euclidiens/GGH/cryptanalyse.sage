load("ggh.sage")

def LLLattack(pubkey, e):
    LLL_pubkey=pubkey.LLL()
    v = BabaiNearestPlaneAlgorithm(LLL_pubkey, e)
    m = pubkey.solve_left(v)
    return m



def embeding_attack(pubkey, c):
    n = pubkey.nrows()

    c_aug = vector(ZZ, list(c) + [1])
 
    
    B_embed = pubkey.augment(vector(ZZ, [0]*n))
   
    B_embed = B_embed.stack(c_aug)

    B_embed = B_embed.LLL()
    e_hack = vector(ZZ, B_embed[0, :n])
    
    # c = m*B + e, donc m*B = c - e
    # On cherche m tel que m*B = c - e_hack
    c_minus_e = c - e_hack
    # B est inversible, donc m = (c - e) * B^{-1}
    try:
        m = c_minus_e * pubkey.inverse()
    except:
        # Si B^{-1} n'existe pas, on essaie une autre approche
        m = pubkey.solve_left(c_minus_e)
    
    return m

