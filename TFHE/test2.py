import numpy as np
from concrete import fhe
configuration = fhe.Configuration(verbose=True)

def smallest_prime_divisor(n):
    if n % 2 == 0:
        return 2

    for i in range(3, int(np.sqrt(n)) + 1):
        if n % i == 0:
            return i

    return n


def mean_of_vector(x):
    assert x.size != 0
    if x.size == 1:
        return x[0]

    group_size = smallest_prime_divisor(x.size)
    if x.size == group_size:
        return np.round(np.sum(x) / x.size).astype(np.int64)

    groups = []
    for i in range(x.size // group_size):
        start = i * group_size
        end = start + group_size
        groups.append(x[start:end])

    mean_of_groups = []
    for group in groups:
        mean_of_groups.append(np.round(np.sum(group) / group_size).astype(np.int64))

    return mean_of_vector(fhe.array(mean_of_groups))

compiler = fhe.Compiler(mean_of_vector, {"x": "encrypted"})


inputset = [[np.random.randint(0, 10) for _ in range(10)] for _ in range(100)]
vector = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

circuit = compiler.compile(inputset, configuration=configuration)

print(circuit.encrypt_run_decrypt(vector) == round(np.array(vector).mean()))
print(round(np.array(vector).mean()))

