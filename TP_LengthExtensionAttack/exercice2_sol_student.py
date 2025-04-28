
from pwn import * 
import json

from tqdm import tqdm
from custom_md5 import *

HOST = "localhost"
PORT = 13407

r = remote(HOST, PORT)

print(r.readline()) # Réception du premier message envoyé par le serveur

def bxor(a, b):
    return bytes(x ^ y for x, y in zip(a, b))

def bytes_to_hexstring(barray):
    return ''.join('{:02x}'.format(x) for x in barray)

def json_recv():
    line = r.readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

# Fonction de padding
def pad(m:bytes):
    l = len(m)
    m += b'\x80'
    while len(m) % 64 != 56:
        m += b"\x00"
    return m + (l * 8).to_bytes(8,byteorder='little')

# Inverse la fonction de finalisation de MD5, vous en avez besoin pour retrouver
# l'état interne de la chaine de compression (s_k dans le sujet).
def reverse_finalize(hash: bytes):
    if len(hash) != 32:
        raise ValueError("The input hash must be 32 bytes long.")
    # Split the hash into 4 equal parts
    parts = [hash[i:i + 8] for i in range(0, 32, 8)]
    # Convert each part to little-endian format
    little_endian_parts = []
    for part in parts:
        temp = ""
        little_endian = part[::-1] # Revert It
        for j in range(0,len(little_endian),2): # For every hex digit
            temp += little_endian[j+1] + little_endian[j] # Make it little endian
        little_endian_parts.append(temp) 
    A = int(little_endian_parts[0],16)
    B = int(little_endian_parts[1],16)
    C = int(little_endian_parts[2],16)
    D = int(little_endian_parts[3],16)
    return A,B,C,D