# TP 5


## Exercice 1:

print("Exercice 1: \n")

### 1)

print("1) \n")

### 2)

print("2) \n")

### 3)

print("3) \n")


## Exercice 2:

print("Exercice 2: \n")

### 1)

print("1) \n")

m = 5
t = 3
n = 25
F2 = GF(2)
F2m.<alpha> = PolynomialRing(GF(2^m))
ev, _, _ = F2m.vector_space()
R.<x> = PolynomialRing(F2m)

g=random_poly(m, t)
L=random_uplet(n, m)
G=goppa_generator_matrix(L, g)

print(f"le code de goppa pour {L} et {g} est {G}\n")

### 2)

print("2) \n")

listinv = []
for i in range(n):
    a=(x-L[i]).inverse_mod(g**2)
    listinv.append(a)
print(f"la liste des inverses est {listinv}\n")

### 3)

print("3) \n")


## Exercice 3:


### 1)

m=10
t=50
n=800
F2 = GF(2)
F2m.<alpha> = PolynomialRing(GF(2^m))
R.<x> = PolynomialRing(F2m)
g=random_poly(m, t)
L=random_uplet(n, m)



### 2)

Hcirc=[]
for i in range(t):
    Hcirc.append([(L[j]**i)*(g(L[j])).inverse for j in range(n)])

### 3)



### 4)
