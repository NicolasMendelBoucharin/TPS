texte1="le lapin tout rose mangeait des pissenlits et des petites carottes miam miam"
attach(".sage")
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

print("le texte en ascii est", transform(texte), "\n")

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
print("Les 1000 premiers caractères chiffrés :", alicedanslacrypte[:1000], "\n")
print("et déchiffrés... :", devigenere_modifie(alicedanslacrypte[:1000],"le lapin blanc")[:1000], "\n")

## 6)

#mon programme est en complexité O(n²) j'ai donc juste pu l'exécuter sur les 1000 premiers caractères de alice.sage
#on prends des bouts de 5 caractères et on voit faut attendre combien de temps pour qu'ils reviennent et après on prend le pgcd de ces "temps"
def kasiski(chaine):
    liste=[]
    for i in range(len(chaine)-5):
        for j in range(i+1,len(chaine)-5):
            if (chaine[i:i+5]==chaine[j:j+5]) and (j!=i):
                liste.append(j-i)
        g=gcd(liste)
    return g

print("Kasiski donne : ", kasiski(alicedanslacrypte[:1000]), "\n")


## 7)

#je fais les fréquences dans un dictionnaire comme dans le tp1 et je récupère l'indice de coincidence à partir de lui

def incidence(text):
    d={}
    for a in text:
        asciidea = transform(a)[0]
        if asciidea in d:
            d[asciidea]+=1
        else:
            d[asciidea]=1
    ic=0
    for key in d:
        ic += (d[key]*(d[key]-1))/(len(text)*(len(text)-1))
    return ic.n()

## 8)

print("l'incide de coincidence de Alice in Wonderlands est :", incidence(texte), "\n")
#je trouve à peu près la même valeur que wikipédia


## 9)

#calcul de la longueur avec l'indice de coincidence avec la formule du cours
def friedman(textechiffre):
    i=incidence(textechiffre)
    I=0.065
    N=92
    n=len(textechiffre)
    l = ((I - 1/N)*n) / ((n-1)*i -n/N +I)
    return l

print("l'attaque de friedman donne : ", friedman(alicedanslacrypte), "mais La taille de la clé n'est pas concluante \n")

# ça ne marche pas ^^

## 10)

#On fait un dictionnaire avec les soustextes en fonction de la position modulo k des lettres dans le texte de base

def soustextes(text, k):
    d={}
    for c,a in enumerate(text):
        cle = c%k
        if cle in d:
            d[cle]=d[cle]+a
        else:
            d[cle]=a
    return d

## 11)

#On teste pour des k différents ce qui donne des incidences cohérents dans les sous textes et ça donne la longueur de la clé

def rechercheexhaustive(text):
    k=1
    stxt=soustextes(text,k)
    I=0.065
    while abs(incidence(stxt[0]) - I )>0.01: #au début j'ai mis 0.005 et j'ai eu 28 pas 14
        k=k+1
        stxt=soustextes(text,k)   
    return k 

print("En utilisant les sous textes on trouve :",rechercheexhaustive(alicedanslacrypte), "\n")

## 12)

#fonction auxilliaire pour trouver les fréquences de chaque lettre (comme pour ma fonction incidence)

def frequency(text):
    d={}
    for a in text:
        asciidea = transform(a)[0]
        if asciidea in d:
            d[asciidea]+=1
        else:
            d[asciidea]=1
    return(d)

#Pour chaque sous texte on trouve la clé de caesar en comparant la lettre la plus frequente à l'espace comme dans le tp1 
#(ici par contre on doit faire attention à pas avoir de "ord" mais bien la fonction de la question 1)
def vigenerekeyfinder(textechif):
    vraiespace=transform(" ")[0]
    longueurcle=rechercheexhaustive(textechif)
    cle=[]#""
    sstxt=soustextes(textechif, longueurcle)
    for ind in sstxt :
        freq= frequency(sstxt[ind])     
        maxfreqletter=max(freq, key = freq.get)
        clecaesar=(maxfreqletter-vraiespace)%91
        cle.append(clecaesar)
    return(detransform(cle))

print(vigenerekeyfinder(alicedanslacrypte))
    