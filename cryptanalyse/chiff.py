import numpy as np

def AddKey(state,key) : # inverse d'elle même
    for i in range (4) : 
        for j in range (4) :
            state[i][j] = state[i][j] ^ key[i][j]
    return state

def sBox(a): # inverse d'elle même 
    S = [0xc,0xa,0xd,0x3,0xe,0xb,0xf,0x7,0x8,0x9,0x1,0x5,0x0,0x2,0x4,0x6]
    return S[a]

def s(state) : 
    for i in range (4) :
        for j in range(4) : 
            state[i,j] = sBox(state[i,j])
    return state

def SR(state):
    for i in range (1,4) :
        if (i == 1) : 
            temp = state[i][0]
            state[i][0] = state[i][1]
            state[i][1] = state[i][2]
            state[i][2] = state[i][3]
            state[i][3] = temp
        if (i == 2) : 
            temp1 = state[i][0]
            temp2 = state[i][1]
            state[i][0] = state[i][2]
            state[i][1] = state[i][3]
            state[i][2] = temp1
            state[i][3] = temp2
        if (i == 3) : 
            temp = state[i][3]
            state[i][3] = state[i][2]
            state[i][2] = state[i][1]
            state[i][1] = state[i][0]
            state[i][0] = temp
    return state


def invSR(state):
    for i in range (1,4):
        if (i == 1) : 
            temp = state[i][3]
            state[i][3] = state[i][2]
            state[i][2] = state[i][1]
            state[i][1] = state[i][0]
            state[i][0] = temp
        if (i == 2) : 
            temp1 = state[i][3]
            temp2 = state[i][2]
            state[i][3] = state[i][1]
            state[i][2] = state[i][0]
            state[i][1] = temp1
            state[i][0] = temp2
        if (i == 3) : 
            temp = state[i][0]
            state[i][0] = state[i][1]
            state[i][1] = state[i][2]
            state[i][2] = state[i][3]
            state[i][3] = temp
    return state



def MC(state): # inverse d'elle même
    M = np.array([[0x0, 0x1, 0x1, 0x1], [0x1, 0x0, 0x1, 0x1],  [0x1, 0x1, 0x0, 0x1],  [0x1, 0x1, 0x1, 0x0]])
    res = np.zeros((4,4),dtype=int)
    for i in range (4) : 
        for j in range(4) :
            for k in range (4) : 
                res[i,j] ^= (M[i,k] * state[k,j])
    return res

def oneRoundEnc(state,key) : 
    state = AddKey(state,key)
    state = s(state)
    state = SR(state)
    state = MC(state)
    return state

def oneRoundDec(state,key) : 
    state = MC(state)
    state = invSR(state)
    state = s(state)
    state = AddKey(state,key)
    return state

def enc(state,key,N):
    for _ in range (N) : 
        state = oneRoundEnc(state,key) 
    return state

def dec(state,key,N):
    for _ in range(N) : 
        state = oneRoundDec(state,key)
    return state



msg1 = np.array([[0x0, 0x0, 0x0, 0x0], [0x0, 0x0, 0x0, 0x0],  [0x0, 0x0, 0x0, 0x0],  [0x0, 0x0, 0x0, 0x0]])
msg2 = np.array([[0x0, 0x0, 0x0, 0x0], [0x1, 0x0, 0x0, 0x0],  [0x0, 0x0, 0x0, 0x0],  [0x0, 0x0, 0x0, 0x0]])
key = np.array([[0x1, 0x1, 0x1, 0x1], [0x1, 0x1, 0x1, 0x1],  [0x1, 0x1, 0x1, 0x1],  [0x1, 0x1, 0x1, 0x1]])
# print(msg1)
# print(msg2)
N = 7

chiffre = enc(msg1,key,N)
print(chiffre)

chiffre2 = enc(msg2,key,N)
print(chiffre2)


# dechiffre = dec(chiffre,key,1)
# print(dechiffre)