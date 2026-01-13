
def LFSR_step(P, state):
    new_bit = 0
    for i in range(len(P)):
        new_bit ^= (P[i] * state[-i-1])
    return state[0], (state[1:] + [new_bit])


def LFSR(P, state, N):
    if len(P) != len(state):
        raise ValueError("Wrong length")
    tmp = state[:]
    out = []
    for i in range(N):
        bit, tmp = LFSR_step(P, tmp)
        out.append(bit)
    return out


def bm( s ):
    # P and Q are represented as a list of coefficients
    P = [1] + [0]*len(s)
    Q = [1] + [0]*len(s)
    Lambda = 0
    m = -1
    dp = 1
    n = len(s)
    
    for t in range(n):
        d = s[t]
        for i in range(1, Lambda+1):
            d ^= P[i] * s[t-i]
        if d != 0:
            T = P[:]
            for i in range(len(P) - (t-m)):
                P[i + t-m] = P[i + t-m] ^ Q[i]
            if 2*Lambda <= t:
                Lambda = t + 1 - Lambda
                m = t
                Q = T
                dp = d
    return P

#================
# question 2

P1 = [1,0,1,1,0,0,0,0,0,0,0,0,1]
P2 = [0,1,0,0,0,0,0,0,0,0,1]
P3 = [0,0,0,1,0,0,0,0,1]

def geffe(S1, S2, S3, N):
    
    out1 = LFSR(P1, S1, N)
    out2 = LFSR(P2, S2, N)
    out3 = LFSR(P3, S3, N)
    
    # combine
    return [ out3[i] ^ (out2[i]*out3[i]) ^ (out1[i]*out2[i]) for i in range(N) ]


S1 = [1,0,1,0,1,0,1,0,1,0,1,0,1]
S2 = [1,0,1,0,1,0,1,0,1,0,1]
S3 = [1,0,1,0,1,0,1,0,1]

assert geffe(S1, S2, S3, 20) == [1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1]
#print(geffe(S1, S2, S3, 20))

# calling BM on each LFSR to check the degree of minimal polynomial
#print( bm( LFSR(P1, S1, 40) ) )
#print( bm( LFSR(P2, S2, 40) ) )
#print( bm( LFSR(P3, S3, 40) ) )

# checking linear complexity of the full Geffe generator
#print( bm( geffe(S1, S2, S3, 800) )[:252] )


#=======================
# correlation attack

# 100 bits of challenge
challenge = [0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0,
0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0,
1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 1, 0]


# helper function: convert integer to list of bits

def int_to_bits(i, width=8):
    return list([int(c) for c in '{:0{width}b}'.format(i, width=width)])


def question8():

    # guess starting state for S1
    S1_choices = []
    
    for i in range(1 << len(P1)):
        S1_candidate = int_to_bits(i, width=len(P1))
        
        # compute LFSR sequence for this candidate
        candidate_seq = LFSR(P1, S1_candidate, 100)
        
        # compute score
        score = sum([ challenge[i]^candidate_seq[i]^1 for i in range(100) ])
        
        # determine a threshold: 65 should be a good start
        if score > 70:
            S1_choices.append( S1_candidate )
            print("s1",S1_candidate)
            print(score)
    #print(S1_candidate)
    
    S3_choices = []
    for i in range(1 << len(P3)):
        S3_candidate = int_to_bits(i, width=len(P3))
        
        # compute LFSR sequence for this candidate
        candidate_seq = LFSR(P3, S3_candidate, 100)
        
        # compute score
        score = sum([ challenge[i]^candidate_seq[i]^1 for i in range(100) ])
        
        # determine a threshold: 65 should be a good start
        if score > 65:
            S3_choices.append( S3_candidate )
            print(S3_candidate)
            print(score)
    
    for i in range(1 << len(P2)):
        S2_candidate = int_to_bits(i, width=len(P2))
    
        for S1_candidate in S1_choices:
            
            for S3_candidate in S3_choices:
                # try this
                candidate_seq = geffe(S1_candidate, S2_candidate, S3_candidate, 100)
                score = sum([ challenge[i]^candidate_seq[i]^1 for i in range(100) ])
                
                if score == 100:
                    print("========= found!")
                    print( S1_candidate )
                    print( S2_candidate )
                    print( S3_candidate )
                
    
        
question8()



