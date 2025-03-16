
# Q11 :

import dns
import dns.message
import socket
DNS_RESOLVER = ("9.9.9.9", 53)
sock = socket.socket() # XXX Complete Here
req = dns.message.make_query(input(), "A")
print("............................................")
print(req.to_text())
print("............................................")
print("You can compare it to wireshark: ")
print(req.to_wire())
print("............................................")
sock.sendto(req.to_wire(), DNS_RESOLVER)
data, addr = sock.recvfrom(1024)
resp = dns.message.from_wire(data)
print(resp)
sock.close()
print("............................................")


# Q12 :

import dns
import dns.message
import socket
DNS_LOCALRSL = ("127.0.0.1", 53)
print("............................................")
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)
print("dig example.org @127.0.0.1")
data, addr = s.recvfrom(1024)
req = dns.message.from_wire(data)
print (req)
print("............................................")
resp = dns.message.make_response(req)
resp.set_rcode(dns.rcode.SERVFAIL)
print(resp)
s.sendto(resp.to_wire(), addr)
s.close()
print("............................................")

