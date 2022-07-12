import socket
server = socket.socket()
server.connect(("127.0.0.1",1234))

string  = input("Enter a string: ")
server.send(bytes(string,"utf-8"))
buffer = server.recv(1024)
buffer = buffer.decode("utf-8")
print(f"server: {buffer}")