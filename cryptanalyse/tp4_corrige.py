
from hashlib import sha256, md5, sha1
from random import randrange, seed

seed(0)
N = 48

def h(i: int, m: int) -> int:
    """
    Args:
        m (int): Message block.
        i (int): Index.

    Returns:
        int: hash of the message block, under given index.
    """
    if m >= (1 << N) or m < 0:
        raise ValueError("Invalid message")
    if i < 0:
        raise ValueError("Invalid index")
    data = i.to_bytes(4, 'little') + m.to_bytes(8, 'little')
    result = int(sha256(data).hexdigest()[:(N//4)], 16)
    return result

def bit_reverse(x, width):
    return int(f"{x:0{width}b}"[::-1], 2)

def lower(x1: int, x2: int, c: int) -> bool:
    """
    Return True iff the c LSBs of x1 are strictly smaller (in lexicographic
    ordering of bit-strings) than the c LSBs of x2.
    """
    return bit_reverse(x1% (1 << c), c) < bit_reverse(x2% (1 << c), c)

def eq(x1: int, x2: int, c: int) -> bool:
    """
    Return True iff the c LSBs of x1 are equal to the c LSBs of x2.
    """
    return x1 % (1 << c) == x2 % (1 << c)

def sort(l: list[tuple[int,...]]) -> list[tuple[int,...]]:
    """
    Sort the list according to lexicographic ordering of bit-strings, on the
    first value of the tuples.
    """
    return sorted(l, key=lambda x: bit_reverse(x[0], N))


def merge(l1: list[tuple[int,...]], l2: list[tuple[int,...]], cc: int) -> list[tuple[int,...]]:
    """
    Merge the lists l1 and l2, taking partial collisions of the cc LSBs.
    If the list l1 contains tuples noted (x1[0],) + x1[1:]) and the list l2 contains
    tuples (x2[0],) + x2[1:]), then the output list contains tuples of the form
    (x1[0] + x2[0],) + x1[1:] + x2[1:] . That is, we concatenate the remaining
    parts of the tuples.
    
    Assumption: l1 and l2 must be sorted.
    """
    it1 = 0
    it2 = 0
    n1,n2 = len(l1), len(l2)
    result = []
    while it1 < n1 and it2 < n2:
        a,b = l1[it1][0], l2[it2][0]
        if eq(a,b,cc):
            tmp1,tmp2 = it1,it2
            while it1 < n1 and eq(l1[it1][0],a,cc):
                it1 += 1
            while it2 < n2 and eq(l2[it2][0],b,cc):
                it2 += 1
    
            for x in range(tmp1,it1):
                for y in range(tmp2,it2):
                    result.append( (l1[x][0]^l2[y][0],) + l1[x][1:] + l2[y][1:] ) 
    
        elif lower(a,b,cc):
            it1 += 1
        else:
            it2 += 1
    
    return sort(result)

# example
l1 = [(34, 150), (86, 52), (97, 144), (81, 151), (197, 53), (251, 208), (7, 255), (31, 13)]
l2 = [(240, 59), (130, 111), (146, 178), (170, 66), (73, 112), (121, 224), (187, 210), (167, 25)]
ll = [(64, 208, 210), (160, 150, 111), (160, 255, 25), (176, 150, 178)]
assert merge(l1,l2,4) == ll

# ----------------------------------------


def full_attack():
    # now for the full attack, we select a starting list size which is around 2^(48/3 ) = 2^16
    START_SIZE = (1 << 16)

    x1 = [randrange(1 << N) for _ in range(START_SIZE)]
    l1 = sort([(h(1,x), x) for x in x1])

    x2 = [randrange(1 << N) for _ in range(START_SIZE)]
    l2 = sort([(h(2,x), x) for x in x2])

    x3 = [randrange(1 << N) for _ in range(START_SIZE)]
    l3 = sort([(h(3,x), x) for x in x3])

    x4 = [randrange(1 << N) for _ in range(START_SIZE)]
    l4 = sort([(h(4,x), x) for x in x4])

    # now we merge on 16 bits
    l12 = merge(l1, l2, 16)
    print("Merging l1 & l2",len(l12))
    l34 = merge(l3, l4,16)
    print("Merging l3 & l4",len(l34))

    # do not forget to sort again!!!
    l12 = sort(l12)
    l34 = sort(l34)

    # next we merge on 48 bits (we want to find a collision, that is)
    lm = merge(l12,l34,N)

    print(lm)
    # check the result

    _,t1,t2,t3,t4 = lm[0]
    assert h(1,t1) ^ h(2,t2) ^ h(3,t3) ^ h(4,t4) == 0

full_attack()


