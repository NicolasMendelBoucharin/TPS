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
    #définition de la matrice de controle de Hamming
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
    #on passe de la matrice de controle à la matrice génératrice
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
	#on prend le mot de poids minimal dans le code de hamming et on le renvoie
	S=G.row_space()
	minimum=n
	for word in S:
		if Poids(word)<minimum and Poids(word)!=0:
			minimum=Poids(word)
	return(minimum)

#décodage du code de Hamming
#entrée : la matrice de contrôle H d'un code hamming,la matrice génératrice G du même code, un mot de longueur n=2^r-1 avec une erreur
#sortie : mot corrigé


def décodage_hamming(H, G, r):
	S=H*r
	S=[S[i] for i in range(len(S))] #converti en liste sinon on peut pas avoir les integers de S
	if S==0:
		c=r	
	else:
		i=Integer(S,2)-1
		e=vector(GF(2),[0]*len(r))
		e[i]=1
		c=r+e
	return((G.solve_left(matrix(c))))

#Nouvelle fonction pour la distance minimale en partant d'une matrice génératrice quelconque
#entrée : matrice génératrice G d'un code quelconque
#sortie : distance minimale du code quelconque

def distance_generatrice(G):
    #on prends le poids minimal de tous les mots du code
	S=G.row_space()
	L=[]
	for c in S:
		if Poids(c)!=0:
			L.append(Poids(c))
	return(min(L))

#fonction qui simule un canal de transmission produisant au plus t erreurs sur un mot c
#entrée : un mot c, un entier d(distance minimale du code)
#sortie : mot reçu

def canal(m,d):
	n=len(m)
	t=(d-1)//2
	#liste d'indices aléatoires des bits à modifier(au plus t)
	rand = [randrange(n) for i in range(t)]
	#je convertie en liste pour que ce soit plus facile à manipuler
	canalise = [m[i] for i in range(n)]
	for i in rand:
		canalise[i]=(canalise[i]+1)%2
	return(vector(GF(2),canalise))
		
	
#décodage du code de Golay binaire étendu de longueur 24
#entrée : la matrice A de droite dans le code de golay, un mot de code de longueur 24 avec au plus 3 erreurs
#sortie : mot corrigé

def décodage_golay(A,r):
	#j'ai recopié le code du cours
	T=G24*r
	if Poids(T)<=3:
		return(T+r[:12])
	else:
		for i in range(12):
			if Poids(T+A.column(i))<=2:
				return r[:12] + T + A.column(i)
		else:
			S=(A.transpose())*T
			if Poids(S)<=3:
				return (r[:12])
			else:
				for i in range(12):
					if Poids(S+A.column(i))<=2:
						return (r[:12] + vector(GF(2),[1 if j == i else 0 for j in range(12)]))
				else:
					return False
	
#décodage par recherche exhaustive dans un code binaire
#entrée : Une matrice génératrice, un mot reçu
#sortie : mot corrigé

def recherche_exhaustive(G,c):
	t=(distance_generatrice(G)-1)//2
	S=G.row_space()
	#dès qu'on trouve un mot du code qui est à distance <= t du mot reçu, on le renvoie
	for s in S:
		if Poids(c-s)<=t:
			return(G.solve_left(matrix(s)))


#calcul du tableau standard
#entrée : Une matrice de contrôle H, t un entier
#sortie : tableau standard des coset leader x de poids<=t, syndrome de x]

def tableau_standard(H,t):
    n=len(H[0])
    standard_table={}
    #plutôt que d'utiliser les cosets et l'espace vectoriel, on génère tout les mots du code de poids inférieur à t avec les permutations
    for v in Permutations([0]*n + [1]*t, n):
        v=vector(GF(2),v)
        v.set_immutable()
        s=H*v
        if not (s in standard_table.values()):
            standard_table[v]=s
    return(standard_table)
		   
    
 
 #décodage par syndrôme
 #entrée : Une matrice génératrice, une matrice de contrôle, un tableau standard des coset leader, une capacité de correctoi ndu code et y un code recu brouillé
 #sortie : mot corrigé

def décodage_syndrome(G, H, T, t, y):
	s=H*y
	for v in T:
		if T[v]==s:
			c=y+v
			return(G.solve_left(matrix(c)))
	