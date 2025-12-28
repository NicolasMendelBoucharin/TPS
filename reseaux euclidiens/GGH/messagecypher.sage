load("gghIntoFile.sage")

# Création et sauvegarde d'un système GGH
n = 200  # Dimension du système
ggh = create_ggh_and_save(n, privkey_file="./keys/privkey.txt", pubkey_file="./keys/pubkey.txt")
encrypt_message_from_file(ggh, "./messages/message.txt", "./messages/ciphertext.txt", delta=3)
decrypt_message_from_file(ggh, "./messages/ciphertext.txt", "./messages/decrypted.txt")

