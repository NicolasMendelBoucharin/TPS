load('ggh.sage')

def save_keys_to_files(ggh, privkey_file="privkey.txt", pubkey_file="pubkey.txt"):
    '''
    Entrée:
        - ggh : instance GGH
        - privkey_file : nom du fichier pour la clé privée (défaut: privkey.txt)
        - pubkey_file : nom du fichier pour la clé publique (défaut: pubkey.txt)
    '''
    # Sauvegarder la clé privée
    with open(privkey_file, 'w') as f:
        f.write(f"{ggh.n}\n")
        for row in ggh.privkey:
            f.write(" ".join(str(int(x)) for x in row) + "\n")
    # Sauvegarder la clé publique
    with open(pubkey_file, 'w') as f:
        f.write(f"{ggh.n}\n")
        for row in ggh.pubkey:
            f.write(" ".join(str(int(x)) for x in row) + "\n")




def load_keys_from_files(privkey_file="privkey.txt", pubkey_file="pubkey.txt"):
    '''
    Entrée:
        - privkey_file : nom du fichier contenant la clé privée
        - pubkey_file : nom du fichier contenant la clé publique
    
    Sortie:
        - (privkey, pubkey) : tuple avec les deux matrices
    '''
    
    # Charger la clé privée
    with open(privkey_file, 'r') as f:
        lines = f.readlines()
        n = int(lines[0].strip())
        privkey_rows = []
        for line in lines[1:]:
            if line.strip():
                row = [int(x) for x in line.strip().split()]
                privkey_rows.append(row)
    privkey = matrix(ZZ, privkey_rows)
    
    # Charger la clé publique
    with open(pubkey_file, 'r') as f:
        lines = f.readlines()
        n = int(lines[0].strip())
        pubkey_rows = []
        for line in lines[1:]:
            if line.strip():
                row = [int(x) for x in line.strip().split()]
                pubkey_rows.append(row)
    pubkey = matrix(ZZ, pubkey_rows)

    return privkey, pubkey


def create_ggh_and_save(n, privkey_file="privkey.txt", pubkey_file="pubkey.txt"):
    '''
    Entrée:
        - n : dimension du système
        - privkey_file : nom du fichier pour la clé privée
        - pubkey_file : nom du fichier pour la clé publique
    Sortie:
        - ggh : instance GGH créée
    '''
    ggh = GGH(n)
    save_keys_to_files(ggh, privkey_file, pubkey_file)
    return ggh

    
def load_ggh_from_files(privkey_file="privkey.txt", pubkey_file="pubkey.txt"):
    '''
    Entrée:
        - privkey_file : nom du fichier contenant la clé privée
        - pubkey_file : nom du fichier contenant la clé publique
    
    Sortie:
        - ggh : instance GGH avec les clés chargées
    '''
    privkey, pubkey = load_keys_from_files(privkey_file, pubkey_file)
    n = privkey.ncols()
    ggh = GGH(n)  # Crée une instance avec n'importe quelles clés
    ggh.set_keypair(privkey, pubkey)  # Remplace par les clés chargées
    return ggh


def encrypt_message_from_file(ggh, input_file, output_file="ciphertext.txt", delta=3):
    '''
    Entrée:
        - ggh : instance GGH
        - input_file : fichier contenant le message à chiffrer
        - output_file : fichier de sortie pour le chiffré
        - delta : paramètre d'erreur
    '''
    # Lire le fichier
    with open(input_file, 'r') as f:
        text = f.read()
    
    # Convertir en ASCII 
    ascii_values = TextToList(text)
    
    print(f"Message lu: {text}")
    
    # Padding
    if len(ascii_values) > ggh.n:
        print(f"Attention: le message est trop long (>'{ggh.n})")
        ascii_values = ascii_values[:ggh.n] #On tronque plutôt que de faire des blocs pour l'instant
    else:
        padding = ggh.n - len(ascii_values)
        ascii_values.extend([0] * padding)


    #message
    m = vector(ZZ, ascii_values)
    print(f"Vecteur message: {m}")
    
    # Chiffré
    c = ggh.encrypt(m, delta=delta)
    print(f"Chiffré généré: {c}")

    # écriture du chiffré
    with open(output_file, 'w') as f:
        f.write(f"{ggh.n}\n")
        f.write(" ".join(str(int(x)) for x in c) + "\n")
    return c


def decrypt_message_from_file(ggh, ciphertext_file, output_file="decrypted.txt"):
    '''
    Entrée:
        - ggh : instance GGH
        - ciphertext_file : fichier contenant le chiffré
        - output_file : fichier de sortie pour le message déchiffré
    
    Sortie:
        - texte déchiffré
    '''

    # Lire le chiffré
    with open(ciphertext_file, 'r') as f:
        lines = f.readlines()
        n = int(lines[0].strip())
        c_values = [int(x) for x in lines[1].strip().split()]
    
    c = vector(ZZ, c_values)
    print(f"Chiffré lu: {c}")
    
    # Déchiffrer
    m = ggh.decrypt(c)
    print(f"vecteur déchiffré (vecteur): {m}")
    
    
    m_list = [int(val) for val in m]
    
    #padding
    while m_list and m_list[-1] == 0:
        m_list.pop()
    
    text = ListToText(m_list)
    print(f"Message déchiffré: {text}")
    
    # écriture du déchiffré
    with open(output_file, 'w') as f:
        f.write(text)
    
    return text



