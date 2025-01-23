## 1)

def transform(chaine):
    liste=[]
    for i in range(len(chaine)):
        if ord(chaine[i])==10:
            liste.append(91)
        else:
            liste.append(ord(chaine[i])-32)
    return liste

#fonction inverse pas demandé mais utile pour la suite
def detransform(liste):
    chaine=""
    for l in liste:
        if l==91:
            chaine += chr(10)
        else:
            chaine += chr(l+32)
    return chaine
## 2)
print(transform("bababoy"))
print(transform(texte))

## 3)

def vigenere_modifie(chaine, cle):
#on commence par transformer la chaine et la cle en liste d'entiers entre 0 et 91
    listchaine=transform(chaine)
    listecle=transform(cle)

#on regarde le i_ème élément de la liste de la chaine et on lui ajoute le ième-element de la liste de clé (modulo sa longueur) le tout modulo 91
    for i,l in enumerate(listchaine):
       l=(l+listecle[i%len(listecle)])%91
    return detransform(listchaine)
## 4)


def devigenere_modifie(chaine, cle):
#on commence par transformer la chaine et la cle en liste d'entiers entre 0 et 91
    listchaine=transform(chaine)
    listecle=transform(cle)

#on regarde le i_ème élément de la liste de la chaine et on lui soustrait le ième-element de la liste de clé (modulo sa longueur) le tout modulo 91   
    for i,l in enumerate(listchaine):
       l=(l-listecle[i%len(listecle)])%91
    return detransform(listchaine)

print(vigenere_modifie(texte, "le lapin blanc"))
## 5)


