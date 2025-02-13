attach("TP2_prog.sage")


## Exercice 1:
print("Exercice 1 :\n")
### 1.


### 2.
print("2)\n")
print("Le poids minimum du code de hamming est", Distance(4), "\n")



M=[vector(GF(2),[randint(0,1) for i in range(11)]) for i in range(10)]
for m in M:
    c=canal(m*G,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", décodage_hamming(Controle(4), Generatrice(4), c), "\n")

## Exercice 2 :
print("Exercice 2 :\n")
### 1.
print("1)\n")
B=matrix(GF(2), 11, 11)
for i in range(11):
    for j in range(11):
        
        if (((i+j)%11) in [0,1,4,9,5,3]):
            B[i,j]=1
    
A=matrix(GF(2), 12, 12)
A[0,0]=0
for j in range(1,12):
    A[0,j]=1
    A[j,0]=1
    for i in range(1,12):
        A[i,j]=B[i-1,j-1]
I=identity_matrix(GF(2), 12)
G24=I.augment(A)
print("La matrice de Golay est : \n", G24)

### 2.
print("2)\n")
print("La distance minimale du code de Golay est : ", distance_generatrice(G24), "\n")

### 3.
print("3)\n")
d=distance_generatrice(G24)
M=[vector(GF(2),[randint(0,1) for i in range(12)]) for i in range(10)]
for m in M:
    c=canal(m*G24,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", décodage_golay(A,c), "\n")

## Exercice 3 :
print("Exercice 3 :\n")

### 2.
print("2)\n")
print("Test recherche exhaustive sur le code de Hamming : \n")
G=Generatrice(4)
d=distance_generatrice(G)
M=[vector(GF(2),[randint(0,1) for i in range(11)]) for i in range(5)]
for m in M:
    c=canal(m*G,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", recherche_exhaustive(G, c), "\n")

print("Test recherche exhaustive sur le code de Golay : \n")
d=distance_generatrice(G24)
M=[vector(GF(2),[randint(0,1) for i in range(12)]) for i in range(5)]
for m in M:
    c=canal(m*G24,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", recherche_exhaustive(G24, c), "\n")

## Exercice 4 :
print("Exercice 4 :\n")

### 3.
print("3)\n")

print("Test décodage par syndrome sur le code de Hamming : \n")
G=Generatrice(4)
H=Controle(4)
d=distance_generatrice(G)
t=(d-1)//2
T=tableau_standard(H,t)
M=[vector(GF(2),[randint(0,1) for i in range(11)]) for i in range(5)]
for m in M:
    c=canal(m*G,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", décodage_syndrome(G, H, T, t, c), "\n")

print("Test décodage par syndrome sur le code de Golay : \n")
d=distance_generatrice(G24)
H24 = G24.right_kernel().basis_matrix()
t=(d-1)//2
T=tableau_standard(H24,t)

M=[vector(GF(2),[randint(0,1) for i in range(12)]) for i in range(5)]
for m in M:
    c=canal(m*G24,d)
    print("Le mot de code associé à", m, "est bruité en ",c, "et corrigé en", décodage_syndrome(G24, H24, T, t, c), "\n")