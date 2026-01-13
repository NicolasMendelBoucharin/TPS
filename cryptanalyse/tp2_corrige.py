

# helper function for question 6: convert integer to list of bits

def int_to_bits(i, width=8):
    return list([int(c) for c in '{:0{width}b}'.format(i, width=width)])

def LFSR_step(P, state):
    """
    Input:
        P -- retroaction polynomial of the form 1 + \sum_{i=1}^\ell c_i X^i,
            represented as [c_1, ..., c_ell]
        state -- state at time t: s_n, ... s_{n+ell-1}
        
        Returns the state at time t+1 and the output at time t.
    """
    new_bit = 0
    for i in range(len(P)):
        new_bit ^= (P[i] * state[-i-1])
    return state[0], (state[1:] + [new_bit])


def LFSR(P, state, N):
    tmp = state[:]
    out = []
    for i in range(N):
        bit, tmp = LFSR_step(P, tmp)
        out.append(bit)
    return out


# check with the LFSR given in the lecture
assert LFSR([0,0,1,1], [1,0,1,1], 15) == [1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0]

#=================================
# find the period of the LFSR

def LFSR_period(P, state):
    tmp = state[:]
    i = 1
    bit, tmp = LFSR_step(P, tmp)
    while tmp != state:
        bit, tmp = LFSR_step(P, tmp)
        i += 1
    return i

#print( LFSR([0,0,0,1,1], [0,0,1,0,1], 10 ) )

# check with the LFSR of the lecture: period should be 15
#print( LFSR_period([0,0,1,1], [1,0,1,1]) )
# get the period: 21
#print( LFSR_period([0,0,0,1,1], [0,0,1,0,1]) )

#==========================
# Question 5: return all states obtained on a period

def LFSR_period_states(P, state):
    if len(state) != len(P):
        raise ValueError("Wrong length")
    tmp = state[:]
    out = [tmp]
    i = 1
    bit, tmp = LFSR_step(P, tmp)
    while tmp != state:
        out.append( tmp )
        bit, tmp = LFSR_step(P, tmp)
        i += 1
    return out

def question5():
    P = [0,0,0,1,1]

    for state in [ [0,0,1,0,1], [0,1,0,0,0], [1,0,1,0,0] ]:
        print("========== Initial state: ", state)
        for s in LFSR_period_states(P, state):
            print(s)


#print(LFSR_period_states([0,0,0,1,1], [0,0,0,0,0]))

def question6(P):
    """Return all cycles of the LFSR."""
    cycles = [] # list of lists of tuples
    covered = set()
    # look at all non-zero states
    
    for i in range(1 << len(P)):
        # convert to state
        s = (int_to_bits(i, len(P)))
        if tuple(s) not in covered:
            new_states = LFSR_period_states(P, s)
            new_states = [tuple(t) for t in new_states]
            cycles.append(new_states)
            for t in new_states:
                covered.add(t)
    return cycles
    
#for c in question6([0,0,0,1,1]):
#    print(c)

# 1 + X^2 + X^4
#print( len(question6([0,1,0,1])) ) # not primitive

# 1 + X + X^2 + X^3 + X^4
#print( len(question6([1,1,1,1])) ) # not primitive

# 1 + X + X^4
#print( len(question6([1,0,0,1])) ) # is primitive

#===================================
# Question 9 (Berlekamp-Massey)

def question9( s ):

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

seq = LFSR([0,0,1,1], [1,0,1,1], 15)

seq = LFSR([0,0,1,1,1,0], [0,1,1,0,1,1], 10)

print( question9(seq) )




