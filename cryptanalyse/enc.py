
import numpy as np
import random as rd


S = [0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6]

M = [[0,1,1,1],[1,0,1,1],[1,1,0,1],[1,1,1,0]]

def ARK(m,k):
    return [[m[j][i] ^ k[j][i] for i in range(4)] for j in range(4)]

def SB(m):
    return [[S[i] for i in m[j]] for j in range(4)]

def SR(m):
    return [ m[i][i:] + m[i][:i] for i in range(4)]

def invSR(m):
    return [ m[i][4-i:] + m[i][:4-i] for i in range(4)]

def dot(col,row):
    d = 0
    for i in range(4): d ^= col[i]*row[i]
    return d

def MC(m):
    return [[dot(M[j],np.array(m)[:,i]) for i in range(4)] for j in range(4)]


def Enc(m,k,Nr):

    m = [m[0:4], m[4:8], m[8:12], m[12:16]]
    k = [k[0:4], k[4:8], k[8:12], k[12:16]]

    for _ in range(Nr):

        m = ARK(m,k)
        m = SB(m)
        m = SR(m)
        m = MC(m)
 
    return m[0] + m[1] + m[2] + m[3]

def Dec(c,k,Nr):

    c = [c[0:4], c[4:8], c[8:12], c[12:16]]
    k = [k[0:4], k[4:8], k[8:12], k[12:16]]

    for _ in range(Nr):

        c = MC(c)
        c = invSR(c)
        c = SB(c)
        c = ARK(c,k)

    return c[0] + c[1] + c[2] + c[3]

# faire : flipper un bit de m ou k --> regarder les bits de différence de c

#m = [rd.randint(0,15) for _ in range(16)]
#k = [rd.randint(0,15) for _ in range(16)]

m = [i for i in range(16)]
k = [i for i in range(16)]

Nr = 3
incidence=[0]*64

for i in range(64):

    m_bis = [i for i in range(16)] # m_bis = m est par référence
    m_bis[i//4] ^= 1 << (3 - i%4)
    
    c = Enc(m,k,Nr)
    c_bis = Enc(m_bis,k,Nr)

    xor = [c[i]^c_bis[i] for i in range(16)]
    
    for b in xor:
        if (b != 0): 
            incidence[i] += 1

#print(incidence) 
    
m = [0 for _ in range(16)]
k = [1 for _ in range(16)]

state = [i for i in range(16)]
print(Enc(state,k,1))
print(Dec(Enc(state,k,1), k,1))
state2 = [(i+1)%16 for i in range(16)]
print(Enc(state2,k,1))
print(Dec(Enc(state2,k,1), k,1))

# c = Enc(m,k,1)
# print(c)
# print(Dec(c, k, 1))





