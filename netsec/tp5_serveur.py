
# Q11 :
"""
import dns
import dns.message
import socket
DNS_RESOLVER = ("9.9.9.9", 53)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # XXX Complete Here
req = dns.message.make_query(input("enter domain here"), "A")
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

"""


# Q12 :

"""
import dns
import dns.message
import socket

DNS_LOCALRSL = ("127.0.0.1", 53)
DNS_RESOLVER = ("9.9.9.9", 53)

print("............................................")

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)

print("Please execute the following command:\ndig example.org @127.0.0.1")

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
"""


# Q13

"""
import dns
import dns.message
import socket

DNS_LOCALRSL = ("127.0.0.1", 53)
DNS_RESOLVER = ("9.9.9.9", 53)

print("............................................")

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)
print("Please execute the following command:\ndig example.org @127.0.0.1")
data, addr = s.recvfrom(1024)
req = dns.message.from_wire(data)
print (req)

print("............................................")

s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s2.sendto(data, DNS_RESOLVER)
data2, addr2 = s2.recvfrom(1024)
resp = dns.message.from_wire(data2)
print(resp)

print("............................................")

s.sendto(data2, addr)
s.close()
s2.close()

print("............................................")

"""


# Q15

"""
import dns
import dns.message
import urllib.request

DOH_RESOLVER = "https://qlf-doh.inria.fr/dns-query"
# Build a DNS request
req = dns.message.make_query(input(), "A")
# Nest the DNS request into an HTTP(s) one
req2 = urllib.request.Request(
DOH_RESOLVER, headers={"Accept": "application/dns-json"}, data=req.to_wire()
)
# Send the request via an HTTP POST instead of sending it over UDP
response = urllib.request.urlopen(req2)
# Get and print the response
data2 = response.read()
print(dns.message.from_wire(data2))

"""


# Q16

import dns
import dns.message
import socket
import urllib.request

DNS_LOCALRSL = ("127.0.0.1", 53)
DNS_RESOLVER = ("9.9.9.9", 53)
DOH_RESOLVER = "https://qlf-doh.inria.fr/dns-query"

print("............................................")

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(DNS_LOCALRSL)
print("Please execute the following command:\ndig example.org @127.0.0.1")
data, addr = s.recvfrom(1024)
req = dns.message.from_wire(data)

print (req)

print("............................................")
req2 = urllib.request.Request(
DOH_RESOLVER, headers={"Accept": "application/dns-json"}, data=req.to_wire()
)
print(req2)


print("............................................")

resp = urllib.request.urlopen(req2)
data2 = resp.read()
print(dns.message.from_wire(data2))

print("............................................")

s.sendto(data2, addr)
s.close()

print("............................................")

