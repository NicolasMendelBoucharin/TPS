texte1="le lapin tout rose mangeait des pissenlits et des petites carottes miam miam"
attach("alice.sage")
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
print(transform(texte1))

## 3)

def vigenere_modifie(chaine, cle):
#on commence par transformer la chaine et la cle en liste d'entiers entre 0 et 91
    listchaine=transform(chaine)
    listecle=transform(cle)

#on regarde le i_ème élément de la liste de la chaine et on lui ajoute le ième-element de la liste de clé (modulo sa longueur) le tout modulo 91
    for i,c in enumerate(listchaine):
       listchaine[i]=(c+listecle[i%len(listecle)])%91
    return detransform(listchaine)
## 4)


def devigenere_modifie(chaine, cle):
#on commence par transformer la chaine et la cle en liste d'entiers entre 0 et 91
    listchaine=transform(chaine)
    listecle=transform(cle)

#on regarde le i_ème élément de la liste de la chaine et on lui soustrait le ième-element de la liste de clé (modulo sa longueur) le tout modulo 91   
    for i,c in enumerate(listchaine):
       listchaine[i]=(c-listecle[i%len(listecle)])%91
    return detransform(listchaine)

## 5)
alicedanslacrypte=vigenere_modifie(texte,"le lapin blanc")
print(alicedanslacrypte[:1000])
print(devigenere_modifie(alicedanslacrypte[:1000],"le lapin blanc")[:1000])

## 6)

#mon programme est en complexité O(n²) j'ai donc juste pu l'exécuter sur les 1000 premiers caractères de alice.sage
def kasiski(chaine):
    liste=[]
    for i in range(len(chaine)-5):
        for j in range(i+1,len(chaine)-5):
            if (chaine[i:i+5]==chaine[j:j+5]) and (j!=i):
                liste.append(j-i)
        g=gcd(liste)
    return g

print(kasiski(alicedanslacrypte[:1000]))


## 7)

def incidence(text):
    d={}
    for a in text:
        asciia = ord(a)
        if asciia in d:
            d[asciia]+=1
        else:
            d[asciia]=1
    ic=0
    for key in d:
        ic += (d[key]*(d[key]-1))/(len(text)*(len(text)-1))
    return ic.n()

## 8)

print("l'incide de coincidence de Alice in Wonderlands est :", incidence(texte))
#je trouve à peu près la même valeur que wikipédia


## 9)

def friedman(textechiffre):
    i=incidence(textechiffre)
    I=0.065
    N=92
    n=len(textechiffre)
    l = ((I - 1/N)*n) / ((n-1)*i -n/N +I)
    return l

print(friedman(alicedanslacrypte))