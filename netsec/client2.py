import socket 
TCP_IP = "127.0.0.1"
TCP_PORT = 10000
BUFFER_SIZE=1000000
MESSAGE="Hello, World!\n"
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
for i in range(50):
    message=f"coucou de la ligne {i}\n"
    s.send(message.encode())
    data=s.recv(BUFFER_SIZE)
print("received data:", data.decode())

s.close()


