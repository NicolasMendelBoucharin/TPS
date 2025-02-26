import socket 

UDP_IP = "127.0.0.1"
UDP_PORT= 10000
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
reponse = "j'ai recu un truc"
while True:
    data, addr = sock.recvfrom(1024)
    print("received message: %s" %data)
    if data !=b"":
        reponse = b"j'ai recu un truc"
        sock.sendto(reponse, addr)
