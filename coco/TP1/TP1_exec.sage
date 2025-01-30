attach("TP1_prog.sage")

## Exercice 1:
### 1.

print("Matrice de contrôle : \n", Controle(4), "\n")
print("Matrice génératrice : \n ", Generatrice(4),"\n")
print("La matrice génératrice n'est pas sous forme systématique \n")

### 2.

print("Le poids minimum est", Distance(4), "\n")

### 3.

## Exercice 2 :
### 1.

B=matrix(GF(2), 11, 11)
for i in range(11):
    for j in range(11):
        
        if ((i+j%11) in [0,1,4,9,5,3]):
            B[i,j]=1
    
A=matrix(GF(2), 12, 12)
A[0,0]=0
for j in range(1,12):
    A[0,j]=1
    A[j,0]=1
    for i in range(1,12):
        A[i,j]=B[i-1,j-1]
I=identity_matrix(GF(2), 12)
G=block_matrix([[I,A]])
print("La matrice de Golay est : \n", G)

### 2.

print("La distance minimale du code de Golay est : ", distance_generatrice(G))
