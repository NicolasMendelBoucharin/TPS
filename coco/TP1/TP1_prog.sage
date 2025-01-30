#TP1 Codes Correcteurs 2025 : codes linéaires, les programmes

#Poids d'un mot
#entrée : c, sous forme de vecteur ou de liste
#sortie : poids de Hamming de c
def Poids(c):#poids d'un mot défini sous forme de vecteur ligne
	res = 0
	n = len(c)
	for i in range(n):
		if not(c[i]==0):
			res=res+1
	return(res)


#matrice de contrôle d'un code de Hamming
#entrée : un entier r non nul
#sortie : matrice de controlle pour le code de Hamming binaire de longueur n=2^r-1
def Controle(r):
	n = 2^r-1
	L=[]
	for i in [1..n]:
		L.append(i.digits(2, padto=r))
	M = matrix(GF(2),L)
	M=M.transpose()
	return(M)

#matrice génératrice d'un code de Hamming
#entrée : un entier r non nul
#sortie : matrice génératrice pour le code de Hamming binaire de longueur n=2^r-1 (à l'aide de la matrice de contrôle)
def Generatrice(r):
	n = 2^r-1
	H = Controle(r)
	G = H.right_kernel().basis_matrix()
	return(G)

#distance minimale d'un code de Hamming
#entrée : un entier r non nul
#sortie : distance minimale du code de Hamming binaire de longueur n=2^r-1
def Distance(r):
	n = 2^r-1
	G=Generatrice(r)
	S=G.row_space()
	minimum=n
	for word in S:
		if Poids(word)<minimum and Poids(word)!=0:
			minimum=Poids(word)
	return(minimum)

#décodage du code de Hamming
#entrée : la matrice de contrôle H d'un code hamming,la matrice génératrice G du même code, un mot de longueur n=2^r-1
#sortie : mot corrigé


def décodage_hamming(H, r):
	S=H*r.transpose()
	if S==0:
		c=r	
	else:
		i=integer(S,2)-1
		e=vector(GF(2),[0]*len(r))
		e[i]=1
		c=r-e
	return(c)

#Nouvelle fonction pour la distance minimale en partant d'une matrice génératrice quelconque
#entrée : matrice génératrice G d'un code quelconque
#sortie : distance minimale du code quelconque

def distance_generatrice(G):
	S=G.row_space()
	minimum=len(G[0])
	for word in S:
		if Poids(word)<minimum and Poids(word)!=0:
			minimum=Poids(word)
	return(minimum)