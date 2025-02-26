attach('TP2_prog.sage')


## Exercice 1:

q = ZZ.random_element(1,5).next_prime()
#q est un nombre premier <=5

n = ZZ.random_element(50,100)
while n%q == 0:
        n = ZZ.random_element(50,100)
#n est un entier entre 50 et 100

s=3

R.<x> = PolynomialRing(GF(q))
#R est un anneau de polynômes à coefficients dans Fq


### Question 1.a):
print("Question 1.a)\n")

print(f"{q}-Classe cyclotomique de {s} modulo {n}: {cycloclass(q,n,s)} \n")

### Question 1.b):
print("Question 1.b)\n")

print(f"les q-classes cyclotomiques modulo {n} dans F_{q} : {cycloclassset(q,n)} \n")

### Question 1.c):
print("Question 1.c)\n")

print(f"Une racine primitive de l'unité dans une extension de F_{q} : {racineprimitive(q,n)} \n")

### Question 1.d):
print("Question 1.d)\n")

print(f"Polynôme minimal de alpha**{s} : {polmin(racineprimitive(q,n), s, q, n)} \n")

### Question 1.e):
print("Question 1.e)\n")

print(f"mes facteurs unitaires de X^{n}-1 dans F_{q} : {ma_factorisation(n,q)} \n")
S = ma_factorisation(n,q)
#Vérification
if (S == {u[0] for u in factor(x^n-1)}):
        print("Validation du TP2\n")
else:
        print("Erreur\n")

## Exercice 2:
print("Exercice 2\n")
n=[9,15,21,23]
q=2
for i in n:
    R.<x> = PolynomialRing(GF(q))
    print(f"Le polynôme X^{n} -1 se factorise dans F_{q} par : {factorisationjoli(i,q)}\n")
    print(f"... et sage le factorise comme ça : {factor(x^i-1)}\n")
    
n=26
q=3
R.<x> = PolynomialRing(GF(q))
print(f"Le polynôme X^{n} -1 se factorise dans F_{q} par : {factorisationjoli(n,q)}\n")
print(f"... et sage le factorise comme ça : {factor(x^n-1)}\n")


## Exercice 3:

print("Exercice 3\n")

R.<x> = PolynomialRing(GF(2))
#calcul de alpha
F=GF(2**10)
Fgen=F.gen()
alpha=Fgen**Integer((2**10-1)/1023)
print(f"alpha = {alpha}\n")

#calcul du polynôme générateur
L=[]
for s in range(1, 101):
    L.append(polmin(racineprimitive(2,1023), s, 2, 1023))
L=set(L)
g=lcm(L)
print(f"le polynôme générateur est : {g}\n")

#calcul de la matrice génératrice
deg=g.degree()
L=list(g)+[0 for i in range(1022-g.degree())]
C = []
for i in range(len(L)):
    C.append([0] * i + L[:len(L) - i])

print("Pour afficher la matrice génératrice, décommenter la ligne suivante\n")

#print(C)
