## Exercice 1 :

### (1)

print("L'alphabet ASCII est :\n", [chr(i) for i in range(128)], "\n")

### (2)

#On parcoure le texte et on transforme chaque caractère

def asciification(text):
    texttoascii=[]
    for a in text:
        texttoascii.append(ord(a))
    return texttoascii

lalice = asciification(texte)


## Exercice 2 :

### (1)

#On transforme en ASCII le texte et on rajoute la clé modulo 128 à chaque élément et après on le remet en texte

def caesar(text, key):
    l=asciification(text)
    caesaro = ""
    for i in l:
        caesaro += chr((i+key)%128)
    return caesaro

### (2)

#On applique juste l'autre fonction avec - la clé

def decaesar(caesaro, key):
    return caesar(caesaro, -key)

decaesar(caesar(texte, 69), 69)
    

## Exercice 3 :

### (1)

#On parcoure la liste et on note dans un dictionnaire le nombre d'occurence de chaque caractère ASCII

def frequency(text):
    d={}
    for a in text:
        asciia = ord(a)
        if asciia in d:
            d[asciia]+=1
        else:
            d[asciia]=1
    return(d)

### (2)

#On prend le caractère avec le plus d'occurence dans le dictionnaire et on suppose que c'est l'espace 
#On prends la difference des deux modulos 128 et on suppose que c'était la clé et on utilise
#notre fonction de déchiffrement

def decodage(textchif):
    vraiespace = ord(" ")
    d=frequency(textchif)
    maxfreqletter=max(d, key = d.get)
    cle=(maxfreqletter-vraiespace)%128
    return(decaesar(textchif, cle))
	
decodage(caesar(texte, 42))



