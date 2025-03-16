conf.L3socket = L3RawSocket
req=IP(src='8.8.8.8', dst='127.0.0.1')/UDP(dport=10000)/raw(b"miaou")
send(req)
resp = sr1(req)
resp.show()
