from concrete import fhe
import time
import numpy as np
import matplotlib.pyplot as plt
from math import *

def add(L):
    return np.sum(L)
temps=[]
for n in range(2,50):
    compiler = fhe.Compiler(add, {"L": "encrypted"})

    size=n
    inputset = [[np.random.randint(0, 10) for _ in range(size)] for _ in range(50)]
    circuit = compiler.compile(inputset)
    circuit.keygen()
    t=time.time()
    L = np.array([np.random.randint(0, 10) for _ in range(size)])
    encrypted_list = circuit.encrypt(L)
    encrypted_result = circuit.run(encrypted_list)
    result = circuit.decrypt(encrypted_result)
    t=time.time()-t
    temps.append(t)
plt.plot(temps)
plt.xlabel('n')
plt.ylabel('Time (s)')
plt.title('Time taken to encrypt then sum then decrypt n elements')
plt.show()

print(f"the first plot took {np.sum(temps)} seconds\n")


def multiplylist(L, M):
    return L*M

temps=[]
for n in range(2,50):
    compiler = fhe.Compiler(multiplylist, {"L": "encrypted", "M": "encrypted"})

    size=n
    inputset = [([np.random.randint(0, 10) for _ in range(size)],[np.random.randint(0, 10) for _ in range(size)]) for _ in range(50)]
    circuit = compiler.compile(inputset)
    circuit.keygen()
    t=time.time()
    L = [np.random.randint(0, 10) for _ in range(size)]
    M= [np.random.randint(0, 10) for _ in range(size)]
    encrypted_L,encrypted_M = circuit.encrypt(L, M)
    encrypted_result = circuit.run(encrypted_L, encrypted_M)
    result = circuit.decrypt(encrypted_result)
    t=time.time()-t
    temps.append(t)

plt.plot(temps)
plt.xlabel('n')
plt.ylabel('Time (s)')
plt.title('Time taken to encrypt then multiply then decrypt n elements')
plt.show()
print(f"the second plot took {np.sum(temps)} seconds\n")

print("Now we will test the lookup table\n")
table = fhe.LookupTable([1, 2, 4, 8, 16, 32, 64, 128, 256])
@fhe.compiler({"x": "encrypted"})
def exp_b2(x):
    return table[x]

inputset = range(9)
circuit = exp_b2.compile(inputset)

t=time.time()
print(circuit.encrypt_run_decrypt(5))
print(f"This operation took {time.time()-t} seconds\n")

print("Now we will test the bitwise and\n")
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
print(f"This operation took {time.time()-t} seconds\n")