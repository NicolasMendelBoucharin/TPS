attach('TP3_prog.sage')
## Exercice 1:

print("Exercice 1: \n")

### 1)

print("1) \n")
F2x.<x>=PolynomialRing(GF(2))
P= x^4 + x^3 + 1
F16.<alpha>=GF(2**4, 'alpha', modulus = P)
print(f"alpha 15 = {alpha**15}")

### 2)

print("2) \n")

L=[]
for i in range (1, 5):
    L.append(polmin(alpha, i, 2, 15))
L=set(L)
g=lcm(L)
print(f"le polynôme générateur est : {g}\n")

### 3)

print("3) \n")

deg=g.degree()
L=list(g)+[0 for i in range(15-g.degree())]
C = []
for i in range(15-g.degree()+1):
    C.append([0] * i + L[:len(L) - i])
print(matrix(C))

### 4)

#### a)

print("4.a) \n") 
f=x^12+x^11+x^8+x^7+x^6+x^5+x^4+1
S=[]
for i in range(4):
    S.append(f(alpha**(i+1)))
print(f"Les 4 premiers S_i sont : {S}\n")

#### b)

print("4.b) \n")

F16z.<z>=PolynomialRing(GF(2**4))
