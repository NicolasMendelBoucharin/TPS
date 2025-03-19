#TODO
#corriger les matrices génératrices



## Exercice 1:
print("Exercice 1: \n")

### 1)

print("1) \n")

F2x.<x>=PolynomialRing(GF(2))
P=x^4+x+1
F16.<alpha>=GF(2**4, 'alpha', modulus = P)
print(f"alpha^15 = {alpha^15} et alpha est bien une racine primitive 15e de l'unité \n" )

### 2)

print("2) \n")

n=15
k=3
d=13

H=[]
for i in range(4):
    H.append([alpha^(i*j) for j in range(15)])
H=matrix(H)
print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir")
#print(f"la matrice de contrôle est {H} \n")

### 3)

print("3) \n")

G = H.right_kernel().basis_matrix()
G=G.echelon_form()
print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir")
print(f"La matrice génératrice est: \n {G}")

### 4)
 
print("4) \n")


M=[]
for f in F2x.polynomials(max_degree=2):
    M.append([f(alpha^(i)) for i in range(15)])
M=matrix(M) 
Gprime=M.right_kernel().basis_matrix()
Gprime=Gprime.echelon_form()

print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir")   
#print(f"La matrice génératrice est: \n {Gprime} \n")

### 5)

print("5) \n")

print("La matrice génératrice est la même que celle de la question 3, donc le code est systématique \n")
## Exercice 2:

print("Exercice 2: \n")


### 1)

print("1) \n")

F2x.<x> = PolynomialRing(GF(2))
for f in F2x.polynomials(max_degree=3):
    print(f)
### 2)

print("2) \n")

### 3)

print("3) \n")

### 4)

print("4) \n")

## Exercice 3:

print("Exercice 3: \n")

### 1)

print("1) \n")

### 2)

print("2) \n")
