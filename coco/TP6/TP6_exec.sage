attach('cleprive.sage')
attach('cryptogramme.sage')

attach('clepublique.sage')
attach('TP6_prog.sage')

# Partie 1 : Cryptosystème de Niederreiter


print("Partie 1 : Cryptosystème de Niederreiter \n")

e = vector(GF(2), [0 for i in range(n)])
poids = randint(0, t)
for i in range(poids):
    e[randint(0, n-1)] = 1





c=chiffrement(e, m, t, T)

d=dechiffrement(c, n, g, L, t)

print(e==d)
print(Poids(e))
print(Poids(d))
print("___________________________________________")

d=dechiffrement(S, n, g, L, t)

print("___________________________________________")


print(Poids(d))
