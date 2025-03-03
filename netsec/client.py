import socket 

UDP_IP = "127.0.0.1"
UDP_PORT= 10000
IP_RECVERR=11
MESSAGE = b"Hello, World !"
print("UDP target IP: %s"% UDP_IP)
print("UDP target PORT: %s"% UDP_PORT)
print("message: %s" %MESSAGE)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.IPPROTO_IP, IP_RECVERR, 1)
for i in range(50):
    message=f"coucou de la ligne {i}\n"
    sock.sendto(message.encode(), (UDP_IP, UDP_PORT))
#sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
data, _ =sock.recvfrom(1024)
print(data)

