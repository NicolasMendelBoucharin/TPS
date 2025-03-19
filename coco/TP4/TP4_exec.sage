#TODO
#corriger les matrices génératrices

#trop bizarre que mon alpha^2 soit alpha +1 et que mon alpha^3 soit alpha^2    

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

V=[[]for i in range (n-k)]
for i in range(n-k):
        V[i]=[alpha^(i*j) for j in range(n)]
V=matrix(V)
D=diagonal_matrix(n, set([alpha^i for i in range(n)]))
H=V*D
print(V)
print(D)
print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir\n")
print(f"la matrice de contrôle est {H} \n")


### 3)

print("3) \n")

G = H.right_kernel().basis_matrix()

print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir\n")
print(f"La matrice génératrice est: \n {G} \n")

### 4)
 
print("4) \n")


M=[]
for f in F2x.polynomials(max_degree=2):
    if f!=0:
        
        M.append([f(alpha^(i)) for i in range(15)])
M=matrix(M) 
Gprime=M.right_kernel().basis_matrix()
Gprime=Gprime.echelon_form()

print("La matrice est horrible à lire mais il suffit de décomenter la ligne après ce message pour la voir\n")   
print(f"La matrice génératrice est: \n {Gprime} \n")

### 5)

print("5) \n")

print("La matrice génératrice est la même que celle de la question 3, donc le code est systématique \n")
## Exercice 2:

print("Exercice 2: \n")


### 1)

print("1) \n")


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

P=x^10 + x^6 + x^5 + x^3 + x^2 + x + 1
F1024.<alpha>=GF(2**10, 'alpha', modulus = P)
n=1023
k=512
d=512  

M=[]
for f in F2x.polynomials(max_degree=511):
    if f!=0:
        M.append([f(alpha^(i)) for i in range(1023)])
M=matrix(M)
Gprime=M.right_kernel().basis_matrix()
Gprime=Gprime.echelon_form()