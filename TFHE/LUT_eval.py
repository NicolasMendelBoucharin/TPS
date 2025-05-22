from concrete import fhe
import time
from math import *

table = fhe.LookupTable([1, 2, 4, 8, 16, 32, 64, 128, 256])
@fhe.compiler({"x": "encrypted"})
def exp_b2(x):
    return table[x]

inputset = range(9)
circuit = exp_b2.compile(inputset)

t=time.time()
print(circuit.encrypt_run_decrypt(5))
print(f"This operation took {time.time()-t} seconds")