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

g=polgen(alpha, 5)
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

F16z.<z>=PolynomialRing(F16)

P=z**4
t = 2
s=0
for i in range(4):
    s+=S[i]*z**i


sigma, omega = euclidedecodagebch(P, s, t)

print(f"sigma = {sigma}\n")
print(f"omega = {omega}\n")
print(f"Le polynôme localisteur est : {sigma}\n")
print(f"Ses racines sont donc : {sigma.roots(multiplicities=false)}\n")

#### c et d)
print("4.c) \n")

print(f"le mot décodé est {decodage(15, 5, alpha, f)}\n")


## Exercice 2:

# J'ai tout fait déjà pour le 1


## Exercice 3:

print("Exercice 3: \n")

### 1)

print("1) \n")

F.<a>=GF(1024)
n=1023
q=10
d=101
g=polgen(a, d)
print(f"le polynome générateur est : {g} \n")

deg=g.degree()
L=list(g)+[0 for i in range(n-g.degree())]
C = []
for i in range(n-g.degree()+1):
    C.append([0] * i + L[:len(L) - i])
print(f"Les 20 premières lignes /colonnes de la matrice génératrices sont: \n {matrix(C)[:20, :20]}\n")

### 2)

print("2) \n")

F2x.<x>=PolynomialRing(GF(2))
y=x^1016 + x^996 + x^977 + x^900 + x^883 + x^877 + x^861 + x^860 + x^859 + x^858 + x^857 + x^848 + x^845 + x^844 + x^843 + x^842 + x^841 + x^840 + x^839 + x^836 + x^835 + x^832 + x^831 + x^826 + x^825 + x^824 + x^823 + x^822 + x^820 + x^819 + x^818 + x^816 + x^814 + x^813 + x^812 + x^810 + x^805 + x^804 + x^802 + x^801 + x^800 + x^799 + x^798 + x^795 + x^793 + x^792 + x^790 + x^788 + x^786 + x^785 + x^784 + x^783 + x^779 + x^778 + x^775 + x^771 + x^769 + x^768 + x^766 + x^765 + x^764 + x^761 + x^760 + x^759 + x^758 + x^757 + x^754 + x^752 + x^750 + x^747 + x^746 + x^745 + x^743 + x^742 + x^741 + x^739 + x^735 + x^734 + x^733 + x^731 + x^729 + x^728 + x^726 + x^725 + x^723 + x^721 + x^718 + x^717 + x^716 + x^714 + x^711 + x^710 + x^709 + x^708 + x^706 + x^702 + x^700 + x^698 + x^697 + x^696 + x^694 + x^692 + x^691 + x^687 + x^685 + x^683 + x^681 + x^679 + x^678 + x^676 + x^672 + x^671 + x^670 + x^669 + x^667 + x^665 + x^663 + x^661 + x^659 + x^657 + x^655 + x^651 + x^650 + x^646 + x^644 + x^642 + x^641 + x^639 + x^635 + x^634 + x^633 + x^630 + x^627 + x^626 + x^624 + x^619 + x^617 + x^610 + x^609 + x^603 + x^600 + x^599 + x^598 + x^597 + x^596 + x^595 + x^594 + x^591 + x^588 + x^587 + x^585 + x^584 + x^581 + x^579 + x^578 + x^574 + x^572 + x^569 + x^568 + x^564 + x^563 + x^562 + x^561 + x^559 + x^558 + x^556 + x^555 + x^552 + x^551 + x^550 + x^549 + x^544 + x^542 + x^540 + x^539 + x^538 + x^536 + x^527 + x^525 + x^523 + x^521 + x^520 + x^519 + x^518 + x^517 + x^515 + x^510 + x^509 + x^506 + x^505 + x^504 + x^502 + x^501 + x^500 + x^499 + x^496 + x^494 + x^493 + x^491 + x^487 + x^486 + x^483 + x^482 + x^480 + x^479 + x^476 + x^475 + x^473 + x^472 + x^471 + x^469 + x^467 + x^463 + x^462 + x^459 + x^454 + x^453 + x^452 + x^451 + x^450 + x^447 + x^443 + x^440 + x^438 + x^436 + x^435 + x^434 + x^431 + x^430 + x^427 + x^426 + x^424 + x^423 + x^422 + x^419 + x^418 + x^416 + x^415 + x^413 + x^412 + x^410 + x^408 + x^407 + x^405 + x^404 + x^401 + x^400 + x^398 + x^397 + x^395 + x^393 + x^392 + x^391 + x^388 + x^387 + x^386 + x^385 + x^383 + x^381 + x^380 + x^376 + x^369 + x^367 + x^364 + x^360 + x^356 + x^351 + x^350 + x^348 + x^347 + x^345 + x^342 + x^339 + x^337 + x^335 + x^334 + x^333 + x^331 + x^330 + x^329 + x^328 + x^327 + x^324 + x^321 + x^316 + x^315 + x^314 + x^312 + x^311 + x^310 + x^307 + x^304 + x^302 + x^301 + x^299 + x^297 + x^293 + x^290 + x^288 + x^287 + x^284 + x^283 + x^282 + x^281 + x^280 + x^279 + x^278 + x^276 + x^274 + x^267 + x^265 + x^264 + x^263 + x^261 + x^260 + x^255 + x^252 + x^248 + x^247 + x^245 + x^242 + x^240 + x^239 + x^232 + x^225 + x^221 + x^218 + x^217 + x^216 + x^214 + x^213 + x^212 + x^210 + x^208 + x^206 + x^204 + x^202 + x^200 + x^197 + x^196 + x^195 + x^194 + x^193 + x^189 + x^185 + x^182 + x^181 + x^180 + x^179 + x^177 + x^175 + x^174 + x^173 + x^172 + x^171 + x^170 + x^169 + x^168 + x^166 + x^162 + x^161 + x^158 + x^157 + x^156 + x^155 + x^154 + x^153 + x^151 + x^148 + x^147 + x^145 + x^142 + x^141 + x^140 + x^137 + x^136 + x^135 + x^133 + x^132 + x^129 + x^127 + x^124 + x^120 + x^116 + x^110 + x^109 + x^108 + x^106 + x^104 + x^100 + x^98 + x^95 + x^91 + x^90 + x^87 + x^86 + x^85 + x^84 + x^83 + x^80 + x^79 + x^78 + x^77 + x^74 + x^73 + x^71 + x^68 + x^65 + x^63 + x^57 + x^53 + x^52 + x^50 + x^49 + x^47 + x^46 + x^45 + x^43 + x^40 + x^39 + x^36 + x^30 + x^29 + x^24 + x^21 + x^17 + x^15 + x^14 + x^13 + x^11 + x^9 + x^7 + x^4 + x
F.<a>=GF(1024)
n=1023
d=101
m=decodage(n, d, a, y)
m=F2x(m)
mm=ZZ([ZZ(u) for u in m.coefficients(sparse=False)],2).digits(200)
l=chr(mm[0])
for i in [1..len(mm)-1]:
        l = l + chr(mm[i])
print(l)