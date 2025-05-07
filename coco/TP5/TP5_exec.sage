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
F2m.<a> = GF(2^m)
R.<x> = PolynomialRing(F2m)
ev, _, _ = F2m.vector_space()


g=random_poly(m, t)

L=random_uplet(n, m)

G=goppa_gen(L, g, m, ev)

print(f"le code de goppa pour {L} et {g} est \n {G}\n")

### 2)

print("2) \n")


listinv = []
for i in range(n):
    a=(x-L[i]).inverse_mod(g^2)
    listinv.append(a)
print(f"La liste des inverses est \n {listinv}\n")

### 3)

print("3) \n")


## Exercice 3:

print("Exercice 3: \n")

### 1)

print("1) \n")
m=10
t=50
n=800



F2 = GF(2)
F2m.<a> = GF(2^m)
R.<x> = PolynomialRing(F2m)
ev, _, _ = F2m.vector_space()
g=random_poly(m, t)
L=random_uplet(n, m)

print(g)
print(L)

### 2)

print("2) \n")

Hcirc=[]
for i in range(t):
    Hcirc.append([(L[j]**i)*(g(L[j]))**(-1) for j in range(n)])



### 3)

print("3) \n")
r=g.degree()
M=[[0 for i in range(n)] for j in range(t*m)]   
for i in range(t):
    for j in range(n):
        Mij = ev.coordinate_vector(Hcirc[i][j])
        for k in range(m):
            M[i*m +k][j]= Mij[k]
H = matrix(GF(2), M).rref()

print(H[:m*t,:m*t])
if H.rank() == m*t:
    print("La matrice est de rang maximal")
print("________________________________________________________________________________")
    
### 4)

cleprive= open("cleprive.sage", "w")
clepublique= open("clepublique.sage", "w")

print("4) \n")

while (H[:,:m*t] != identity_matrix(GF(2), m*t)):
    H, L, g =goppa_gen2(m, n, t, ev)

T=H[:,m*t:]
cleprive.write(f"g = {g}\n L= {L}")
clepublique.write(f"T = matrix(GF(2),{[list(T_i) for T_i in T]})\n")

print("ça marche là normalement")
