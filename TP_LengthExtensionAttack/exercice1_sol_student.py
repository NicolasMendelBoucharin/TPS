from pwn import * # pip install pwntools
import json
from Crypto.Util.Padding import pad
from Crypto.Cipher import AES


def bxor(a, b):
    return bytes(x ^ y for x, y in zip(a, b))

HOST = "localhost"
PORT = 13388

r = remote(HOST, PORT)

def bytes_to_hexstring(barray):
    return ''.join('{:02x}'.format(x) for x in barray)

def json_recv():
    line = r.readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)
    return






print(r.readline()) # Récéption du premier message envoyé par le serveur

json_send({"option": "sign", "message": bytes_to_hexstring(b"message")})

reponse = json_recv() # Récéption de la signature

signaturerep = reponse["signature"]

pad1=pad(b"message", 16)
print(pad1) 
pad2=pad(pad1 + b"admin=True", 16)
lenpad1 = len(pad1)
lenadm = len(pad2)-lenpad1

for i in range(lenpad1, lenpad1+lenadm, 16):
    blk=pad2[i:i+16]
    signaturerep = bxor(AES.new(blk, AES.MODE_ECB).encrypt(bytes.fromhex(signaturerep)), bytes.fromhex(signaturerep))

json_send({"option": "get_flag", "signature": bytes_to_hexstring(signaturerep), "message": bytes_to_hexstring(pad1 + b"admin=True")})

flag= json_recv()["flag"] 
print("Le flag est : ", flag)


















json_send({"option": "get_flag", "message": bytes_to_hexstring(b"admin=True")})

print(json_recv()) # Récéption de la signature

json