import numpy as np
from concrete import fhe
import time

def f(x, y):
    return x & y

inputset = [
    (np.random.randint(0, 2**4), np.random.randint(0, 2**4))
    for _ in range(100)
]

compiler = fhe.Compiler(f, {"x": "encrypted", "y": "encrypted"})
circuit = compiler.compile(inputset)

t=time.time()
print(circuit.encrypt_run_decrypt(0,1))
print(f"Took {time.time()-t}s")
# Code taken from Zama's documentation