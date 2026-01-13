import random
random.seed(0)

def int_to_bits(i: int, width: int=8)-> list[int]:
    return list([int(c) for c in '{:0{width}b}'.format(i, width=width)])

def bits_to_int(l: list[int], rev: bool=False) -> int:
    out = 0
    for bit in (reversed(l) if rev else l):
        out = (out << 1) | bit
    return out

def LFSR_step(P: list[int], state: list[int]) -> tuple[int,list[int]]:
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


def LFSR_multiple_steps(P: list[int], state: list[int], N: int) -> list[int]:
    tmp = state[:]
    out = []
    for i in range(N):
        bit, tmp = LFSR_step(P, tmp)
        out.append(bit)
    return tmp, out

#=======================================================
# 17-bit LFSR
P1 = [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
# 25-bit LFSR
P2 = [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1]



def css(s: list[int], N: int) -> list[int]:
    s1, s2 =  s[:16] + [1], s[16:] + [1]
    c = 0
    res = []
    #TODO
    

# test your code:
#assert css([1]*40,4) == [254, 255, 142, 185]

# ------------------ testing for question 2

def generate_s_x_z():
    # Generate a random key
    s = [random.randrange(2) for _ in range(40)]

    # Recompute the first sequence
    s1 = s[:16] + [1]
    x = []
    for i in range(3):
        s1, bits1 = LFSR_multiple_steps(P1, s1, 8)
        x.append( bits_to_int(bits1) )
    z = css(s,3)
    return s,x,z

def compute_initial_state_s2(x: list[int], z: list[int]) -> list[int]:
    """
    x: 3 bytes of output of the LFSR s1
    z: 3 bytes of output of CSS
    Return: the entire initial state s2.
    """
    #TODO
    pass

# test your code:
#s,x,z = generate_s_x_z()
#assert compute_initial_state_s2(x,z) == s[16:]



def attack(z: list[int]) -> list[int]:
    """
    z: 5 bytes of the CSS output
    Return: the entire initial state s1.
    """
    #TODO    
    pass

# test your code:
#s = [random.randrange(2) for _ in range(40)]
#z = css(s, 5)
#assert attack(z) == s


